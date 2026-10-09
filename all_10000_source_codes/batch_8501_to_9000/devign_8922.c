/* 
 * Benchmark Sample ID : devign_8922
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=387eedebf60a463ba30833588f10123da296ba4d
 */

MigrationCapabilityStatusList *qmp_query_migrate_capabilities(Error **errp)

{

    MigrationCapabilityStatusList *head = NULL;

    MigrationCapabilityStatusList *caps;

    MigrationState *s = migrate_get_current();

    int i;




    for (i = 0; i < MIGRATION_CAPABILITY_MAX; i++) {

        if (head == NULL) {

            head = g_malloc0(sizeof(*caps));

            caps = head;

        } else {

            caps->next = g_malloc0(sizeof(*caps));

            caps = caps->next;

        }

        caps->value =

            g_malloc(sizeof(*caps->value));

        caps->value->capability = i;

        caps->value->state = s->enabled_capabilities[i];

    }



    return head;

}
