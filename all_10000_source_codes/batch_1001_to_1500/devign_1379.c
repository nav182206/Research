/* 
 * Benchmark Sample ID : devign_1379
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=439e2a6e10ed7f5da819bf7dcaa54b8cfdbeab0d
 */

Aml *aml_index(Aml *arg1, Aml *idx)

{

    Aml *var = aml_opcode(0x88 /* IndexOp */);

    aml_append(var, arg1);

    aml_append(var, idx);

    build_append_byte(var->buf, 0x00 /* NullNameOp */);

    return var;

}
