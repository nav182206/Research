/* 
 * Benchmark Sample ID : devign_7228
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=048c74c4379789d03c857cea038ec00d95b68eaf
 */

static int rtc_load_td(QEMUFile *f, void *opaque, int version_id)

{

    RTCState *s = opaque;



    if (version_id != 1)

        return -EINVAL;



    s->irq_coalesced = qemu_get_be32(f);

    s->period = qemu_get_be32(f);

    rtc_coalesced_timer_update(s);

    return 0;

}
