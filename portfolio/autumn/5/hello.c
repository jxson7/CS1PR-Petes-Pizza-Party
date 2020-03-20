/**
 * @file
 * @author Oliver Barnwell <qb011080@reading.ac.uk>
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * @section DESCRIPTION
 *
 * Simple utility created to read from standard input and determine
 * the line count.
 */

#include "stdio.h"

/**
 * Main entrypoint to application. Consumes characters from standard
 * input until EOF is enountered. Prints the recorded line-count to
 * standard output.
 *
 * @param argc Number of arguments passed to program.
 * @param argv Array of "strings" to argument values.
 *
 * @return Exit status code of program.
 */
int main(int argc, char *argv[]) {
  int c;      // Current character
  int lc = 0; // The line count, i.e., number of lines parsed

  // Accept characters through stdin until EOF enountered.
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++lc;
    }
  }

  printf("Line Count: %d\n", lc);

  // Success
  return 0;
}


#include  <stdio.h>


/**
 @Return shoe
 */
int main(int argc , char *argv []) {
  char *name = argv [1];
  printf("Hello %s! %d %s\n", name, argc, argv[2]);
  return 0;
}
