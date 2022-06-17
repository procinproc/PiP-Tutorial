#include <pip/pip.h>
int var;
int foo( void ) { return var; }
int main( int argc, char **argv ) {
  int pipid, ntasks, prev;
  int(*funcp)(void);
  pip_get_pipid( &pipid );
  pip_get_ntasks( &ntasks );
  prev = ( pipid == 0 ) ? ntasks - 1 : pipid - 1;
  var = pipid * 100;
  pip_named_export( foo, "foo@%d", pipid );
  pip_named_import( prev, (void**) &funcp, "foo@%d", prev );
  printf( "PIPID:%d foo(%d)=%d\n", pipid, prev, funcp() );
  return 0;
}
