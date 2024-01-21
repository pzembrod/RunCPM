
void _usage(char *argv[]) {
	fprintf(stderr,
		"RunCPM - an emulator to run CP/M programs on modern hosts\n"
		"usage: %s [-i input_file] [-o output_file] [-s]\n", argv[0]);
	fprintf(stderr,
		"  -i input_file: console input will be read from the file "
		"with the\n     given name. "
		"After input file's EOF, further console input\n     will be read "
		"from the keyboard.\n");
	fprintf(stderr,
		"  -o output_file: console output will be written to the file "
		"with the\n     given name, in addition to the screen.\n");
	fprintf(stderr,
		"  -s: console input and output is connected directly to "
		"stdin and stdout.\n");
}

#define SET_OPTARG ++i; if (i >= argc) {++errflg; break;} optarg = argv[i];

void _parse_options(int argc, char *argv[]) {
	int errflg = 0;
	char *optarg;
	for (int i = 1; i < argc && errflg == 0; ++i) {
		if (strcmp("-i", argv[i]) == 0) {
			/* ++i;
			if (i >= argc) {
				++errflg;
				break;
			}
			optarg = argv[i]; */
			SET_OPTARG
			streamInputFile = fopen(optarg, "r");
			if (NULL == streamInputFile) {
				_file_failure_exit(argv,
					"error opening console input file %s", optarg);
			}
			streamInputActive = TRUE;
			continue;
		}
		if (strcmp("-o", argv[i]) == 0) {
			SET_OPTARG
			streamOutputFile = fopen(optarg, "w");
			if (NULL == streamOutputFile) {
				_file_failure_exit(argv,
					"error opening console output file %s", optarg);
			}
			continue;
		}
		if (strcmp("-s", argv[i]) == 0) {
			streamInputFile = stdin;
			streamOutputFile = stdout;
			streamInputActive = TRUE;
			consoleOutputActive = FALSE;
			continue;
		}
		/*	case ':':       // -i or -o without operand
				fprintf(stderr,
					"Option -%c requires an operand\n", optopt);
				errflg++;
				break; */
		fprintf(stderr,
			"Unrecognized option: '%s'\n", argv[i]);
		errflg++;
	}
	if (errflg) {
		_usage(argv);
		exit(EXIT_FAILURE);
	}
}
