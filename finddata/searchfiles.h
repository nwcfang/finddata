#pragma once
#include "stdafx.h"
typedef void (*LPSEARCHFUNC)(LPCSTR lpszFileName);

BOOL SearchFiles(
        LPCTSTR lpszFileName,                // Директория и маска файлов для поиска
        LPSEARCHFUNC lpSearchFunc,            // Функция, вызываемая для всех найденных файлов.
        BOOL bInnerFolders /* = TRUE */);    // TRUE - поиск в подпапках. 
                                            // FALSE - поиск только в заданной папке