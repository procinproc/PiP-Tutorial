#include <pip/pip.h>
#include <stdlib.h>
int user_func( void *arg ) {
  char *msg = (char*) arg;
  int pipid, ntasks;
  pip_get_pipid( &pipid );
  pip_get_ntasks( &ntasks );
  printf( "USER-FUNC: \"%s\" from PIPID:%d/%d\n",
	  msg, pipid, ntasks );
  return 0;
}

int main( int argc, char **argv ) {
  int pipid, ntasks, pipid_task, i;
  ntasks = strtol( argv[1], NULL, 10 );
  pip_init( &pipid, &ntasks, NULL, 0 );
  if( pipid == PIP_PIPID_ROOT ) {
    pip_spawn_program_t prog;
    pip_spawn_from_func( &prog,
			 argv[0],     /* exec file */
			 "user_func", /* func name */
			 (void*) argv[2], /* arg   */
			 NULL,	      /* environ   */
			 NULL );/* explained later */
    for( i=0; i<ntasks; i++ ) {
      pipid_task = i;
      pip_task_spawn( &prog, PIP_CPUCORE_ASIS, 0,
		      &pipid_task, NULL );
      pip_wait( pipid_task, NULL );
    }
  } else {
    /* NEVER REACH HERE */
    printf( "MAIN: \"%s\" from PIPID:%d/%d\n",
	    argv[2], pipid, ntasks );
  }
  pip_fin();
  return 0;
}
