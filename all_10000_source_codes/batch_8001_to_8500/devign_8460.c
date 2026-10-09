/* 
 * Benchmark Sample ID : devign_8460
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

int qemu_input_key_value_to_qcode(const KeyValue *value)

{

    if (value->type == KEY_VALUE_KIND_QCODE) {

        return value->u.qcode;

    } else {

        assert(value->type == KEY_VALUE_KIND_NUMBER);

        return qemu_input_key_number_to_qcode(value->u.number);

    }

}
