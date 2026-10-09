/* 
 * Benchmark Sample ID : devign_925
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2aae2b8e0abd58e76d616bcbe93c6966d06d0188
 */

static target_ulong get_psr(void)

{

    helper_compute_psr();



#if !defined (TARGET_SPARC64)

    return env->version | (env->psr & PSR_ICC) |

        (env->psref? PSR_EF : 0) |

        (env->psrpil << 8) |

        (env->psrs? PSR_S : 0) |

        (env->psrps? PSR_PS : 0) |

        (env->psret? PSR_ET : 0) | env->cwp;

#else

    return env->version | (env->psr & PSR_ICC) |

        (env->psref? PSR_EF : 0) |

        (env->psrpil << 8) |

        (env->psrs? PSR_S : 0) |

        (env->psrps? PSR_PS : 0) | env->cwp;

#endif

}
