/* 
 * Benchmark Sample ID : devign_2137
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=47d3df2387ed6927732584ffa4159c26d9f4dee8
 */

static int xenfb_send_position(struct XenInput *xenfb,

			       int abs_x, int abs_y, int z)

{

    union xenkbd_in_event event;



    memset(&event, 0, XENKBD_IN_EVENT_SIZE);

    event.type = XENKBD_TYPE_POS;

    event.pos.abs_x = abs_x;

    event.pos.abs_y = abs_y;

#if __XEN_LATEST_INTERFACE_VERSION__ == 0x00030207

    event.pos.abs_z = z;

#endif

#if __XEN_LATEST_INTERFACE_VERSION__ >= 0x00030208

    event.pos.rel_z = z;

#endif



    return xenfb_kbd_event(xenfb, &event);

}
