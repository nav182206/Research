/* 
 * Benchmark Sample ID : devign_8909
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=66dc50f7057b9a0191f54e55764412202306858d
 */

void ioinst_handle_rsch(S390CPU *cpu, uint64_t reg1)

{

    int cssid, ssid, schid, m;

    SubchDev *sch;

    int ret = -ENODEV;

    int cc;



    if (ioinst_disassemble_sch_ident(reg1, &m, &cssid, &ssid, &schid)) {

        program_interrupt(&cpu->env, PGM_OPERAND, 4);

        return;

    }

    trace_ioinst_sch_id("rsch", cssid, ssid, schid);

    sch = css_find_subch(m, cssid, ssid, schid);

    if (sch && css_subch_visible(sch)) {

        ret = css_do_rsch(sch);

    }

    switch (ret) {

    case -ENODEV:

        cc = 3;

        break;

    case -EINVAL:

        cc = 2;

        break;

    case 0:

        cc = 0;

        break;

    default:

        cc = 1;

        break;

    }

    setcc(cpu, cc);

}
