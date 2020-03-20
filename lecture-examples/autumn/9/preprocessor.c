#include <stdio.h> // C-preprocessor embeds the file stdio.h here!

// preprocessor macro, this can be ANY CODE!
#define HELLO_WORLD "hello world"

int main(int argc, char ** argv){
  printf(HELLO_WORLD "\n"); // here this token will be replaced by the preprocsessor macro.
  return 0;
}
