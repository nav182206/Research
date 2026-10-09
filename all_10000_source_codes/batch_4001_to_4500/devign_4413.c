/* 
 * Benchmark Sample ID : devign_4413
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1c37d0e94048502f9874e6356ce7136d4b05bdb
 */

static int qemu_savevm_state(Monitor *mon, QEMUFile *f)

{

    int ret;



    if (qemu_savevm_state_blocked(mon)) {

        ret = -EINVAL;

        goto out;

    }



    ret = qemu_savevm_state_begin(f, 0, 0);

    if (ret < 0)

        goto out;



    do {

        ret = qemu_savevm_state_iterate(f);

        if (ret < 0)

            goto out;

    } while (ret == 0);



    ret = qemu_savevm_state_complete(f);



out:

    if (ret == 0) {

        ret = qemu_file_get_error(f);

    }



    return ret;

}
