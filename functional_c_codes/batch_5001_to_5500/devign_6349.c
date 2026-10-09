/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6349
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=26fc6ffec45c954cd8ca46342ac75cd90bcc7e02
 */

static inline void libopenjpeg_copyto16(AVFrame *picture, opj_image_t *image) {

    int *comp_data;

    uint16_t *img_ptr;

    int index, x, y;

    int adjust[4];

    for (x = 0; x < image->numcomps; x++)

        adjust[x] = FFMAX(FFMIN(av_pix_fmt_desc_get(picture->format)->comp[x].depth_minus1 + 1 - image->comps[x].prec, 8), 0);



    for (index = 0; index < image->numcomps; index++) {

        comp_data = image->comps[index].data;

        for (y = 0; y < image->comps[index].h; y++) {

            img_ptr = (uint16_t*) (picture->data[index] + y * picture->linesize[index]);

            for (x = 0; x < image->comps[index].w; x++) {

                *img_ptr = 0x8000 * image->comps[index].sgnd + (*comp_data << adjust[index]);

                img_ptr++;

                comp_data++;

            }

        }

    }

}
