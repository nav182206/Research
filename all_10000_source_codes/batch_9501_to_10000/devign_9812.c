/* 
 * Benchmark Sample ID : devign_9812
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=658ae5a7b90139a6a296cd4cd83643d843964796
 */

static uint16List **host_memory_append_node(uint16List **node,

                                            unsigned long value)

{

     *node = g_malloc0(sizeof(**node));

     (*node)->value = value;

     return &(*node)->next;

}
