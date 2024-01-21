
#include "cheat.h"
#include "parseoptions_testsetup.h"

CHEAT_SET_UP(setupParseoptionsTest();)

CHEAT_TEST(dummy,
  cheat_assert(1);
)

CHEAT_TEST(no_opts,
  char *myargv[] = {"runcpm"};
  _parse_options(1, myargv);
  cheat_assert_not(streamInputActive);
  cheat_assert(consoleOutputActive);
  cheat_assert(streamInputFile == NULL);
  cheat_assert(streamOutputFile == NULL);
  cheat_assert_not(exit_value);
  cheat_assert(cheat_compare(mystderr, ""));
)

CHEAT_TEST(dash_i,
  char *myargv[] = {"runcpm", "-i", "inputfile"};
  _parse_options(3, myargv);
  cheat_assert(streamInputActive);
  cheat_assert(consoleOutputActive);
  cheat_assert(streamInputFile == myinfile);
  cheat_assert(streamOutputFile == NULL);
  cheat_assert(cheat_compare(infilename, "inputfile"));
  cheat_assert(cheat_compare(outfilename, ""));
  cheat_assert_not(exit_value);
  cheat_assert(cheat_compare(mystderr, ""));
)

CHEAT_TEST(dash_o,
  char *myargv[] = {"runcpm", "-o", "outputfile"};
  _parse_options(3, myargv);
  cheat_assert_not(streamInputActive);
  cheat_assert(consoleOutputActive);
  cheat_assert(streamInputFile == NULL);
  cheat_assert(streamOutputFile == myoutfile);
  cheat_assert(cheat_compare(infilename, ""));
  cheat_assert(cheat_compare(outfilename, "outputfile"));
  cheat_assert_not(exit_value);
  cheat_assert(cheat_compare(mystderr, ""));
)

CHEAT_TEST(dash_i_o,
  char *myargv[] = {"runcpm", "-i", "inputfile", "-o", "outputfile"};
  _parse_options(5, myargv);
  cheat_assert(streamInputActive);
  cheat_assert(consoleOutputActive);
  cheat_assert(streamInputFile == myinfile);
  cheat_assert(streamOutputFile == myoutfile);
  cheat_assert(cheat_compare(infilename, "inputfile"));
  cheat_assert(cheat_compare(outfilename, "outputfile"));
  cheat_assert_not(exit_value);
  cheat_assert(cheat_compare(mystderr, ""));
)

CHEAT_TEST(dash_o_i,
  char *myargv[] = {"runcpm", "-o", "outputfile", "-i", "inputfile"};
  _parse_options(5, myargv);
  cheat_assert(streamInputActive);
  cheat_assert(consoleOutputActive);
  cheat_assert(streamInputFile == myinfile);
  cheat_assert(streamOutputFile == myoutfile);
  cheat_assert(cheat_compare(infilename, "inputfile"));
  cheat_assert(cheat_compare(outfilename, "outputfile"));
  cheat_assert_not(exit_value);
  cheat_assert(cheat_compare(mystderr, ""));
)

CHEAT_TEST(dash_s,
  char *myargv[] = {"runcpm", "-s"};
  _parse_options(2, myargv);
  cheat_assert(streamInputActive);
  cheat_assert_not(consoleOutputActive);
  cheat_assert(streamInputFile == mystdin);
  cheat_assert(streamOutputFile == mystdout);
  cheat_assert(cheat_compare(infilename, ""));
  cheat_assert(cheat_compare(outfilename, ""));
  cheat_assert_not(exit_value);
  cheat_assert(cheat_compare(mystderr, ""));
)

CHEAT_TEST(dash_i_no_ifile,
  char *myargv[] = {"myruncpm", "-i"};
  _parse_options(2, myargv);
  cheat_assert(exit_value);
  cheat_assert(strncmp(mystderr + 58, "usage: myruncpm", 15) == 0);
)

CHEAT_TEST(dash_o_no_ofile,
  char *myargv[] = {"myruncpm", "-o"};
  _parse_options(2, myargv);
  cheat_assert(exit_value);
  cheat_assert(strncmp(mystderr + 58, "usage: myruncpm", 15) == 0);
)

CHEAT_TEST(dash_i_o_no_ifile,
  char *myargv[] = {"myruncpm", "-o", "outfile", "-i"};
  _parse_options(4, myargv);
  cheat_assert(exit_value);
  cheat_assert(strncmp(mystderr + 58, "usage: myruncpm", 15) == 0);
)

CHEAT_TEST(dash_i_o_no_ofile,
  char *myargv[] = {"myruncpm", "-i", "infile", "-o"};
  _parse_options(4, myargv);
  cheat_assert(exit_value);
  cheat_assert(strncmp(mystderr + 58, "usage: myruncpm", 15) == 0);
)

