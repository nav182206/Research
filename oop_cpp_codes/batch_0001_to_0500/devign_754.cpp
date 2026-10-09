/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_754
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7797a73947d5c0e63dd5552b348cf66c384b4555
 */

void pcmcia_info(Monitor *mon, const QDict *qdict)

{

    struct pcmcia_socket_entry_s *iter;



    if (!pcmcia_sockets)

        monitor_printf(mon, "No PCMCIA sockets\n");



    for (iter = pcmcia_sockets; iter; iter = iter->next)

        monitor_printf(mon, "%s: %s\n", iter->socket->slot_string,

                       iter->socket->attached ? iter->socket->card_string :

                       "Empty");

}
