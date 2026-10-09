/* 
 * Benchmark Sample ID : devign_9622
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=82e59a676c01b3df3b53998d428d0a64a55f2439
 */

void qmp_memchar_write(const char *device, int64_t size,

                       const char *data, bool has_format,

                       enum DataFormat format,

                       Error **errp)

{

    CharDriverState *chr;

    guchar *write_data;

    int ret;

    gsize write_count;



    chr = qemu_chr_find(device);

    if (!chr) {

        error_set(errp, QERR_DEVICE_NOT_FOUND, device);

        return;

    }



    if (qemu_is_chr(chr, "memory")) {

        error_setg(errp,"%s is not memory char device", device);

        return;

    }



    write_count = (gsize)size;



    if (has_format && (format == DATA_FORMAT_BASE64)) {

        write_data = g_base64_decode(data, &write_count);

    } else {

        write_data = (uint8_t *)data;

    }



    ret = cirmem_chr_write(chr, write_data, write_count);



    if (ret < 0) {

        error_setg(errp, "Failed to write to device %s", device);

        return;

    }

}
