#include <stdio.h>

/* COMPILATION INSTRUCTIONS
Try both:
$ gcc -DDEBUG preprocessor2.c
$ ./a.out
$ gcc preprocessor2.c
$ ./a.out
*/

// here is a nice usage of conditional compilation
// it controls if we print debugger information or not
// during compilation, add -DDEBUG to gcc to enable this flag!
#ifdef DEBUG
  #define debug(x) printf(x)
#else
  #define debug(x) // we remove the token
#endif

int main(int argc, char ** argv){
  debug("I will only be printed if DEBUG mode is on!\n");
  return 0;
}
