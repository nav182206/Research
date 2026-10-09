/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9982
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d83c951cce14dd3c7600c386d3791c4993744622
 */

static int ata_passthrough_16_xfer_size(SCSIDevice *dev, uint8_t *buf)

{

    int extend = buf[1] & 0x1;

    int length = buf[2] & 0x3;

    int xfer;

    int unit = ata_passthrough_xfer_unit(dev, buf);



    switch (length) {

    case 0:

    case 3: /* USB-specific.  */


        xfer = 0;

        break;

    case 1:

        xfer = buf[4];

        xfer |= (extend ? buf[3] << 8 : 0);

        break;

    case 2:

        xfer = buf[6];

        xfer |= (extend ? buf[5] << 8 : 0);

        break;

    }



    return xfer * unit;

}
