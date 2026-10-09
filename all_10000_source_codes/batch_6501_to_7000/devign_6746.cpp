/* 
 * Benchmark Sample ID : devign_6746
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=abd696e4f74a9d30801c6ae2693efe4e5979c2f2
 */

int zipl_load(void)

{

    struct mbr *mbr = (void*)sec;

    uint8_t *ns, *ns_end;

    int program_table_entries = 0;

    int pte_len = sizeof(struct scsi_blockptr);

    struct scsi_blockptr *prog_table_entry;

    const char *error = "";



    /* Grab the MBR */

    virtio_read(0, (void*)mbr);



    dputs("checking magic\n");



    if (!zipl_magic(mbr->magic)) {

        error = "zipl_magic 1";

        goto fail;

    }



    debug_print_int("program table", mbr->blockptr.blockno);



    /* Parse the program table */

    if (virtio_read(mbr->blockptr.blockno, sec)) {

        error = "virtio_read";

        goto fail;

    }



    if (!zipl_magic(sec)) {

        error = "zipl_magic 2";

        goto fail;

    }



    ns_end = sec + SECTOR_SIZE;

    for (ns = (sec + pte_len); (ns + pte_len) < ns_end; ns++) {

        prog_table_entry = (struct scsi_blockptr *)ns;

        if (!prog_table_entry->blockno) {

            break;

        }



        program_table_entries++;

    }



    debug_print_int("program table entries", program_table_entries);



    if (!program_table_entries) {

        goto fail;

    }



    /* Run the default entry */



    prog_table_entry = (struct scsi_blockptr *)(sec + pte_len);



    return zipl_run(prog_table_entry);



fail:

    sclp_print("failed loading zipl: ");

    sclp_print(error);

    sclp_print("\n");

    return -1;

}
