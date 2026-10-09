/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3598
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d6af26c55c1ea30f85a7d9edbc373f53be1743ee
 */

static inline int get_len(LZOContext *c, int x, int mask)

{

    int cnt = x & mask;

    if (!cnt) {

        while (!(x = get_byte(c)))

            cnt += 255;

        cnt += mask + x;

    }

    return cnt;

}
