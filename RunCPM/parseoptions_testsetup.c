
#include "parseoptions_testsetup.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// Faking stdio begin
#undef FILE
#define FILE char

FILE mystdin[1];
FILE mystdout[1];
FILE mystderr[2000];
FILE myinfile[1];
FILE myoutfile[1];

void myfprintf(FILE *out, const char *fmt, ...) {
  va_list va;
  va_start(va, fmt);
  char *attach = out + strlen(out);
  vsprintf (attach, fmt, va);
}

char infilename[50];
char outfilename[50];
char unknownfilename[50];

char *myfopen(const char *fname, const char *mode) {
  if (*mode == 'r') {
    strcpy(infilename, fname);
    return myinfile;
  } else if (*mode == 'w') {
    strcpy(outfilename, fname);
    return myoutfile;
  } else {
    strcpy(unknownfilename, fname);
    return NULL;
  }
}

#undef stdin
#undef stdout
#undef stderr
#define stdin mystdin
#define stdout mystdout
#define stderr mystderr
#define fprintf myfprintf
#define fopen myfopen

// Faking stdio end

int exit_value = 0;
#define EXIT_FAILURE 1
void myexit(int value) { exit_value = value; }
#define exit myexit

#define FALSE 0
#define TRUE 1

FILE		*streamInputFile = NULL;
FILE		*streamOutputFile = NULL;
char	streamInputActive = FALSE;
char	consoleOutputActive = TRUE;

void _file_failure_exit(char *argv[], char* fmt, char* filename)
{
}

void setupParseoptionsTest(void) {
  *infilename = 0;
  *outfilename = 0;
  *unknownfilename = 0;
  streamInputFile = NULL;
  streamOutputFile = NULL;
  streamInputActive = FALSE;
  consoleOutputActive = TRUE;
}

#include "parseoptions_vstudio.h"
