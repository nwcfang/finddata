// finddata.cpp: определяет точку входа для консольного приложения.
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

	setlocale(LC_ALL,"Russian");
	cout << "ПОИСК ФАЙЛОВ ПО ДАТЕ" << endl << "Выполнил: Гусев М.С 03-527" << endl;
	cout << "Введите число ";
	cin >> sFD.wDay;
	cout << "Введите месяц ";
	cin >> sFD.wMonth;
	cout << "Введите год ";
	cin >> sFD.wYear;

	FILE *log;
	log = fopen( "out.txt", "w" );
	if( log == NULL )
	{
		cout << "Произошла ошибка при открытии выходного файла";
		return FALSE;
	}
	
	cout << "Пример:"<< endl << "Для поиска в корневой директории  - C:\\\\*"<< endl;
	cout << "Для поиска в папке - С:\\\\papka\\\\*"<< endl;
	cout << "Введите маску для поиска файла : ";
	wchar_t wstr[260];
	fflush( stdin );
	wscanf(L"%s", wstr );
	//for( int i = 0; i < 260;
	cout << "Идет поиск ..." << endl;
	SearchFiles( log, wstr, (LPSEARCHFUNC)DoSomething, true);
	cout << "Поиск завершен." << endl << "После нажатия любой клавиши результат поместится в файл .\\out.txt";
	getch();
	fclose( log );
	return 0;
}

