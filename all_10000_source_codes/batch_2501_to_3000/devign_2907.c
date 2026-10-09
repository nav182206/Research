/* 
 * Benchmark Sample ID : devign_2907
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=74474750f1ac522730dae271a5ea5003caa8b73c
 */

static void align_position(AVIOContext *pb,  int64_t offset, uint64_t size)

{

    if (avio_tell(pb) != offset + size)

        avio_seek(pb, offset + size, SEEK_SET);

}
