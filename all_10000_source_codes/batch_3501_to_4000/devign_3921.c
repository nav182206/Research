/* 
 * Benchmark Sample ID : devign_3921
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=568c73a4783cd981e9aa6de4f15dcda7829643ad
 */

int qemu_input_key_value_to_number(const KeyValue *value)

{

    if (value->kind == KEY_VALUE_KIND_QCODE) {

        return qcode_to_number[value->qcode];

    } else {

        assert(value->kind == KEY_VALUE_KIND_NUMBER);

        return value->number;

    }

}
