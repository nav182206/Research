/* 
 * Benchmark Sample ID : devign_706
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=439e2a6e10ed7f5da819bf7dcaa54b8cfdbeab0d
 */

Aml *aml_shiftleft(Aml *arg1, Aml *count)

{

    Aml *var = aml_opcode(0x79 /* ShiftLeftOp */);

    aml_append(var, arg1);

    aml_append(var, count);

    build_append_byte(var->buf, 0x00); /* NullNameOp */

    return var;

}
