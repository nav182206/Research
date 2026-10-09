/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2100
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

Aml *aml_local(int num)

{

    Aml *var;

    uint8_t op = 0x60 /* Local0Op */ + num;



    assert(num <= 7);

    var = aml_opcode(op);

    return var;

}
