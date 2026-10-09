/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5012
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ef76dc59fa5203d146a2acf85a0ad5a5971a4824
 */

START_TEST(unterminated_array_comma)

{

    QObject *obj = qobject_from_json("[32,");

    fail_unless(obj == NULL);

}
