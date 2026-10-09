/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7652
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c843af22604edecda10d4bb89d4eede9e1bd3d0
 */

int net_slirp_parse_legacy(QemuOptsList *opts_list, const char *optarg, int *ret)

{

    if (strcmp(opts_list->name, "net") != 0 ||

        strncmp(optarg, "channel,", strlen("channel,")) != 0) {

        return 0;

    }



    error_report("The '-net channel' option is deprecated. "

                 "Please use '-netdev user,guestfwd=...' instead.");



    /* handle legacy -net channel,port:chr */

    optarg += strlen("channel,");



    if (QTAILQ_EMPTY(&slirp_stacks)) {

        struct slirp_config_str *config;



        config = g_malloc(sizeof(*config));

        pstrcpy(config->str, sizeof(config->str), optarg);

        config->flags = SLIRP_CFG_LEGACY;

        config->next = slirp_configs;

        slirp_configs = config;

        *ret = 0;

    } else {

        *ret = slirp_guestfwd(QTAILQ_FIRST(&slirp_stacks), optarg, 1);

    }



    return 1;

}
