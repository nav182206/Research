/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5491
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=73d963c0a75cb99c6aaa3f6f25e427aa0b35a02e
 */

static int openpic_load(QEMUFile* f, void *opaque, int version_id)

{

    OpenPICState *opp = (OpenPICState *)opaque;

    unsigned int i;



    if (version_id != 1) {

        return -EINVAL;

    }



    qemu_get_be32s(f, &opp->gcr);

    qemu_get_be32s(f, &opp->vir);

    qemu_get_be32s(f, &opp->pir);

    qemu_get_be32s(f, &opp->spve);

    qemu_get_be32s(f, &opp->tfrr);



    qemu_get_be32s(f, &opp->nb_cpus);



    for (i = 0; i < opp->nb_cpus; i++) {

        qemu_get_sbe32s(f, &opp->dst[i].ctpr);

        openpic_load_IRQ_queue(f, &opp->dst[i].raised);

        openpic_load_IRQ_queue(f, &opp->dst[i].servicing);

        qemu_get_buffer(f, (uint8_t *)&opp->dst[i].outputs_active,

                        sizeof(opp->dst[i].outputs_active));

    }



    for (i = 0; i < OPENPIC_MAX_TMR; i++) {

        qemu_get_be32s(f, &opp->timers[i].tccr);

        qemu_get_be32s(f, &opp->timers[i].tbcr);

    }



    for (i = 0; i < opp->max_irq; i++) {

        uint32_t val;



        val = qemu_get_be32(f);

        write_IRQreg_idr(opp, i, val);

        val = qemu_get_be32(f);

        write_IRQreg_ivpr(opp, i, val);



        qemu_get_be32s(f, &opp->src[i].ivpr);

        qemu_get_be32s(f, &opp->src[i].idr);

        qemu_get_be32s(f, &opp->src[i].destmask);

        qemu_get_sbe32s(f, &opp->src[i].last_cpu);

        qemu_get_sbe32s(f, &opp->src[i].pending);

    }



    return 0;

}
