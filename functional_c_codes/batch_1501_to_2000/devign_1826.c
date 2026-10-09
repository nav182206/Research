/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1826
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0752706de257b38763006ff5bb6b39a97e669ba2
 */

void net_slirp_redir(const char *redir_str)

{

    struct slirp_config_str *config;



    if (QTAILQ_EMPTY(&slirp_stacks)) {

        config = qemu_malloc(sizeof(*config));

        pstrcpy(config->str, sizeof(config->str), redir_str);

        config->flags = SLIRP_CFG_HOSTFWD | SLIRP_CFG_LEGACY;

        config->next = slirp_configs;

        slirp_configs = config;

        return;

    }



    slirp_hostfwd(QTAILQ_FIRST(&slirp_stacks), NULL, redir_str, 1);

}
