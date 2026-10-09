/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9636
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b57ed9bf075e33cdd2f9eb545ff555301dd57221
 */

static int virtio_ccw_hcall_notify(const uint64_t *args)

{

    uint64_t subch_id = args[0];

    uint64_t queue = args[1];

    SubchDev *sch;

    int cssid, ssid, schid, m;



    if (ioinst_disassemble_sch_ident(subch_id, &m, &cssid, &ssid, &schid)) {



    sch = css_find_subch(m, cssid, ssid, schid);

    if (!sch || !css_subch_visible(sch)) {






    virtio_queue_notify(virtio_ccw_get_vdev(sch), queue);

    return 0;
