/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9552
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=124fe7fb1b7a1db8cb2ebb9edae84716ffaf37ce
 */

vcard_emul_replay_insertion_events(void)
{
    VReaderListEntry *current_entry;
    VReaderListEntry *next_entry = NULL;
    VReaderList *list = vreader_get_reader_list();
    for (current_entry = vreader_list_get_first(list); current_entry;
            current_entry = next_entry) {
        VReader *vreader = vreader_list_get_reader(current_entry);
        next_entry = vreader_list_get_next(current_entry);
        vreader_queue_card_event(vreader);
    }
}
