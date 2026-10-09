/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6954
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5836d16812cda6b93380632802d56411972e3148
 */

static void fw_cfg_init1(DeviceState *dev)

{

    FWCfgState *s = FW_CFG(dev);

    MachineState *machine = MACHINE(qdev_get_machine());



    assert(!object_resolve_path(FW_CFG_PATH, NULL));



    object_property_add_child(OBJECT(machine), FW_CFG_NAME, OBJECT(s), NULL);



    qdev_init_nofail(dev);



    fw_cfg_add_bytes(s, FW_CFG_SIGNATURE, (char *)"QEMU", 4);

    fw_cfg_add_bytes(s, FW_CFG_UUID, &qemu_uuid, 16);

    fw_cfg_add_i16(s, FW_CFG_NOGRAPHIC, (uint16_t)!machine->enable_graphics);

    fw_cfg_add_i16(s, FW_CFG_NB_CPUS, (uint16_t)smp_cpus);

    fw_cfg_add_i16(s, FW_CFG_BOOT_MENU, (uint16_t)boot_menu);

    fw_cfg_bootsplash(s);

    fw_cfg_reboot(s);



    s->machine_ready.notify = fw_cfg_machine_ready;

    qemu_add_machine_init_done_notifier(&s->machine_ready);

}
