/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9245
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aedbe19297907143f17b733a7ff0e0534377bed1
 */

void qemu_system_reset(bool report)

{

    MachineClass *mc;



    mc = current_machine ? MACHINE_GET_CLASS(current_machine) : NULL;



    cpu_synchronize_all_states();



    if (mc && mc->reset) {

        mc->reset();

    } else {

        qemu_devices_reset();

    }

    if (report) {

        qapi_event_send_reset(&error_abort);

    }

    cpu_synchronize_all_post_reset();

}
