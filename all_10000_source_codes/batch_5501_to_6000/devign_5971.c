/* 
 * Benchmark Sample ID : devign_5971
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dfd100f242370886bb6732f70f1f7cbd8eb9fedc
 */

char_socket_get_addr(Object *obj, Visitor *v, const char *name,

                     void *opaque, Error **errp)

{

    SocketChardev *s = SOCKET_CHARDEV(obj);



    visit_type_SocketAddress(v, name, &s->addr, errp);

}
