/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3502
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

static ImageInfoSpecific *vmdk_get_specific_info(BlockDriverState *bs)

{

    int i;

    BDRVVmdkState *s = bs->opaque;

    ImageInfoSpecific *spec_info = g_new0(ImageInfoSpecific, 1);

    ImageInfoList **next;



    *spec_info = (ImageInfoSpecific){

        .type = IMAGE_INFO_SPECIFIC_KIND_VMDK,

        {

            .vmdk = g_new0(ImageInfoSpecificVmdk, 1),

        },

    };



    *spec_info->u.vmdk = (ImageInfoSpecificVmdk) {

        .create_type = g_strdup(s->create_type),

        .cid = s->cid,

        .parent_cid = s->parent_cid,

    };



    next = &spec_info->u.vmdk->extents;

    for (i = 0; i < s->num_extents; i++) {

        *next = g_new0(ImageInfoList, 1);

        (*next)->value = vmdk_get_extent_info(&s->extents[i]);

        (*next)->next = NULL;

        next = &(*next)->next;

    }



    return spec_info;

}
