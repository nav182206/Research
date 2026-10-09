/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2699
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ef76dc59fa5203d146a2acf85a0ad5a5971a4824
 */

START_TEST(vararg_string)

{

    int i;

    struct {

        const char *decoded;

    } test_cases[] = {

        { "hello world" },

        { "the quick brown fox jumped over the fence" },

        {}

    };



    for (i = 0; test_cases[i].decoded; i++) {

        QObject *obj;

        QString *str;



        obj = qobject_from_jsonf("%s", test_cases[i].decoded);



        fail_unless(obj != NULL);

        fail_unless(qobject_type(obj) == QTYPE_QSTRING);

        

        str = qobject_to_qstring(obj);

        fail_unless(strcmp(qstring_get_str(str), test_cases[i].decoded) == 0);



        QDECREF(str);

    }

}
