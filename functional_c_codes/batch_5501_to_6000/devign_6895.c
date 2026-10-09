/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6895
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2c2f25eb8920129ef3cfe6da2e1cefdedc485965
 */

static void free_texture(void *opaque, uint8_t *data)

{

    ID3D11Texture2D_Release((ID3D11Texture2D *)opaque);


}
