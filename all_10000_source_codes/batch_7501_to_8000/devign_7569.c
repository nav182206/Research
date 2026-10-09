/* 
 * Benchmark Sample ID : devign_7569
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=124eb7e476f7e3f66dcdc30f780a45b378751219
 */

static void pop_output_configuration(AACContext *ac) {

    if (ac->oc[1].status != OC_LOCKED) {

        if (ac->oc[0].status == OC_LOCKED) {

            ac->oc[1] = ac->oc[0];

            ac->avctx->channels = ac->oc[1].channels;

            ac->avctx->channel_layout = ac->oc[1].channel_layout;

        }else{

            ac->avctx->channels = 0;

            ac->avctx->channel_layout = 0;

        }

    }

}
