/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4965
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=acbbc036619092fcd2c882222e1be168bd972b3e
 */

static void entropy_available(void *opaque)

{

    RndRandom *s = RNG_RANDOM(opaque);

    uint8_t buffer[s->size];

    ssize_t len;



    len = read(s->fd, buffer, s->size);




    g_assert(len != -1);



    s->receive_func(s->opaque, buffer, len);

    s->receive_func = NULL;



    qemu_set_fd_handler(s->fd, NULL, NULL, NULL);
