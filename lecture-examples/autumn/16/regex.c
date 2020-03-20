#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <regex.h>

int main(int argc, char ** argv){
  regex_t regex;
  int ret;
  /* Compile te regular expression */
  ret = regcomp(&regex, "([a-zA-Z]+)ing", REG_EXTENDED | REG_ICASE);
  if (ret) {
      printf("Could not compile regex\n");
      exit(1);
  }

  /* Try to match regular expression */
  regmatch_t pmatch[2]; // the first result is the whole match
  char * str = argv[1]; // use the program argument as input
  ret = regexec(& regex, str, 2, pmatch, 0);
  if (!ret) {
      printf("Matches\n");
      for(int i=0; i < 2; i++){
        if(pmatch[i].rm_eo == -1) break;
        str[pmatch[i].rm_eo] = 0; // set the end marker to 0
        printf("%d: %s\n", i, & str[pmatch[i].rm_so]);
      }
  } else if (ret == REG_NOMATCH) {
      printf("Does not match\n");
  } else {
      char err[200];
      regerror(ret, &regex, err, sizeof(err));
      printf("Regex match failed: %s\n", err);
      exit(1);
  }

  regfree(&regex);
  return 0;
}
