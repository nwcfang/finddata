// finddata.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "searchfiles.h"

//typedef void (*LPSEARCHFUNC)(LPCSTR lpszFileName);

void DoSomething(LPCTSTR lpszFileName)
{
    MessageBox(NULL, lpszFileName, L"Find File", MB_OK | MB_APPLMODAL);
}

int _wmain()
{
    if (!SetConsoleOutputCP(1251))
    {
        // ������� ���������� ������ �������� ����������� ��������
        // ������� ������� ������
        char msg[300];
        FormatMessageA(FORMAT_MESSAGE_IGNORE_INSERTS 
            | FORMAT_MESSAGE_FROM_SYSTEM, 0, GetLastError(),  
            0, msg, sizeof(msg) - 1, 0);
        // ���� ������ Windows �������������� �� ������ �����
        // �� ������� �����, ������� 
        CharToOemA(msg, msg);
        printf("SetConsoleOutputCP Error: %s\n", msg);
        return 1;
    }

    // ������ ���� ����� ������ � ������������� ������� ��������

    printf("������ ����!\n");
    printf("� ��� ��� ������ ����!\n");
	SearchFiles( L"D:\\books\\name.*", (LPSEARCHFUNC)DoSomething, FALSE);
	//GetFileTime(
	return 0;
}

