#include <pip/pip.h>
#include <stdlib.h>
int main( int argc, char **argv ) {
  int pipid, ntasks, pipid_task, i;
  ntasks = strtol( argv[1], NULL, 10 );
  pip_init( &pipid, &ntasks, NULL, 0 );
  if( pipid == PIP_PIPID_ROOT ) {
    pip_spawn_program_t prog;
    pip_spawn_from_main( &prog,
			 argv[0],     /* exec file */
			 argv,	      /* argv      */
			 NULL,	      /* environ   */
			 NULL );/* explained later */
    for( i=0; i<ntasks; i++ ) {
      pipid_task = i;
      pip_task_spawn( &prog, PIP_CPUCORE_ASIS, 0,
		      &pipid_task, NULL );
      pip_wait( pipid_task, NULL );
    }
  } else {
    printf( "MAIN: \"%s\" from PIPID:%d/%d\n",
	    argv[2], pipid, ntasks );
  }
  pip_fin();
  return 0;
}
