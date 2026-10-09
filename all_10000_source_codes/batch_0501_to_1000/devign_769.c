/* 
 * Benchmark Sample ID : devign_769
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=364889cf9c1f3c5e816a30d30d714a84765cfc29
 */

int sws_getColorspaceDetails(SwsContext *c, int **inv_table, int *srcRange, int **table, int *dstRange, int *brightness, int *contrast, int *saturation)

{

    if (isYUV(c->dstFormat) || isGray(c->dstFormat)) return -1;



    *inv_table = c->srcColorspaceTable;

    *table     = c->dstColorspaceTable;

    *srcRange  = c->srcRange;

    *dstRange  = c->dstRange;

    *brightness= c->brightness;

    *contrast  = c->contrast;

    *saturation= c->saturation;



    return 0;

}
