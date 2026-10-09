/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_134
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=eb69b50ad9806c4a3b5900392a5acc9837cffd18
 */

static void wm8750_audio_out_cb(void *opaque, int free_b)

{

    struct wm8750_s *s = (struct wm8750_s *) opaque;

    wm8750_out_flush(s);



    s->req_out = free_b;

    s->data_req(s->opaque, free_b >> 2, s->req_in >> 2);

}
