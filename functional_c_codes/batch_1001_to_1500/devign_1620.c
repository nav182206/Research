/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1620
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3f5ec2b5e92706e3b807059f79b1fb5d936e567
 */

static void dump_receive(void *opaque, const uint8_t *buf, size_t size)

{

    DumpState *s = opaque;

    struct pcap_sf_pkthdr hdr;

    int64_t ts;

    int caplen;



    /* Early return in case of previous error. */

    if (s->fd < 0) {

        return;

    }



    ts = muldiv64(qemu_get_clock(vm_clock), 1000000, ticks_per_sec);

    caplen = size > s->pcap_caplen ? s->pcap_caplen : size;



    hdr.ts.tv_sec = ts / 1000000;

    hdr.ts.tv_usec = ts % 1000000;

    hdr.caplen = caplen;

    hdr.len = size;

    if (write(s->fd, &hdr, sizeof(hdr)) != sizeof(hdr) ||

        write(s->fd, buf, caplen) != caplen) {

        qemu_log("-net dump write error - stop dump\n");

        close(s->fd);

        s->fd = -1;

    }

}
