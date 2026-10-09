/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5068
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3f5ec2b5e92706e3b807059f79b1fb5d936e567
 */

static void net_socket_receive_dgram(void *opaque, const uint8_t *buf, size_t size)

{

    NetSocketState *s = opaque;

    sendto(s->fd, buf, size, 0,

           (struct sockaddr *)&s->dgram_dst, sizeof(s->dgram_dst));

}
