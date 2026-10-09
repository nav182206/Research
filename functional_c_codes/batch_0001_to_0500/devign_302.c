/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_302
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b45c03f585ea9bb1af76c73e82195418c294919d
 */

static int stellaris_sys_init(uint32_t base, qemu_irq irq,

                              stellaris_board_info * board,

                              uint8_t *macaddr)

{

    ssys_state *s;



    s = (ssys_state *)g_malloc0(sizeof(ssys_state));

    s->irq = irq;

    s->board = board;

    /* Most devices come preprogrammed with a MAC address in the user data. */

    s->user0 = macaddr[0] | (macaddr[1] << 8) | (macaddr[2] << 16);

    s->user1 = macaddr[3] | (macaddr[4] << 8) | (macaddr[5] << 16);



    memory_region_init_io(&s->iomem, NULL, &ssys_ops, s, "ssys", 0x00001000);

    memory_region_add_subregion(get_system_memory(), base, &s->iomem);

    ssys_reset(s);

    vmstate_register(NULL, -1, &vmstate_stellaris_sys, s);

    return 0;

}
