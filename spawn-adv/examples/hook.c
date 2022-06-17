#include <pip/pip.h>
#include <stdlib.h>
#include <unistd.h>
#define FD_TASK		(10)
int before_hook( void *argp ) {
  int *fdp = (int*) argp;
  printf( "PID:%d Before Hook: fd=%d\n", getpid(), *fdp );
  fflush( stdout );
  dup2( 1, *fdp );
  return 0;
}
int after_hook( void *argp ) {
  int *fdp = (int*) argp;
  printf( "PID:%d After Hook:  fd=%d\n", getpid(), *fdp );
  fflush( stdout );
  close( *fdp );
  return 0;
}
int main( int argc, char **argv ) {
  int pipid, ntasks, pipid_task, i;
  int arg = FD_TASK;
  ntasks = strtol( argv[1], NULL, 10 );
  pip_init( &pipid, &ntasks, NULL, 0 );
  if( pipid == PIP_PIPID_ROOT ) {
    pip_spawn_program_t prog;
    pip_spawn_hook_t    hooks;
    pip_spawn_from_main( &prog, argv[0], argv,
			 NULL, NULL );
    pip_spawn_hook( &hooks,
		    before_hook,
		    after_hook,
		    &arg );
    printf( "PID:%d MAIN\n", getpid() );
    fflush( stdout );
    for( i=0; i<ntasks; i++ ) {
      pipid_task = i;
      pip_task_spawn( &prog, PIP_CPUCORE_ASIS,
		      0, &pipid_task, &hooks );
      pip_wait( pipid_task, NULL );
    }
  } else {
    char msg[64];
    sprintf( msg, "Hello from PIPID:%d\n", pipid );
    int len = strlen( msg );
    write( FD_TASK, msg, len );
  }
  pip_fin();
  return 0;
}
