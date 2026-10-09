/* 
 * Benchmark Sample ID : devign_6345
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

void blk_mig_init(void)

{

    QSIMPLEQ_INIT(&block_mig_state.bmds_list);

    QSIMPLEQ_INIT(&block_mig_state.blk_list);

    qemu_mutex_init(&block_mig_state.lock);



    register_savevm_live(NULL, "block", 0, 1, &savevm_block_handlers,

                         &block_mig_state);

}
