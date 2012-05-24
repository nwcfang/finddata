#pragma once
#include "stdafx.h"
typedef void (*LPSEARCHFUNC)(LPCWSTR lpszFileName);

BOOL SearchFiles(
        LPCWSTR lpszFileName,                // Директория и маска файлов для поиска
        LPSEARCHFUNC lpSearchFunc,            // Функция, вызываемая для всех найденных файлов.
        BOOL bInnerFolders /* = TRUE */);    // TRUE - поиск в подпапках. 
                                            // FALSE - поиск только в заданной папке