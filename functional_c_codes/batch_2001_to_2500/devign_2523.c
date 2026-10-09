/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2523
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2d216336f80b294af056a8b1ee8c7306f4d543f3
 */

static int usage(int ret)

{

    fprintf(stderr, "dump (up to maxpkts) AVPackets as they are demuxed by libavformat.\n");

    fprintf(stderr, "each packet is dumped in its own file named like `basename file.ext`_$PKTNUM_$STREAMINDEX_$STAMP_$SIZE_$FLAGS.bin\n");

    fprintf(stderr, "pktdumper file [maxpkts]\n");

    return ret;

}
