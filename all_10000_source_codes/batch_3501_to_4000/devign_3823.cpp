/* 
 * Benchmark Sample ID : devign_3823
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1687a089f103f9b7a1b4a1555068054cb46ee9e9
 */

vreader_list_delete(VReaderList *list)

{

    VReaderListEntry *current_entry;

    VReaderListEntry *next_entry = NULL;

    for (current_entry = vreader_list_get_first(list); current_entry;

         current_entry = next_entry) {

        next_entry = vreader_list_get_next(current_entry);

        vreader_list_entry_delete(current_entry);

    }

    list->head = NULL;

    list->tail = NULL;

    g_free(list);

}
