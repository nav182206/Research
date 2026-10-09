/* 
 * Benchmark Sample ID : devign_8247
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=363db4b249244f31d3c47fbd5a8b128c95ba8fe7
 */

static int nic_can_receive(NetClientState *nc)

{

    EEPRO100State *s = qemu_get_nic_opaque(nc);

    TRACE(RXTX, logout("%p\n", s));

    return get_ru_state(s) == ru_ready;

#if 0

    return !eepro100_buffer_full(s);

#endif

}
