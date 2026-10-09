/* 
 * Benchmark Sample ID : devign_2329
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c92458538f501eda585b4b774c50644aed391a8a
 */

void helper_set_alarm(CPUAlphaState *env, uint64_t expire)

{

    if (expire) {

        env->alarm_expire = expire;

        qemu_mod_timer(env->alarm_timer, expire);

    } else {

        qemu_del_timer(env->alarm_timer);

    }

}
