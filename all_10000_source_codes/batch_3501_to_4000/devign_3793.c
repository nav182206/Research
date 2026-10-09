/* 
 * Benchmark Sample ID : devign_3793
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e305e4a4752f70c0b5c3cf5b43ec957881714f7
 */

void vncws_tls_handshake_io(void *opaque)

{

    VncState *vs = (VncState *)opaque;



    if (!vs->tls.session) {

        VNC_DEBUG("TLS Websocket setup\n");

        if (vnc_tls_client_setup(vs, vs->vd->tls.x509cert != NULL) < 0) {

            return;

        }

    }

    VNC_DEBUG("Handshake IO continue\n");

    vncws_start_tls_handshake(vs);

}
