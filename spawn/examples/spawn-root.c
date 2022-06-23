#include <pip/pip.h>
#include <stdlib.h>
int main( int argc, char **argv ) {
  int pipid, ntasks, pipid_task, i;
  ntasks = strtol( argv[1], NULL, 10 );
  pip_init( &pipid, &ntasks, NULL, 0 );
  for( i=0; i<ntasks; i++ ) {
    pipid_task = PIP_PIPID_ANY;
    pip_spawn( argv[2], &argv[2], NULL,
	       PIP_CPUCORE_ASIS, &pipid_task,
	       NULL, NULL, NULL );
    pip_wait( pipid_task, NULL );
    printf( "PiP task (PIPID:%d) done\n",
	    pipid_task );
  }
  pip_fin();
  return 0;
}
