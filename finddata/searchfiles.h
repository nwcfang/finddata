#pragma once
#include "stdafx.h"
typedef void (*LPSEARCHFUNC)(LPCWSTR lpszFileName);

BOOL SearchFiles(
        LPCWSTR lpszFileName,                // ���������� � ����� ������ ��� ������
        LPSEARCHFUNC lpSearchFunc,            // �������, ���������� ��� ���� ��������� ������.
        BOOL bInnerFolders /* = TRUE */);    // TRUE - ����� � ���������. 
                                            // FALSE - ����� ������ � �������� �����