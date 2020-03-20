#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define MAXDOCS 10 /* max number of documents */
#define MAXLINES 100 /* max number of lines per document */
#define MAXCHARS 80 /* max number of chars per line */
#define MAXBUFFERSIZE 1024 /* max number of chars in text buffer */

int main(int argc, char ** argv){

  /* 'docs' is our main data structure: a collection of documents */
  char docs[MAXDOCS][MAXLINES][MAXCHARS]; /* 3-D array */

  int ndoc=0, nline=0, nchar=0; /* 3 indexes, one for each dimension */
  char answer;
  int tot_docs, tot_lines, tot_chars;
  printf("Hello there! You can type documents (at most %d).\n\n", MAXDOCS);
  do{ /* repeat for each document */
    printf("You can now enter a document of text.\n");
    printf("Enter an empty line when your input is complete.\n\n");

    char c = getchar();
    char old = c;
    nline=0;
    while(c != EOF){
      if(old == c && c == '\n'){
        docs[ndoc][nline][nchar] = '\0';
        break;
      }
      if(c == '\n') {
        nline++;
        nchar = 0; // reset character position
      }else{
        docs[ndoc][nline][nchar++] = c;
      }
      old = c;
      c = getchar();
    } /* end of while loop for a document */
    docs[ndoc][nline][0] = '\0'; /* end of this document's lines */
    ndoc++;
    if(ndoc < MAXDOCS){
      printf("\nWould you like to enter another document? (y/n): ");
      fflush(stdin);
      answer = getchar();
      getchar(); // get rid of the final '\n'
    } else {
      printf("\nSorry you have already entered the max number of documents (%d).\n", MAXDOCS);
      answer = 'n';
    }
  } while(answer == 'y');
  /* end of do-while loop for the documents */

  /* Let's count our data: */
  tot_docs = ndoc;
  tot_lines = 0;
  tot_chars = 0;
  for(ndoc=0; ndoc < tot_docs; ndoc++){
    printf("\n> Document %d\n", ndoc+1);
    nline=0;
    nchar=0;
    while(docs[ndoc][nline][0] != 0){
      printf("%s\n", docs[ndoc][nline]);
      printf("> line %d has %lu chars \n", nline+1, strlen(docs[ndoc][nline]));
      tot_chars += strlen(docs[ndoc][nline]);
      tot_lines++;
      nline++;
    }
  }
  printf(" You have entered %d docs, %d lines and %d chars.\n ", tot_docs, tot_lines, tot_chars);
  printf("Press enter to quit.\n");
  fflush(stdin);
  getchar();
  return 0;
} /* end of main */
