/* 
 * Benchmark Sample ID : devign_7965
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8ef9dcf1d74aea55bf39f1e479fe67e98d973954
 */

void ff_mpeg_set_erpic(ERPicture *dst, Picture *src)

{

    int i;




    if (!src)

        return;



    dst->f = &src->f;

    dst->tf = &src->tf;



    for (i = 0; i < 2; i++) {

        dst->motion_val[i] = src->motion_val[i];

        dst->ref_index[i] = src->ref_index[i];

    }



    dst->mb_type = src->mb_type;

    dst->field_picture = src->field_picture;

}
