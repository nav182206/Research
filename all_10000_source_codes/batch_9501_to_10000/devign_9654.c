/* 
 * Benchmark Sample ID : devign_9654
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9c605cb13547a5faa5cb1092e3e44ac8b0d0b841
 */

static void dump_ops(const uint16_t *opc_buf)

{

    const uint16_t *opc_ptr;

    int c;

    opc_ptr = opc_buf;

    for(;;) {

        c = *opc_ptr++;

        fprintf(logfile, "0x%04x: %s\n", opc_ptr - opc_buf - 1, op_str[c]);

        if (c == INDEX_op_end)

            break;

    }

}
