/* 
 * Benchmark Sample ID : devign_3201
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=69ef1f36b0f882fc5ba9491fb272fa5f83ac1d3d
 */

MigrationParameters *qmp_query_migrate_parameters(Error **errp)

{

    MigrationParameters *params;

    MigrationState *s = migrate_get_current();



    params = g_malloc0(sizeof(*params));

    params->compress_level = s->parameters.compress_level;

    params->compress_threads = s->parameters.compress_threads;

    params->decompress_threads = s->parameters.decompress_threads;

    params->cpu_throttle_initial = s->parameters.cpu_throttle_initial;

    params->cpu_throttle_increment = s->parameters.cpu_throttle_increment;





    return params;

}
