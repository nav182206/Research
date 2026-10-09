/* 
 * Benchmark Sample ID : devign_5723
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b40acf99bef69fa8ab0f9092ff162fde945eec12
 */

uint8_t cpu_inb(pio_addr_t addr)

{

    uint8_t val;

    val = ioport_read(0, addr);

    trace_cpu_in(addr, val);

    LOG_IOPORT("inb : %04"FMT_pioaddr" %02"PRIx8"\n", addr, val);

    return val;

}
