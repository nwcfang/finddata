// finddata.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "searchfiles.h"
#include <conio.h>
#include <vector>

struct SFileData
{
	WORD wDay;
	WORD wMonth;
	WORD wYear;
};

SFileData sFD;
//SYSTEMTIME todayData;

void DoSomething(FILE *log, wchar_t file[], WIN32_FIND_DATA *wfd)
{
	SYSTEMTIME pSysTime;
	FileTimeToSystemTime( &(wfd->ftCreationTime), &pSysTime );

	if( pSysTime.wYear > sFD.wYear)
	{
		fwprintf( log, L"%s\t%i.%i.%i\t%i:%i\n", file, pSysTime.wDay, pSysTime.wMonth, pSysTime.wYear,
			pSysTime.wHour, pSysTime.wMinute);
	}
	else if( pSysTime.wYear == sFD.wYear)
	{
		if( pSysTime.wMonth > sFD.wMonth )
		{
			fwprintf( log, L"%s\t%i.%i.%i\t%i:%i\n", file, pSysTime.wDay, pSysTime.wMonth, pSysTime.wYear,
				pSysTime.wHour, pSysTime.wMinute);
		}
		else if( pSysTime.wMonth == sFD.wMonth )
		{
			if( pSysTime.wDay >= sFD.wDay )
				fwprintf( log, L"%s\t%i.%i.%i\t%i:%i\n", file, pSysTime.wDay, pSysTime.wMonth, pSysTime.wYear,
					pSysTime.wHour, pSysTime.wMinute);
		}
	}
	//if(  pSysTime.wDay >= sFD.wDay && pSysTime.wMonth >= sFD.wMonth && pSysTime.wYear >= sFD.wYear )
	//fwprintf( log, L"%s\t%i.%i.%i\t%i:%i\n", file, pSysTime.wDay, pSysTime.wMonth, pSysTime.wYear,
		//pSysTime.wHour, pSysTime.wMinute);
}



int main()
{
    //if (!SetConsoleOutputCP(1251))
    //{
    //    // попытка установить нужную страницу закончилась неудачно
    //    // выводим причину ошибки
    //    char msg[300];
    //    FormatMessageA(FORMAT_MESSAGE_IGNORE_INSERTS 
    //        | FORMAT_MESSAGE_FROM_SYSTEM, 0, GetLastError(),  
    //        0, msg, sizeof(msg) - 1, 0);
    //    // если версия Windows локализованная то ошибка будет
    //    // на русском языке, поэтому 
    //    CharToOemA(msg, msg);
    //    printf("SetConsoleOutputCP Error: %s\n", msg);
    //    return 1;
    //}
	char strData[21] = {0};

	setlocale(LC_ALL,"Russian");
	cout << "ПОИСК ФАЙЛОВ ПО ДАТЕ" << endl << "Выполнил: Гусев М.С 03-527" << endl;
	
	while ( 1 )
	{
		cout << "Введите дату (ДД.ММ.ГГГГ) ";
		cin >> strData;
		if( strlen( strData ) == 10 )
			break;
		ZeroMemory( strData, sizeof(char) * 21 );
		cout << "Неправильный формат даты." << endl;
	}

	char tmp[4] = {0};
	strncpy( tmp, strData, 2 );
	sFD.wDay = atoi( tmp );
	ZeroMemory( tmp, sizeof(char) * 4 );
	strncpy( tmp, &strData[3], 2 );
	sFD.wMonth = atoi( tmp );
	ZeroMemory( tmp, sizeof(char) * 4 );
	strncpy( tmp, &(strData[6]), 4 );
	sFD.wYear = atoi( tmp );

	//GetLocalTime( &todayData );


	FILE *log;
	log = fopen( "out.txt", "w" );
	if( log == NULL )
	{
		cout << "Произошла ошибка при открытии выходного файла";
		return FALSE;
	}
	
	cout << "Пример:"<< endl << "Для поиска в корневой директории  - C:\\*"<< endl;
	cout << "Символ * обозначает любую последовательность символом в имени файла" << endl;
	//cout << "Для поиска в папке - С:\\papka\\*"<< endl;
	cout << "Введите маску для поиска файла : ";
	wchar_t wstr[260];
	fflush( stdin );
	wscanf(L"%s", wstr );
	cout << "Идет поиск ..." << endl;
	SearchFiles( log, wstr, (LPSEARCHFUNC)DoSomething, true);
	cout << "Поиск завершен." << endl << "После нажатия любой клавиши результат поместится в файл .\\out.txt";
	getch();
	fclose( log );
	return 0;
}

