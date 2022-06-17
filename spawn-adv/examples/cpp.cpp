#include <pip/pip.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>

char *pipidstr( void ) {
  static char idstr[32];
  int pipid;
  if( pip_get_pipid( &pipid ) != 0 ) {
    sprintf( idstr, "[%s]", "ROOT" );
  } else {
    sprintf( idstr, "[%d]", pipid );
  } 
  return idstr;
}

static int x = 0;

class Hello
{
public:
  Hello(void ) {
    std::cout << pipidstr() << " Hello from " << getpid() << std::endl;
  }
  ~Hello(void ) {
    std::cout << pipidstr() << " Bye from " << getpid() << std::endl;
  }
};

Hello hello;

int main() {
  std::cout << pipidstr() << " MAIN " << getpid() << std::endl;
  return 0;
}
