/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5707
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac531cb6e542b1e61d668604adf9dc5306a948c0
 */

START_TEST(qdict_put_obj_test)

{

    QInt *qi;

    QDict *qdict;

    QDictEntry *ent;

    const int num = 42;



    qdict = qdict_new();



    // key "" will have tdb hash 12345

    qdict_put_obj(qdict, "", QOBJECT(qint_from_int(num)));



    fail_unless(qdict_size(qdict) == 1);

    ent = QLIST_FIRST(&qdict->table[12345 % QDICT_BUCKET_MAX]);

    qi = qobject_to_qint(ent->value);

    fail_unless(qint_get_int(qi) == num);



    // destroy doesn't exit yet

    QDECREF(qi);

    g_free(ent->key);

    g_free(ent);

    g_free(qdict);

}
