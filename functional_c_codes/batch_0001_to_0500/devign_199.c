/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_199
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e7f136d8b4383d99f1b034a045b73f9b12a4eae
 */

static VncServerInfo *vnc_server_info_get(VncDisplay *vd)

{

    VncServerInfo *info;

    Error *err = NULL;



    info = g_malloc(sizeof(*info));

    vnc_init_basic_info_from_server_addr(vd->lsock,

                                         qapi_VncServerInfo_base(info), &err);

    info->has_auth = true;

    info->auth = g_strdup(vnc_auth_name(vd));

    if (err) {

        qapi_free_VncServerInfo(info);

        info = NULL;

        error_free(err);

    }

    return info;

}
