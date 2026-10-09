/* 
 * Benchmark Sample ID : devign_6231
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1fe2b245910d42715e556458afe7d975d9417ef
 */

void test_self_modifying_code(void)

{

    int (*func)(void);



    func = (void *)code;

    printf("self modifying code:\n");

    printf("func1 = 0x%x\n", func());

    code[1] = 0x2;

    printf("func1 = 0x%x\n", func());

}
