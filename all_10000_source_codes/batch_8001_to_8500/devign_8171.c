/* 
 * Benchmark Sample ID : devign_8171
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d70724cec84ff99ffc7f70dd567466acf228b389
 */

static void dump_op_count(void)

{

    int i;

    FILE *f;

    f = fopen("/tmp/op.log", "w");

    for(i = INDEX_op_end; i < NB_OPS; i++) {

        fprintf(f, "%s %" PRId64 "\n", tcg_op_defs[i].name, tcg_table_op_count[i]);

    }

    fclose(f);

}
