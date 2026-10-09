/* 
 * Benchmark Sample ID : devign_4404
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ae50b2747f77944faa79eb914272b54eb30b63b3
 */

void mipsnet_init (int base, qemu_irq irq, NICInfo *nd)

{

    MIPSnetState *s;



    qemu_check_nic_model(nd, "mipsnet");



    s = qemu_mallocz(sizeof(MIPSnetState));



    register_ioport_write(base, 36, 1, mipsnet_ioport_write, s);

    register_ioport_read(base, 36, 1, mipsnet_ioport_read, s);

    register_ioport_write(base, 36, 2, mipsnet_ioport_write, s);

    register_ioport_read(base, 36, 2, mipsnet_ioport_read, s);

    register_ioport_write(base, 36, 4, mipsnet_ioport_write, s);

    register_ioport_read(base, 36, 4, mipsnet_ioport_read, s);



    s->io_base = base;

    s->irq = irq;

    if (nd && nd->vlan) {

        s->vc = qemu_new_vlan_client(nd->vlan, nd->model, nd->name,

                                     mipsnet_can_receive, mipsnet_receive, NULL,

                                     mipsnet_cleanup, s);

    } else {

        s->vc = NULL;

    }



    qemu_format_nic_info_str(s->vc, nd->macaddr);



    mipsnet_reset(s);

    register_savevm("mipsnet", 0, 0, mipsnet_save, mipsnet_load, s);

}
