// finddata.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "searchfiles.h"
#include <conio.h>
//typedef void (*LPSEARCHFUNC)(LPCSTR lpszFileName);

void DoSomething(LPCWSTR lpszFileName)
{
    printf( "��� ����������" );
}

int main()
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
	getch();
	SearchFiles( L"D:\\books\\*", (LPSEARCHFUNC)DoSomething, FALSE);
	//GetFileTime(
	return 0;
}

