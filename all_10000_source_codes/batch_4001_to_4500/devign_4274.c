/* 
 * Benchmark Sample ID : devign_4274
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f6b4fc8b23b1154577c72937b70e565716bb0a60
 */

static void cmd_args_init(CmdArgs *cmd_args)

{

    cmd_args->name = qstring_new();

    cmd_args->type = cmd_args->flag = cmd_args->optional = 0;

}
