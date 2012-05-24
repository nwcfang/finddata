#include "stdafx.h"


typedef void (*LPSEARCHFUNC)(FILE *log , wchar_t file[], WIN32_FIND_DATA *wfd);

BOOL SearchFiles( FILE *log, LPCWSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = TRUE)
{

    LPWSTR part;
	wchar_t tmp[MAX_PATH]; // ��������� ������
    wchar_t name[MAX_PATH];
	SYSTEMTIME pSysTime;

	HANDLE hSearch = NULL;
	WIN32_FIND_DATA wfd;
	memset(&wfd, 0, sizeof(WIN32_FIND_DATA));



    // ������� ����� ������ ��������� ������ ...
    if(bInnerFolders)
    {
        if(GetFullPathNameW(lpszFileName, MAX_PATH, tmp, &part) == 0) return FALSE;
        wcscpy(name, part);
        wcscpy(part, L"*.*");

        // ���� ����� ����������, �� ������ �����
        wfd.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
        if (!((hSearch = FindFirstFile(tmp, &wfd)) == INVALID_HANDLE_VALUE))
        do
        {
            // � ������ ����� ���� ��� ����� � ������� "." � ".."
            // � ��� ����� �� �� �������

            // ���������� ����� "." � ".."
            if (!wcsncmp(wfd.cFileName, L".", 1) || !wcsncmp(wfd.cFileName, L"..", 2))            
           continue;
       
            if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) // ���� �� ����� �����
            {
                wchar_t next[MAX_PATH];
                if(GetFullPathNameW(lpszFileName, MAX_PATH, next, &part) == 0) return FALSE;
				
                wcscpy(part, wfd.cFileName);
                wcscat(next, L"\\");
                wcscat(next, name);

                SearchFiles( log, next, lpSearchFunc, TRUE);
            }
        }
        while (FindNextFile(hSearch, &wfd)); // ���� ��������� ����

        FindClose (hSearch); // ����������� �����
    }

   if ((hSearch = FindFirstFile(lpszFileName, &wfd)) == INVALID_HANDLE_VALUE) 
       return TRUE; // � ��������� ������ �������
   do
   if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) // ���� �� ����� ����
   {
        wchar_t file[MAX_PATH];
        if(GetFullPathNameW(lpszFileName, MAX_PATH, file, &part) == 0) return FALSE;
        wcscpy(part, wfd.cFileName);

		lpSearchFunc( log,  file, &wfd);
   }
   while (FindNextFile(hSearch, &wfd)); // ���� ��������� ����
   FindClose (hSearch); // ����������� �����

    return TRUE;
}