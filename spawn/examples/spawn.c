#include <pip/pip.h>
#define NT	(4)
int main( int argc, char **argv ) {
  int pipid, pipid_task, ntasks, i;
  ntasks = NT;
  pip_init( &pipid, &ntasks, NULL, 0 );
  if( pipid == PIP_PIPID_ROOT ) {
    /* PiP root */
    for( i=0; i<NT; i++ ) {
      pipid_task = i;
      pip_spawn( argv[0], argv, NULL, PIP_CPUCORE_ASIS,
		 &pipid_task, NULL, NULL, NULL );
      pip_wait( pipid_task, NULL );
      printf( "PiP task (PIPID:%d) done\n", pipid_task );
    }
  } else {
    /* PiP task */
    printf( "Hello from PIPID:%d\n", pipid );
  }
  pip_fin();
  return 0;
}
