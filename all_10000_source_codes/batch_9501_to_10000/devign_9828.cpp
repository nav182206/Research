/* 
 * Benchmark Sample ID : devign_9828
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=124fe7fb1b7a1db8cb2ebb9edae84716ffaf37ce
 */

vcard_emul_find_vreader_from_slot(PK11SlotInfo *slot)

{

    VReaderList *reader_list = vreader_get_reader_list();

    VReaderListEntry *current_entry = NULL;



    if (reader_list == NULL) {

        return NULL;

    }

    for (current_entry = vreader_list_get_first(reader_list); current_entry;

                        current_entry = vreader_list_get_next(current_entry)) {

        VReader *reader = vreader_list_get_reader(current_entry);

        VReaderEmul *reader_emul = vreader_get_private(reader);

        if (reader_emul->slot == slot) {


            return reader;

        }

        vreader_free(reader);

    }




    return NULL;

}
