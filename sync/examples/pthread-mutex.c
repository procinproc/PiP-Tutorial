#include <pip/pip.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define NITERS		(1000)
typedef struct sync_tasks {
  pthread_barrier_t	barr;
  pthread_mutex_t	mutex;
  int			count;
} sync_t;
sync_t	sync_tasks;
int lock;
void increment( sync_t *syncp ) {
  int tmp;
  if( lock ) pthread_mutex_lock( &syncp->mutex );
  tmp = syncp->count;
  usleep( 10 );
  syncp->count = tmp + 1;
  if( lock ) pthread_mutex_unlock( &syncp->mutex );
}
int main( int argc, char **argv ) {
  int pipid, ntasks, i;
  sync_t *syncp;
  pip_get_pipid( &pipid );
  pip_get_ntasks( &ntasks );
  lock = ( argc == 1 );
  if( pipid == 0 ) {
    syncp = &sync_tasks;
    pthread_barrier_init( &syncp->barr, NULL, ntasks );
    pthread_mutex_init( &syncp->mutex, NULL );
    syncp->count = 0;
    pip_named_export( syncp, "sync" );
  } else {
    pip_named_import( 0, (void**) &syncp, "sync" );
  }
  pthread_barrier_wait( &syncp->barr );
  for( i=0; i<NITERS; i++ ) increment( syncp );
  pthread_barrier_wait( &syncp->barr );
  if( pipid == 0 ) {
    printf( "count=%d (%d*%d)\n", syncp->count,
	    ntasks, NITERS );
  }
  return 0;
}
