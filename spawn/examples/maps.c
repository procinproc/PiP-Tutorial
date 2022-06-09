#include <pip/pip.h>
#include <unistd.h>
#include <stdlib.h>

pip_barrier_t barr;

int main() {
  int pipid, ntasks;
  pip_barrier_t *barrp;
  
  pip_get_pipid( &pipid );
  pip_get_ntasks( &ntasks );

  if( pipid == 0 ) {
    barrp = &barr;
    pip_barrier_init( barrp, ntasks );
    pip_named_export( barrp, "barr" );
  } else {
    pip_named_import( 0, (void**) &barrp, "barr" );
  }
  pip_barrier_wait( barrp );
  if( pipid == 0 ) {
    char sys[128];
    sprintf( sys, "cat /proc/%d/maps", getpid() );
    system( sys );
  }
  pip_barrier_wait( barrp );
}
