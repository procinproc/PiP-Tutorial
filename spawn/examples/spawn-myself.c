#include <pip/pip.h>
#include <stdlib.h>
int main( int argc, char **argv ) {
  int pipid, ntasks, pipid_task, i;
  ntasks = strtol( argv[1], NULL, 10 );
  pip_init( &pipid, &ntasks, NULL, 0 );
  if( pipid == PIP_PIPID_ROOT ) {
    /* PiP root */
    for( i=0; i<ntasks; i++ ) {
      pipid_task = i;
      pip_spawn( argv[0], argv, NULL,
		 PIP_CPUCORE_ASIS, &pipid_task,
		 NULL, NULL, NULL );
      pip_wait( pipid_task, NULL );
      printf( "PiP task (PIPID:%d) done\n",
	      pipid_task );
    }
  } else {
    /* PiP task */
    printf( "\"%s\" from PIPID:%d/%d\n",
	    argv[2], pipid, ntasks );
  }
  pip_fin();
  return 0;
}
