/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3796
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fd34dbea58e097609ff09cf7dcc59f74930195d3
 */

static int mxf_read_cryptographic_context(void *arg, AVIOContext *pb, int tag, int size, UID uid)

{

    MXFCryptoContext *cryptocontext = arg;

    if (size != 16)

        return -1;

    if (IS_KLV_KEY(uid, mxf_crypto_source_container_ul))

        avio_read(pb, cryptocontext->source_container_ul, 16);

    return 0;

}
