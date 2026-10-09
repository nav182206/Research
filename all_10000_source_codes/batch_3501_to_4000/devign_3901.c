/* 
 * Benchmark Sample ID : devign_3901
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ec50dd4634ae06091e61f42b7ba975f9ed510ad0
 */

RockerSwitch *qmp_query_rocker(const char *name, Error **errp)

{

    RockerSwitch *rocker = g_malloc0(sizeof(*rocker));

    Rocker *r;



    r = rocker_find(name);

    if (!r) {

        error_set(errp, ERROR_CLASS_GENERIC_ERROR,

                  "rocker %s not found", name);

        return NULL;

    }



    rocker->name = g_strdup(r->name);

    rocker->id = r->switch_id;

    rocker->ports = r->fp_ports;



    return rocker;

}
