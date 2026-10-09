/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1465
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f929ab0569ff31ed5a59b0b0adb7ce09df3fca39
 */

static void assert_file_overwrite(const char *filename)

{

    if (file_overwrite && file_skip) {

        fprintf(stderr, "Error, both -y and -n supplied. Exiting.\n");

        exit_program(1);

    }



    if (!file_overwrite &&

        (strchr(filename, ':') == NULL || filename[1] == ':' ||

         av_strstart(filename, "file:", NULL))) {

        if (avio_check(filename, 0) == 0) {

            if (!using_stdin && !file_skip) {

                fprintf(stderr,"File '%s' already exists. Overwrite ? [y/N] ", filename);

                fflush(stderr);

                if (!read_yesno()) {

                    fprintf(stderr, "Not overwriting - exiting\n");

                    exit_program(1);

                }

            }

            else {

                fprintf(stderr,"File '%s' already exists. Exiting.\n", filename);

                exit_program(1);

            }

        }

    }

}
