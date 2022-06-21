#include <pip/pip.h>
#include <stdlib.h>
#include <pthread.h>
pthread_barrier_t barr;
int main( int argc, char **argv ) {
  int pipid, ntasks, pipid_task, i;
  pthread_barrier_t *barrp = &barr;
  ntasks = strtol( argv[1], NULL, 10 );
  pip_init( &pipid, &ntasks, (void**) &barrp, 0 );
  if( pipid == PIP_PIPID_ROOT ) {
    pthread_barrier_init( barrp, NULL, ntasks );
    for( i=0; i<ntasks; i++ ) {
      pipid_task = i;
      pip_spawn( argv[0], argv, NULL, 
		 PIP_CPUCORE_ASIS, &pipid_task,
		 NULL, NULL, NULL );
    }
    for( i=0; i<ntasks; i++ ) {
      pip_wait_any( &pipid_task, NULL );
      printf( "PiP task (PIPID:%d) done\n", pipid_task );
    }
    pthread_barrier_destroy( barrp );
  } else {
    if( argv[2] == NULL ) {
      pthread_barrier_wait( barrp );
    }
    printf( "PIPID:%d %f [S]\n", pipid, pip_gettime() );
  }
  return 0;
}
