/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6747
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e86d90352adf6cb08295255220295cf23c4286e
 */

static void sdhci_data_transfer(void *opaque)

{

    SDHCIState *s = (SDHCIState *)opaque;



    if (s->trnmod & SDHC_TRNS_DMA) {

        switch (SDHC_DMA_TYPE(s->hostctl)) {

        case SDHC_CTRL_SDMA:

            if ((s->trnmod & SDHC_TRNS_MULTI) &&

                    (!(s->trnmod & SDHC_TRNS_BLK_CNT_EN) || s->blkcnt == 0)) {

                break;

            }



            if ((s->blkcnt == 1) || !(s->trnmod & SDHC_TRNS_MULTI)) {

                sdhci_sdma_transfer_single_block(s);

            } else {

                sdhci_sdma_transfer_multi_blocks(s);

            }



            break;

        case SDHC_CTRL_ADMA1_32:

            if (!(s->capareg & SDHC_CAN_DO_ADMA1)) {

                ERRPRINT("ADMA1 not supported\n");

                break;

            }



            sdhci_do_adma(s);

            break;

        case SDHC_CTRL_ADMA2_32:

            if (!(s->capareg & SDHC_CAN_DO_ADMA2)) {

                ERRPRINT("ADMA2 not supported\n");

                break;

            }



            sdhci_do_adma(s);

            break;

        case SDHC_CTRL_ADMA2_64:

            if (!(s->capareg & SDHC_CAN_DO_ADMA2) ||

                    !(s->capareg & SDHC_64_BIT_BUS_SUPPORT)) {

                ERRPRINT("64 bit ADMA not supported\n");

                break;

            }



            sdhci_do_adma(s);

            break;

        default:

            ERRPRINT("Unsupported DMA type\n");

            break;

        }

    } else {

        if ((s->trnmod & SDHC_TRNS_READ) && sdbus_data_ready(&s->sdbus)) {

            s->prnsts |= SDHC_DOING_READ | SDHC_DATA_INHIBIT |

                    SDHC_DAT_LINE_ACTIVE;

            sdhci_read_block_from_card(s);

        } else {

            s->prnsts |= SDHC_DOING_WRITE | SDHC_DAT_LINE_ACTIVE |

                    SDHC_SPACE_AVAILABLE | SDHC_DATA_INHIBIT;

            sdhci_write_block_to_card(s);

        }

    }

}
