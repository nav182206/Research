/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9174
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

uint16_t cpu_inw(CPUState *env, pio_addr_t addr)

{

    uint16_t val;

    val = ioport_read(1, addr);

    LOG_IOPORT("inw : %04"FMT_pioaddr" %04"PRIx16"\n", addr, val);

#ifdef CONFIG_KQEMU

    if (env)

        env->last_io_time = cpu_get_time_fast();

#endif

    return val;

}
