#pragma once
#include "stdafx.h"
typedef void (*LPSEARCHFUNC)(LPCSTR lpszFileName);

BOOL SearchFiles(
        LPCTSTR lpszFileName,                // ���������� � ����� ������ ��� ������
        LPSEARCHFUNC lpSearchFunc,            // �������, ���������� ��� ���� ��������� ������.
        BOOL bInnerFolders /* = TRUE */);    // TRUE - ����� � ���������. 
                                            // FALSE - ����� ������ � �������� �����