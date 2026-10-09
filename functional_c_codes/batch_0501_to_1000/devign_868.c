/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_868
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3d002df33eb034757d98e1ae529318f57df78f91
 */

static size_t buffered_get_rate_limit(void *opaque)

{

    QEMUFileBuffered *s = opaque;

  

    return s->xfer_limit;

}
