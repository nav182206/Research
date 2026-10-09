/* 
 * Benchmark Sample ID : devign_6377
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e01376daea75e888c370aab521a7d4aeaf2ffd1
 */

void ioinst_handle_csch(S390CPU *cpu, uint64_t reg1)

{

    int cssid, ssid, schid, m;

    SubchDev *sch;

    int ret = -ENODEV;

    int cc;



    if (ioinst_disassemble_sch_ident(reg1, &m, &cssid, &ssid, &schid)) {

        program_interrupt(&cpu->env, PGM_OPERAND, 2);

        return;

    }

    trace_ioinst_sch_id("csch", cssid, ssid, schid);

    sch = css_find_subch(m, cssid, ssid, schid);

    if (sch && css_subch_visible(sch)) {

        ret = css_do_csch(sch);

    }

    if (ret == -ENODEV) {

        cc = 3;

    } else {

        cc = 0;

    }

    setcc(cpu, cc);

}
