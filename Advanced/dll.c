/*
Advanced Penetration Testing
Hacking the World’s Most Secure Networks
- Wil Allsopp
*/

#include <windows.h>
#include <stdio.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  printf("This string will be written to the console when this DLL is imported\n");
  break;
}

/*
This is a very simple DLLMain function that will be executed as soon as the DLL
has been imported. The code will be executed as SYSTEM. This means that if you
call a Shell() command to execute external executables, then they too will
inherit SYSTEM level privileges.
*/
