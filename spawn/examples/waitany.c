#include <pip/pip.h>
#include <stdlib.h>
int main( int argc, char **argv ) {
  int pipid, ntasks, pipid_task, i, exitval = 0;
  ntasks = strtol( argv[1], NULL, 10 );
  pip_init( &pipid, &ntasks, NULL, 0 );
  if( pipid == PIP_PIPID_ROOT ) {
    int status;
    for( i=0; i<ntasks; i++ ) {
      pipid_task = i;
      pip_spawn( argv[0], argv, NULL,
		 PIP_CPUCORE_ASIS, &pipid_task,
		 NULL, NULL, NULL );
    }
    for( i=0; i<ntasks; i++ ) {
      pip_wait_any( &pipid_task, &status );
      printf( "PiP task (PIPID:%d) done: %d\n",
	      pipid_task, WEXITSTATUS(status) );
    }
  } else {
    exitval = pipid;
  }
  pip_fin();
  return exitval;
}
