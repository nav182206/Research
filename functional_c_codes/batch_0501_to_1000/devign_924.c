/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_924
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1cadab602343c4f577d2710a43bc66fde5a0d20b
 */

static int select_input_file(uint8_t *no_packet)

{

    int64_t ipts_min = INT64_MAX;

    int i, file_index = -1;



    for (i = 0; i < nb_input_streams; i++) {

        InputStream *ist = input_streams[i];

        int64_t ipts     = ist->pts;



        if (ist->discard || no_packet[ist->file_index])

            continue;

        if (!input_files[ist->file_index]->eof_reached) {

            if (ipts < ipts_min) {

                ipts_min = ipts;

                file_index = ist->file_index;

            }

        }

    }



    return file_index;

}
