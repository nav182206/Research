/* 
 * Benchmark Sample ID : devign_8607
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e81a982aa5398269a2cc344091ffa4930bdd242f
 */

static void cpu_ppc_decr_cb(void *opaque)

{

    PowerPCCPU *cpu = opaque;



    _cpu_ppc_store_decr(cpu, 0x00000000, 0xFFFFFFFF, 1);

}
