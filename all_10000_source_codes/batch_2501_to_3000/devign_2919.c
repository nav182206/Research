/* 
 * Benchmark Sample ID : devign_2919
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7fd88069241ead2d2fd3e2db1b79e4b292e90001
 */

static av_cold void init_static(void)

{

    if (!huff_vlc[0].bits) {

    INIT_VLC_STATIC(&huff_vlc[0], VLC_BITS, 18,

                &ff_mlp_huffman_tables[0][0][1], 2, 1,

                &ff_mlp_huffman_tables[0][0][0], 2, 1, 512);

    INIT_VLC_STATIC(&huff_vlc[1], VLC_BITS, 16,

                &ff_mlp_huffman_tables[1][0][1], 2, 1,

                &ff_mlp_huffman_tables[1][0][0], 2, 1, 512);

    INIT_VLC_STATIC(&huff_vlc[2], VLC_BITS, 15,

                &ff_mlp_huffman_tables[2][0][1], 2, 1,

                &ff_mlp_huffman_tables[2][0][0], 2, 1, 512);




    ff_mlp_init_crc();
