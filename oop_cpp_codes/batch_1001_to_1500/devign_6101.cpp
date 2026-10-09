/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6101
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static QDictEntry *qdict_find(const QDict *qdict,

                              const char *key, unsigned int hash)

{

    QDictEntry *entry;



    LIST_FOREACH(entry, &qdict->table[hash], next)

        if (!strcmp(entry->key, key))

            return entry;



    return NULL;

}
