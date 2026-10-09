/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1881
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

static void kqemu_record_pc(unsigned long pc)

{

    unsigned long h;

    PCRecord **pr, *r;



    h = pc / PC_REC_SIZE;

    h = h ^ (h >> PC_REC_HASH_BITS);

    h &= (PC_REC_HASH_SIZE - 1);

    pr = &pc_rec_hash[h];

    for(;;) {

        r = *pr;

        if (r == NULL)

            break;

        if (r->pc == pc) {

            r->count++;

            return;

        }

        pr = &r->next;

    }

    r = malloc(sizeof(PCRecord));

    r->count = 1;

    r->pc = pc;

    r->next = NULL;

    *pr = r;

    nb_pc_records++;

}
