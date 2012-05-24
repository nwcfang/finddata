#include "stdafx.h"


typedef void (*LPSEARCHFUNC)(FILE *log , wchar_t file[], WIN32_FIND_DATA *wfd);

BOOL SearchFiles( FILE *log, LPCWSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = TRUE)
{

    LPWSTR part;
	wchar_t tmp[MAX_PATH]; // временный массив
    wchar_t name[MAX_PATH];
	SYSTEMTIME pSysTime;

	HANDLE hSearch = NULL;
	WIN32_FIND_DATA wfd;
	memset(&wfd, 0, sizeof(WIN32_FIND_DATA));



    // сначало поиск внутри вложенных папках ...
    if(bInnerFolders)
    {
        if(GetFullPathNameW(lpszFileName, MAX_PATH, tmp, &part) == 0) return FALSE;
        wcscpy(name, part);
        wcscpy(part, L"*.*");

        // если папки существуют, то делаем поиск
        wfd.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
        if (!((hSearch = FindFirstFile(tmp, &wfd)) == INVALID_HANDLE_VALUE))
        do
        {
            // в каждой папке есть две папки с именами "." и ".."
            // и эти папки мы не трогаем

            // пропускаем папки "." и ".."
            if (!wcsncmp(wfd.cFileName, L".", 1) || !wcsncmp(wfd.cFileName, L"..", 2))            
           continue;
       
            if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) // если мы нашли папку
            {
                wchar_t next[MAX_PATH];
                if(GetFullPathNameW(lpszFileName, MAX_PATH, next, &part) == 0) return FALSE;
				
                wcscpy(part, wfd.cFileName);
                wcscat(next, L"\\");
                wcscat(next, name);

                SearchFiles( log, next, lpSearchFunc, TRUE);
            }
        }
        while (FindNextFile(hSearch, &wfd)); // ищем следующий файл

        FindClose (hSearch); // заканчиваем поиск
    }

   if ((hSearch = FindFirstFile(lpszFileName, &wfd)) == INVALID_HANDLE_VALUE) 
       return TRUE; // в противном случае выходим
   do
   if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) // если мы нашли файл
   {
        wchar_t file[MAX_PATH];
        if(GetFullPathNameW(lpszFileName, MAX_PATH, file, &part) == 0) return FALSE;
        wcscpy(part, wfd.cFileName);

		lpSearchFunc( log,  file, &wfd);
   }
   while (FindNextFile(hSearch, &wfd)); // ищем следующий файл
   FindClose (hSearch); // заканчиваем поиск

    return TRUE;
}