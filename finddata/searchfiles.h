#pragma once
#include "stdafx.h"
typedef void (*LPSEARCHFUNC)(FILE* log, wchar_t file[], WIN32_FIND_DATA *wfd);

BOOL SearchFiles( FILE *log,
        LPCWSTR lpszFileName,                // ���������� � ����� ������ ��� ������
        LPSEARCHFUNC lpSearchFunc,            // �������, ���������� ��� ���� ��������� ������.
        BOOL bInnerFolders /* = TRUE */);    // TRUE - ����� � ���������. 
                                            // FALSE - ����� ������ � �������� �����