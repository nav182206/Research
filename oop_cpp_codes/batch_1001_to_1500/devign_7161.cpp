/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7161
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=882b3b97697affb36ca3d174f42f846232008979
 */

static int css_add_virtual_chpid(uint8_t cssid, uint8_t chpid, uint8_t type)

{

    CssImage *css;



    trace_css_chpid_add(cssid, chpid, type);

    if (cssid > MAX_CSSID) {

        return -EINVAL;

    }

    css = channel_subsys.css[cssid];

    if (!css) {

        return -EINVAL;

    }

    if (css->chpids[chpid].in_use) {

        return -EEXIST;

    }

    css->chpids[chpid].in_use = 1;

    css->chpids[chpid].type = type;

    css->chpids[chpid].is_virtual = 1;



    css_generate_chp_crws(cssid, chpid);



    return 0;

}
