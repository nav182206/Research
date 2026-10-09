/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5452
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f94b3f64e6572c8cec73a538588f7cd754bcfa88
 */

static void test_qga_fstrim(gconstpointer fix)

{

    const TestFixture *fixture = fix;

    QDict *ret;

    QList *list;

    const QListEntry *entry;



    ret = qmp_fd(fixture->fd, "{'execute': 'guest-fstrim',"

                 " arguments: { minimum: 4194304 } }");

    g_assert_nonnull(ret);

    qmp_assert_no_error(ret);

    list = qdict_get_qlist(ret, "return");

    entry = qlist_first(list);

    g_assert(qdict_haskey(qobject_to_qdict(entry->value), "paths"));



    QDECREF(ret);

}
