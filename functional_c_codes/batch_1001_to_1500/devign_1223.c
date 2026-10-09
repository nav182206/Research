/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1223
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=786a4ea82ec9c87e3a895cf41081029b285a5fe5
 */

static void tc6393xb_gpio_handler_update(TC6393xbState *s)

{

    uint32_t level, diff;

    int bit;



    level = s->gpio_level & s->gpio_dir;



    for (diff = s->prev_level ^ level; diff; diff ^= 1 << bit) {

        bit = ffs(diff) - 1;

        qemu_set_irq(s->handler[bit], (level >> bit) & 1);

    }



    s->prev_level = level;

}
