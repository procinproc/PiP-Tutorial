#include <pip/pip.h>
#include <stdlib.h>
int x;
int main( int argc, char **argv ) {
  int pipid, *xp;
  pip_get_pipid( &pipid );
  if( pipid == 0 ) {
    x = strtol( argv[1], NULL, 10 );;
    pip_named_export( &x, "export" );
  } else {
    pip_named_import( 0, (void**) &xp, "export" );
    printf( "%d: %d\n", pipid, *xp );
  }
  return 0;
}
