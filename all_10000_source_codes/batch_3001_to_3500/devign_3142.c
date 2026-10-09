/* 
 * Benchmark Sample ID : devign_3142
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5c2fb561d94fc51d76ab21d6f7cc5b6cc3aa599c
 */

static int get_last_needed_nal(H264Context *h)

{

    int nals_needed = 0;

    int i;



    for (i = 0; i < h->pkt.nb_nals; i++) {

        H2645NAL *nal = &h->pkt.nals[i];

        GetBitContext gb;



        /* packets can sometimes contain multiple PPS/SPS,

         * e.g. two PAFF field pictures in one packet, or a demuxer

         * which splits NALs strangely if so, when frame threading we

         * can't start the next thread until we've read all of them */

        switch (nal->type) {

        case NAL_SPS:

        case NAL_PPS:

            nals_needed = i;

            break;

        case NAL_DPA:

        case NAL_IDR_SLICE:

        case NAL_SLICE:

            init_get_bits(&gb, nal->data + 1, (nal->size - 1) * 8);

            if (!get_ue_golomb(&gb))

                nals_needed = i;

        }

    }



    return nals_needed;

}
