/* 
 * Benchmark Sample ID : devign_7876
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7b46add7257628bffac96d3002308d1f9e1ed172
 */

int av_cold ff_celt_pvq_init(CeltPVQ **pvq, int encode)

{

    CeltPVQ *s = av_malloc(sizeof(CeltPVQ));

    if (!s)

        return AVERROR(ENOMEM);



    s->pvq_search = ppp_pvq_search_c;

    s->quant_band = encode ? pvq_encode_band : pvq_decode_band;

    s->band_cost  = pvq_band_cost;



    if (ARCH_X86)

        ff_opus_dsp_init_x86(s);



    *pvq = s;



    return 0;

}
