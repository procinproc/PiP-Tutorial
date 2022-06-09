#include <pip/pip.h>
int main( int argc, char **argv ) {
  int pipid, ntasks;
  pip_init( &pipid, &ntasks, NULL, 0 );
  printf( "\"%s\" from PIPID:%d/%d\n",
	  argv[1], pipid, ntasks );
  pip_fin();
  return 0;
}
