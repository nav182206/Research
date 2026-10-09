/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3324
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=107e4b352cc309f9bd7588ef1a44549200620078
 */

World *world_alloc(Rocker *r, size_t sizeof_private,

                   enum rocker_world_type type, WorldOps *ops)

{

    World *w = g_malloc0(sizeof(World) + sizeof_private);



    if (w) {

        w->r = r;

        w->type = type;

        w->ops = ops;

        if (w->ops->init) {

            w->ops->init(w);

        }

    }



    return w;

}
