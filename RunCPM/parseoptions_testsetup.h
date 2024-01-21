
#ifndef PARSEOPTIONS_TESTSETUP_H
#define PARSEOPTIONS_TESTSETUP_H

extern char mystdin[];
extern char mystdout[];
extern char mystderr[];
extern char myinfile[];
extern char myoutfile[];

extern char infilename[];
extern char outfilename[];
extern char unknownfilename[];

extern char	*streamInputFile;
extern char	*streamOutputFile;
extern char	streamInputActive;
extern char	consoleOutputActive;

extern int exit_value;

void setupParseoptionsTest(void);

void _usage(char *argv[]);

void _parse_options(int argc, char *argv[]);

#endif
