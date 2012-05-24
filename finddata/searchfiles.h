#pragma once
#include "stdafx.h"
typedef void (*LPSEARCHFUNC)(FILE* log, wchar_t file[], WIN32_FIND_DATA *wfd);

BOOL SearchFiles( FILE *log,
        LPCWSTR lpszFileName,                // Директория и маска файлов для поиска
        LPSEARCHFUNC lpSearchFunc,            // Функция, вызываемая для всех найденных файлов.
        BOOL bInnerFolders /* = TRUE */);    // TRUE - поиск в подпапках. 
                                            // FALSE - поиск только в заданной папке