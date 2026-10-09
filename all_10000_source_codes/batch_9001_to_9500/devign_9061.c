/* 
 * Benchmark Sample ID : devign_9061
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0e2487bd6f56445b43307536a465ee2ba810aed9
 */

static void qxl_flip(PCIQXLDevice *qxl, QXLRect *rect)

{

    uint8_t *src = qxl->guest_primary.data;

    uint8_t *dst = qxl->guest_primary.flipped;

    int len, i;



    src += (qxl->guest_primary.surface.height - rect->top - 1) *

        qxl->guest_primary.stride;

    dst += rect->top  * qxl->guest_primary.stride;

    src += rect->left * qxl->guest_primary.bytes_pp;

    dst += rect->left * qxl->guest_primary.bytes_pp;

    len  = (rect->right - rect->left) * qxl->guest_primary.bytes_pp;



    for (i = rect->top; i < rect->bottom; i++) {

        memcpy(dst, src, len);

        dst += qxl->guest_primary.stride;

        src -= qxl->guest_primary.stride;

    }

}
