#include <pip/pip.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
char *pipidstr( void ) {
  static char idstr[32];
  int pipid;
  if( pip_get_pipid( &pipid ) != 0 ) {
    sprintf( idstr, "[R] PID:" );
  } else {
    sprintf( idstr, "[%d] PID:", pipid );
  } 
  return idstr;
}
static int x = 0;
class Hello {
public:
  Hello(void ) {
    std::cout << pipidstr() << getpid() << " Hello" <<
      std::endl;
  }
  ~Hello(void ) {
    std::cout << pipidstr() << getpid() << " Bye" <<
      std::endl;
  }
};
Hello hello;
int main() {
  std::cout << pipidstr() << getpid() << " MAIN " <<
    std::endl;
  return 0;
}
