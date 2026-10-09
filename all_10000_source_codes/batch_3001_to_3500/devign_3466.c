/* 
 * Benchmark Sample ID : devign_3466
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8d06b149271cbd5b19bed5bde8da5ecef40ecbc6
 */

static void smc91c111_release_packet(smc91c111_state *s, int packet)

{

    s->allocated &= ~(1 << packet);

    if (s->tx_alloc == 0x80)

        smc91c111_tx_alloc(s);

    qemu_flush_queued_packets(qemu_get_queue(s->nic));

}
