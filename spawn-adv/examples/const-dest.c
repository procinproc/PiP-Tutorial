#include <pip/pip.h>
#include <unistd.h>

char *pipidstr( void ) {
  static char idstr[64];
  int pipid;
  if( pip_get_pipid( &pipid ) != 0 ) {
    sprintf( idstr, "ROOT" );
  } else {
    sprintf( idstr, "Task[%d]", pipid );
  }
  return idstr;
}

void const_func( void ) __attribute__ ((constructor));
void const_func( void ) {
  printf( "[PIPID:%s] constructor is called (PID:%d)\n", 
	  pipidstr(), getpid() );
}

void dest_func( void ) __attribute__ ((destructor));
void dest_func( void ) {
  printf( "[PIPID:%s] destructor is called (PID:%d)\n", 
	  pipidstr(), getpid() );
}

int main( int argc, char **argv ) {
  printf( "[PIPID:%s] PiP task main (PID:%d)\n", 
	  pipidstr(), getpid() );
  return 0;
}
