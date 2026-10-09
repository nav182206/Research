/* 
 * Benchmark Sample ID : devign_1770
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

uint8_t cpu_inb(CPUState *env, pio_addr_t addr)

{

    uint8_t val;

    val = ioport_read(0, addr);

    LOG_IOPORT("inb : %04"FMT_pioaddr" %02"PRIx8"\n", addr, val);

#ifdef CONFIG_KQEMU

    if (env)

        env->last_io_time = cpu_get_time_fast();

#endif

    return val;

}
