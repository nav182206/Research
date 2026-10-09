/* 
 * Benchmark Sample ID : devign_3349
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=52b4bb7383b32e4e7512f98c57738c8fc9cb35ba
 */

static uint32_t do_mac_read(lan9118_state *s, int reg)

{

    switch (reg) {

    case MAC_CR:

        return s->mac_cr;

    case MAC_ADDRH:

        return s->conf.macaddr.a[4] | (s->conf.macaddr.a[5] << 8);

    case MAC_ADDRL:

        return s->conf.macaddr.a[0] | (s->conf.macaddr.a[1] << 8)

               | (s->conf.macaddr.a[2] << 16) | (s->conf.macaddr.a[3] << 24);

    case MAC_HASHH:

        return s->mac_hashh;

        break;

    case MAC_HASHL:

        return s->mac_hashl;

        break;

    case MAC_MII_ACC:

        return s->mac_mii_acc;

    case MAC_MII_DATA:

        return s->mac_mii_data;

    case MAC_FLOW:

        return s->mac_flow;

    default:

        hw_error("lan9118: Unimplemented MAC register read: %d\n",

                 s->mac_cmd & 0xf);

    }

}
