/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8261
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d3b12f5dec4b27ebab58fb5797cb67bacced773b
 */

int qemu_add_wait_object(HANDLE handle, WaitObjectFunc *func, void *opaque)

{

    WaitObjects *w = &wait_objects;



    if (w->num >= MAXIMUM_WAIT_OBJECTS)

        return -1;

    w->events[w->num] = handle;

    w->func[w->num] = func;

    w->opaque[w->num] = opaque;

    w->num++;

    return 0;

}
