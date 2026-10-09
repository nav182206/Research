/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4227
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=439e2a6e10ed7f5da819bf7dcaa54b8cfdbeab0d
 */

Aml *aml_or(Aml *arg1, Aml *arg2)

{

    Aml *var = aml_opcode(0x7D /* OrOp */);

    aml_append(var, arg1);

    aml_append(var, arg2);

    build_append_byte(var->buf, 0x00 /* NullNameOp */);

    return var;

}
