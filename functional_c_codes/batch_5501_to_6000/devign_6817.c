/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6817
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ac4b32df71bd932838043a4838b86d11e169707f
 */

const uint8_t *get_submv_prob(uint32_t left, uint32_t top)

{

    if (left == top)

        return vp8_submv_prob[4 - !!left];

    if (!top)

        return vp8_submv_prob[2];

    return vp8_submv_prob[1 - !!left];

}
