/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5465
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4f3ed190a673c0020c3ccebb4882ae4675cb5f4d
 */

static void receive_from_chr_layer(SCLPConsoleLM *scon, const uint8_t *buf,

                                   int size)

{

    assert(size == 1);



    if (*buf == '\r' || *buf == '\n') {

        scon->event.event_pending = true;

        return;

    }

    scon->buf[scon->length] = *buf;

    scon->length += 1;

    if (scon->echo) {

        qemu_chr_fe_write(scon->chr, buf, size);

    }

}
