/* 
 * Benchmark Sample ID : devign_2442
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ddbcc48b646737c8bff7f8e28e0a69dca65509cf
 */

static int ftp_type(FTPContext *s)

{

    const char *command = "TYPE I\r\n";

    const int type_codes[] = {200, 0};



    if (!ftp_send_command(s, command, type_codes, NULL))

        return AVERROR(EIO);



    return 0;

}
