/* 
 * Benchmark Sample ID : devign_233
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b098d56979d2f7fd707c5be85555d114353a28d
 */

static void visitor_output_setup(TestOutputVisitorData *data,

                                 const void *unused)

{

    data->qov = qmp_output_visitor_new();

    g_assert(data->qov != NULL);



    data->ov = qmp_output_get_visitor(data->qov);

    g_assert(data->ov != NULL);

}
