/* 
 * Benchmark Sample ID : devign_3720
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void fill_thread_info(struct elf_note_info *info, const CPUState *env)

{

    TaskState *ts = (TaskState *)env->opaque;

    struct elf_thread_status *ets;



    ets = qemu_mallocz(sizeof (*ets));

    ets->num_notes = 1; /* only prstatus is dumped */

    fill_prstatus(&ets->prstatus, ts, 0);

    elf_core_copy_regs(&ets->prstatus.pr_reg, env);

    fill_note(&ets->notes[0], "CORE", NT_PRSTATUS, sizeof (ets->prstatus),

        &ets->prstatus);



    TAILQ_INSERT_TAIL(&info->thread_list, ets, ets_link);



    info->notes_size += note_size(&ets->notes[0]);

}
