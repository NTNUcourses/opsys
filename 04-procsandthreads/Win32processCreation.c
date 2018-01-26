#include <stdio.h>
#include "C:\\Program Files\\MinGW\\include\\windows.h"

int main(VOID)
{

  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  // allocate memory
  ZeroMemory( &si, sizeof(si) );
  si.cb = sizeof( si );
  ZeroMemory( &pi, sizeof(pi ) );

  // create child process
  if ( !CreateProcess( NULL, // use command line
    "C:\\WINDOWS\\system32\\mspaint.exe", // command line
    NULL, // don't inherit process handle
    NULL, // don't inherit thread handle
    FALSE, //disable handle inheritance
    0, // no creation flags
    NULL,  // use parent's environment block
    NULL,  // use parent's existing directory
    &si,
    &pi ) )
  {
    fprintf( stderr, "create process failded" ) ;
    return -1;
  }

  // parent waits for child to complete
  WaitForSingleObject( pi.hProcess, INFINITE );
  printf( "child complete\n" );

  // close handles
  CloseHandle( pi.hProcess );
  CloseHandle( pi.hThread );

}
