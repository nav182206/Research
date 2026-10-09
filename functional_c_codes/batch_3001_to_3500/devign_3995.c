/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3995
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b40acf99bef69fa8ab0f9092ff162fde945eec12
 */

void cpu_outl(pio_addr_t addr, uint32_t val)

{

    LOG_IOPORT("outl: %04"FMT_pioaddr" %08"PRIx32"\n", addr, val);

    trace_cpu_out(addr, val);

    ioport_write(2, addr, val);

}
