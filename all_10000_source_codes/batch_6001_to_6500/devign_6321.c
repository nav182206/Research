/* 
 * Benchmark Sample ID : devign_6321
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5fb6c7a8b26eab1a22207d24b4784bd2b39ab54b
 */

static int start_auth_vencrypt(VncState *vs)

{

    /* Send VeNCrypt version 0.2 */

    vnc_write_u8(vs, 0);

    vnc_write_u8(vs, 2);



    vnc_read_when(vs, protocol_client_vencrypt_init, 2);

    return 0;

}
