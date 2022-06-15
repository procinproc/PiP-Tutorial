#include <pip/pip.h>
int main( int argc, char **argv ) {
  int pipid;
  pip_get_pipid( &pipid );
  printf( "This is %s [%d]\n", argv[0], pipid );
  return 0;
}
