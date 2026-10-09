/* 
 * Benchmark Sample ID : devign_2135
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b40acf99bef69fa8ab0f9092ff162fde945eec12
 */

void cpu_outw(pio_addr_t addr, uint16_t val)

{

    LOG_IOPORT("outw: %04"FMT_pioaddr" %04"PRIx16"\n", addr, val);

    trace_cpu_out(addr, val);

    ioport_write(1, addr, val);

}
