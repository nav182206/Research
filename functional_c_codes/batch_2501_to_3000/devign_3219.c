/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3219
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a426e122173f36f05ea2cb72dcff77b7408546ce
 */

static KVMSlot *kvm_alloc_slot(KVMState *s)

{

    int i;



    for (i = 0; i < ARRAY_SIZE(s->slots); i++) {

        /* KVM private memory slots */

        if (i >= 8 && i < 12)

            continue;

        if (s->slots[i].memory_size == 0)

            return &s->slots[i];

    }



    fprintf(stderr, "%s: no free slot available\n", __func__);

    abort();

}
