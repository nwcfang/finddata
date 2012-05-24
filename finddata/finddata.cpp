// finddata.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "searchfiles.h"
#include <conio.h>
//typedef void (*LPSEARCHFUNC)(LPCSTR lpszFileName);

void DoSomething(LPCWSTR lpszFileName)
{
    printf( "все получилось" );
}

int main()
{
    if (!SetConsoleOutputCP(1251))
    {
        // попытка установить нужную страницу закончилась неудачно
        // выводим причину ошибки
        char msg[300];
        FormatMessageA(FORMAT_MESSAGE_IGNORE_INSERTS 
            | FORMAT_MESSAGE_FROM_SYSTEM, 0, GetLastError(),  
            0, msg, sizeof(msg) - 1, 0);
        // если верси€ Windows локализованна€ то ошибка будет
        // на русском €зыке, поэтому 
        CharToOemA(msg, msg);
        printf("SetConsoleOutputCP Error: %s\n", msg);
        return 1;
    }

    // дальше весь вывод пойдет в установленной кодовой странице

    printf("ѕривет всем!\n");
    printf("» еще раз привет всем!\n");
	getch();
	SearchFiles( L"D:\\books\\*", (LPSEARCHFUNC)DoSomething, FALSE);
	//GetFileTime(
	return 0;
}

