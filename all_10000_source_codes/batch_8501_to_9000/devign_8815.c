/* 
 * Benchmark Sample ID : devign_8815
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ef76dc59fa5203d146a2acf85a0ad5a5971a4824
 */

START_TEST(simple_string)

{

    int i;

    struct {

        const char *encoded;

        const char *decoded;

    } test_cases[] = {

        { "\"hello world\"", "hello world" },

        { "\"the quick brown fox jumped over the fence\"",

          "the quick brown fox jumped over the fence" },

        {}

    };



    for (i = 0; test_cases[i].encoded; i++) {

        QObject *obj;

        QString *str;



        obj = qobject_from_json(test_cases[i].encoded);



        fail_unless(obj != NULL);

        fail_unless(qobject_type(obj) == QTYPE_QSTRING);

        

        str = qobject_to_qstring(obj);

        fail_unless(strcmp(qstring_get_str(str), test_cases[i].decoded) == 0);



        str = qobject_to_json(obj);

        fail_unless(strcmp(qstring_get_str(str), test_cases[i].encoded) == 0);



        qobject_decref(obj);

        

        QDECREF(str);

    }

}
