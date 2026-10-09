/* 
 * Benchmark Sample ID : devign_4198
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0745eb1e4336bf665a911754d18ddd63794b352d
 */

static int parse_filter(const char *spec, struct USBAutoFilter *f)

{

    enum { BUS, DEV, VID, PID, DONE };

    const char *p = spec;

    int i;



    f->bus_num    = -1;

    f->addr       = -1;

    f->vendor_id  = -1;

    f->product_id = -1;



    for (i = BUS; i < DONE; i++) {

    	p = strpbrk(p, ":.");

    	if (!p) break;

        p++;

 

    	if (*p == '*')

            continue;



        switch(i) {

        case BUS: f->bus_num = strtol(p, NULL, 10);    break;

        case DEV: f->addr    = strtol(p, NULL, 10);    break;

        case VID: f->vendor_id  = strtol(p, NULL, 16); break;

        case PID: f->product_id = strtol(p, NULL, 16); break;

        }

    }



    if (i < DEV) {

        fprintf(stderr, "husb: invalid auto filter spec %s\n", spec);

        return -1;

    }



    return 0;

}
