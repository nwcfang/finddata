#include "stdafx.h"

//typedef void (*LPSEARCHFUNC)(LPCSTR lpszFileName);
//
////BOOL SearchFiles(LPCTSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = TRUE)
//BOOL SearchFiles(LPCSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = TRUE)
//{
//    //LPTSTR part;
//	LPSTR part;
//	//char *part;
//	char tmp[MAX_PATH]; // ��������� ������
//	//LPWSTR tmp; // ��������� ������
//    char name[MAX_PATH];
//
//   HANDLE hSearch = NULL;
//   LPWIN32_FIND_DATAA wfd;
//    memset(&wfd, 0, sizeof(WIN32_FIND_DATAA));
//
//    // ������� ����� ������ ��������� ������ ...
//    if(bInnerFolders)
//    {
//		if(GetFullPathNameA(lpszFileName, MAX_PATH, tmp, &part) == 0) return FALSE;
//		strcpy( name, part);
//        strcpy(part, "*.*");
//
//        // ���� ����� ����������, �� ������ �����
//        wfd->dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
//        if (!((hSearch = FindFirstFileA(tmp, wfd)) == INVALID_HANDLE_VALUE))
//        do
//        {
//            // � ������ ����� ���� ��� ����� � ������� "." � ".."
//            // � ��� ����� �� �� �������
//
//            // ���������� ����� "." � ".."
//            if (!strncmp(wfd->cFileName, ".", 1) || !strncmp(wfd->cFileName, "..", 2))            
//           continue;
//       
//            if (wfd->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) // ���� �� ����� �����
//            {
//                char next[MAX_PATH];
//				if(GetFullPathNameA(lpszFileName, MAX_PATH, next, &part) == 0) return FALSE;
//                strcpy(part, wfd->cFileName);
//                strcat(next, "\\");
//                strcat(next, name);
//
//                SearchFiles(next, lpSearchFunc, TRUE);
//            }
//        }
//		while (FindNextFileA(hSearch, wfd)); // ���� ��������� ����
//
//        FindClose (hSearch); // ����������� �����
//    }
//
//	if ((hSearch = FindFirstFileA(lpszFileName, wfd)) == INVALID_HANDLE_VALUE) 
//       return TRUE; // � ��������� ������ �������
//   do
//   if (!(wfd->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) // ���� �� ����� ����
//   {
//        char file[MAX_PATH];
//		if(GetFullPathNameA(lpszFileName, MAX_PATH, file, &part) == 0) return FALSE;
//        strcpy(part, wfd->cFileName);
//
//        lpSearchFunc(file);
//   }
//   while (FindNextFileA(hSearch, wfd)); // ���� ��������� ����
//   FindClose (hSearch); // ����������� �����
//
//    return TRUE;
//}


//typedef void (*LPSEARCHFUNC)(LPCTSTR lpszFileName);
//
//BOOL SearchFiles(LPCTSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = TRUE)

//typedef void (*LPSEARCHFUNC)(LPCWSTR lpszFileName);
//
//BOOL SearchFiles(LPCTSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = TRUE)
//{
//    LPWSTR part;
//   //char tmp[MAX_PATH]; // ��������� ������
//	LPWSTR tmp;
//    wchar_t name[MAX_PATH];
//
//   HANDLE hSearch = NULL;
//   WIN32_FIND_DATA wfd;
//    memset(&wfd, 0, sizeof(WIN32_FIND_DATA));
//
//    // ������� ����� ������ ��������� ������ ...
//    if(bInnerFolders)
//    {
//        if(GetFullPathNameW(lpszFileName, MAX_PATH, tmp, &part) == 0) return FALSE;
//		wcscpy(name, part);
//		wcscpy(part, L"*.*");
//        //strcpy(name, (char *)part);
//        //strcpy((char *)part, "*.*");
//
//        // ���� ����� ����������, �� ������ �����
//        wfd.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
//        if (!((hSearch = FindFirstFile(tmp, &wfd)) == INVALID_HANDLE_VALUE))
//        do
//        {
//            // � ������ ����� ���� ��� ����� � ������� "." � ".."
//            // � ��� ����� �� �� �������
//
//            // ���������� ����� "." � ".."
//			LPSTR filename;
//			//CharToOemW(wfd.cFileName, filename );
//			
//            if (!strncmp(filename, ".", 1) || !strncmp(filename, "..", 2))            
//           continue;
//       
//            if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) // ���� �� ����� �����
//            {
//                //char next[MAX_PATH];
//				wchar_t next[MAX_PATH];		
//                if(GetFullPathName(lpszFileName, MAX_PATH, next, &part) == 0) return FALSE;
//                //strcpy(part, wfd.cFileName);
//				wcscpy(part, wfd.cFileName);
//				wcscat( part, L"\\" );
//				wcscat( part, name );
//                //strcat(next, "\\");
//                //strcat(next, name);
//
//                SearchFiles(next, lpSearchFunc, TRUE);
//            }
//        }
//        while (FindNextFile(hSearch, &wfd)); // ���� ��������� ����
//
//        FindClose (hSearch); // ����������� �����
//    }
//
//   if ((hSearch = FindFirstFile(lpszFileName, &wfd)) == INVALID_HANDLE_VALUE) 
//       return TRUE; // � ��������� ������ �������
//   do
//   if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) // ���� �� ����� ����
//   {
//        wchar_t file[MAX_PATH];
//        if(GetFullPathName(lpszFileName, MAX_PATH, file, &part) == 0) return FALSE;
//		wcscpy(part, wfd.cFileName);
//        //strcpy(part, wfd.cFileName);
//
//        lpSearchFunc(file);
//   }
//   while (FindNextFile(hSearch, &wfd)); // ���� ��������� ����
//   FindClose (hSearch); // ����������� �����
//
//    return TRUE;
//}


typedef void (*LPSEARCHFUNC)(LPCWSTR lpszFileName);

//BOOL SearchFiles(LPCWSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = TRUE)
BOOL SearchFiles(LPCWSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = TRUE)
{
    LPWSTR part;
   wchar_t tmp[MAX_PATH]; // ��������� ������
    wchar_t name[MAX_PATH];

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

                SearchFiles(next, lpSearchFunc, TRUE);
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

        lpSearchFunc(file);
   }
   while (FindNextFile(hSearch, &wfd)); // ���� ��������� ����
   FindClose (hSearch); // ����������� �����

    return TRUE;
}