/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4929
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9f61abc8111c7c43f49ca012e957a108b9cc7610
 */

static void close_file(OutputStream *os)

{

    int64_t pos = avio_tell(os->out);

    avio_seek(os->out, 0, SEEK_SET);

    avio_wb32(os->out, pos);

    avio_flush(os->out);

    avio_close(os->out);

    os->out = NULL;

}
