/* 
 * Benchmark Sample ID : devign_7140
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0f7bfd8198ffad58a5095ac5d7a46288ea7f5c6e
 */

static void qxl_exit_vga_mode(PCIQXLDevice *d)

{

    if (d->mode != QXL_MODE_VGA) {

        return;

    }

    trace_qxl_exit_vga_mode(d->id);


    qxl_destroy_primary(d, QXL_SYNC);

}
