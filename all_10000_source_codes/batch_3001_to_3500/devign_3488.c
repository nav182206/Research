/* 
 * Benchmark Sample ID : devign_3488
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2436b61a6b386d712a1813b036921443bd1c5c39
 */

void helper_sysenter(void)

{

    if (env->sysenter_cs == 0) {

        raise_exception_err(EXCP0D_GPF, 0);

    }

    env->eflags &= ~(VM_MASK | IF_MASK | RF_MASK);

    cpu_x86_set_cpl(env, 0);

    cpu_x86_load_seg_cache(env, R_CS, env->sysenter_cs & 0xfffc,

                           0, 0xffffffff,

                           DESC_G_MASK | DESC_B_MASK | DESC_P_MASK |

                           DESC_S_MASK |

                           DESC_CS_MASK | DESC_R_MASK | DESC_A_MASK);

    cpu_x86_load_seg_cache(env, R_SS, (env->sysenter_cs + 8) & 0xfffc,

                           0, 0xffffffff,

                           DESC_G_MASK | DESC_B_MASK | DESC_P_MASK |

                           DESC_S_MASK |

                           DESC_W_MASK | DESC_A_MASK);

    ESP = env->sysenter_esp;

    EIP = env->sysenter_eip;

}
