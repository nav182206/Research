/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7296
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=64d7e9a421fea0ac50b44541f5521de455e7cd5d
 */

void pit_set_gate(PITState *pit, int channel, int val)

{

    PITChannelState *s = &pit->channels[channel];



    switch(s->mode) {

    default:

    case 0:

    case 4:

        /* XXX: just disable/enable counting */

        break;

    case 1:

    case 5:

        if (s->gate < val) {

            /* restart counting on rising edge */

            s->count_load_time = qemu_get_clock(vm_clock);

            pit_irq_timer_update(s, s->count_load_time);

        }

        break;

    case 2:

    case 3:

        if (s->gate < val) {

            /* restart counting on rising edge */

            s->count_load_time = qemu_get_clock(vm_clock);

            pit_irq_timer_update(s, s->count_load_time);

        }

        /* XXX: disable/enable counting */

        break;

    }

    s->gate = val;

}
