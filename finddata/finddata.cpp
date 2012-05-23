// finddata.cpp: определ€ет точку входа дл€ консольного приложени€.
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
	SearchFiles( L"D:\\books\\name.*", (LPSEARCHFUNC)DoSomething, FALSE);
	//GetFileTime(
	return 0;
}

