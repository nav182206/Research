/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2268
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ee5b34d56e7fa9c1eb1a2aeb2bf7b55516c99c8a
 */

static uint16_t mlp_checksum16(const uint8_t *buf, unsigned int buf_size)

{

    uint16_t crc;



    if (!crc_init) {

        av_crc_init(crc_2D, 0, 16, 0x002D, sizeof(crc_2D));

        crc_init = 1;

    }



    crc = av_crc(crc_2D, 0, buf, buf_size - 2);

    crc ^= AV_RL16(buf + buf_size - 2);

    return crc;

}
