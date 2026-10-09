/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2352
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dd84efe3c76a5ebf3db254b02870edd193d1a1e7
 */

static int ass_get_duration(const uint8_t *p)

{

    int sh, sm, ss, sc, eh, em, es, ec;

    uint64_t start, end;



    if (sscanf(p, "%*[^,],%d:%d:%d%*c%d,%d:%d:%d%*c%d",

               &sh, &sm, &ss, &sc, &eh, &em, &es, &ec) != 8)

        return 0;

    start = 3600000*sh + 60000*sm + 1000*ss + 10*sc;

    end   = 3600000*eh + 60000*em + 1000*es + 10*ec;

    return end - start;

}
