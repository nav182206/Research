/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9551
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b5469b1104a4b0c870dd805d9fb9d844b56d987e
 */

void vnc_tight_clear(VncState *vs)

{

    int i;

    for (i=0; i<ARRAY_SIZE(vs->tight.stream); i++) {

        if (vs->tight.stream[i].opaque) {

            deflateEnd(&vs->tight.stream[i]);

        }

    }



    buffer_free(&vs->tight.tight);

    buffer_free(&vs->tight.zlib);

    buffer_free(&vs->tight.gradient);

#ifdef CONFIG_VNC_JPEG

    buffer_free(&vs->tight.jpeg);





}
