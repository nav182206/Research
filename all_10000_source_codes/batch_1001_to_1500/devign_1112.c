/* 
 * Benchmark Sample ID : devign_1112
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd859081453f94c3cbd6527289e41b7fddbf645f
 */

static int tpm_passthrough_unix_transfer(TPMPassthruState *tpm_pt,

                                         const TPMLocality *locty_data)

{

    return tpm_passthrough_unix_tx_bufs(tpm_pt,

                                        locty_data->w_buffer.buffer,

                                        locty_data->w_offset,

                                        locty_data->r_buffer.buffer,

                                        locty_data->r_buffer.size);

}
