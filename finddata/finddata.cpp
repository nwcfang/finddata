// finddata.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "searchfiles.h"
#include <conio.h>

struct SFileData
{
	WORD wDay;
	WORD wMonth;
	WORD wYear;
};

SFileData sFD;

void DoSomething(FILE *log, wchar_t file[], WIN32_FIND_DATA *wfd)
{
	SYSTEMTIME pSysTime;
	FileTimeToSystemTime( &(wfd->ftCreationTime), &pSysTime );  
	if(  pSysTime.wDay == sFD.wDay && pSysTime.wMonth == sFD.wMonth && pSysTime.wYear == sFD.wYear )
	fwprintf( log, L"%s\t%i.%i.%i\t%i:%i\n", file, pSysTime.wDay, pSysTime.wMonth, pSysTime.wYear,
		pSysTime.wHour, pSysTime.wMinute);
}



int main()
{
    //if (!SetConsoleOutputCP(1251))
    //{
    //    // ������� ���������� ������ �������� ����������� ��������
    //    // ������� ������� ������
    //    char msg[300];
    //    FormatMessageA(FORMAT_MESSAGE_IGNORE_INSERTS 
    //        | FORMAT_MESSAGE_FROM_SYSTEM, 0, GetLastError(),  
    //        0, msg, sizeof(msg) - 1, 0);
    //    // ���� ������ Windows �������������� �� ������ �����
    //    // �� ������� �����, ������� 
    //    CharToOemA(msg, msg);
    //    printf("SetConsoleOutputCP Error: %s\n", msg);
    //    return 1;
    //}

	setlocale(LC_ALL,"Russian");
	cout << "����� ������ �� ����" << endl << "��������: ����� �.� 03-527" << endl;
	cout << "������� ����� ";
	cin >> sFD.wDay;
	cout << "������� ����� ";
	cin >> sFD.wMonth;
	cout << "������� ��� ";
	cin >> sFD.wYear;

	FILE *log;
	log = fopen( "out.txt", "w" );
	if( log == NULL )
	{
		cout << "��������� ������ ��� �������� ��������� �����";
		return FALSE;
	}
	
	cout << "������:"<< endl << "��� ������ � �������� ����������  - C:\\\\*"<< endl;
	cout << "��� ������ � ����� - �:\\\\papka\\\\*"<< endl;
	cout << "������� ����� ��� ������ ����� : ";
	wchar_t wstr[260];
	fflush( stdin );
	wscanf(L"%s", wstr );
	//for( int i = 0; i < 260;
	cout << "���� ����� ..." << endl;
	SearchFiles( log, wstr, (LPSEARCHFUNC)DoSomething, true);
	cout << "����� ��������." << endl << "����� ������� ����� ������� ��������� ���������� � ���� .\\out.txt";
	getch();
	fclose( log );
	return 0;
}

