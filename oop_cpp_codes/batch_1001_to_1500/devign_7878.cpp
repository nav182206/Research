/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7878
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c50f65118b429e6847d5c11b1a20a560d61c34b7
 */

bool gs_allowed(void)

{

    if (kvm_enabled()) {

        MachineClass *mc = MACHINE_GET_CLASS(qdev_get_machine());

        if (object_class_dynamic_cast(OBJECT_CLASS(mc),

                                      TYPE_S390_CCW_MACHINE)) {

            S390CcwMachineClass *s390mc = S390_MACHINE_CLASS(mc);



            return s390mc->gs_allowed;

        }

        /* Make sure the "none" machine can have gs */

        return true;

    }

    return false;

}
