/*
Advanced Windows Debugging
- Mario Hewardt, Daniel Pravat
*/

/*
오늘 실습 하다가 알게되어서 공유합니다
dead.exe 실행시 일정 확률로 쓰레드 데드락이 발생해요 
x86_64-w64-mingw32-gcc -o dead.exe deadlock.c
침해사고 고급과정에서 쓰이는 내용은 아닙니다
실습에 도움이 되는 책은 
Learning Malware Analysis - Monnappa K. A.
이거 한글판 보시면 됩니다 여기서 다나와욧!
*/

#include <windows.h>
#include <stdio.h>
#include <conio.h>

CRITICAL_SECTION cs_DB1;
CRITICAL_SECTION cs_DB2;

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	EnterCriticalSection(&cs_DB1); // Race cond.
	printf("Entering DB1\n");
	Sleep(1000);
	EnterCriticalSection(&cs_DB2); // Race cond.
	printf("Entering DB2\n");
	Sleep(1000);
	LeaveCriticalSection(&cs_DB2);
	LeaveCriticalSection(&cs_DB1);
	return 0;
}

void __cdecl main()
{
	HANDLE MultiThread=NULL;
	DWORD dwId=0;
	InitializeCriticalSection(&cs_DB1);
	InitializeCriticalSection(&cs_DB2);
	if(MultiThread=CreateThread(NULL,0,ThreadProc,NULL,0,&dwId))
	{
		Sleep(1000); // Entering...
		EnterCriticalSection(&cs_DB2); // Race cond.
		printf("This is a DB2 Critical Section\n");
		Sleep(1000);
		// Deadlock occur...
		EnterCriticalSection(&cs_DB1); // Race cond.
		printf("This is a DB1 Critical Section\n");
		LeaveCriticalSection(&cs_DB1);
		LeaveCriticalSection(&cs_DB2);
	}
	DeleteCriticalSection(&cs_DB1);
	DeleteCriticalSection(&cs_DB2);
}

