/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9071
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2c00b373024054e0779ef67fc54b763d624db3e8
 */

int av_packet_unpack_dictionary(const uint8_t *data, int size, AVDictionary **dict)

{

    const uint8_t *end = data + size;

    int ret = 0;



    if (!dict || !data || !size)

        return ret;

    if (size && end[-1])

        return AVERROR_INVALIDDATA;

    while (data < end) {

        const uint8_t *key = data;

        const uint8_t *val = data + strlen(key) + 1;



        if (val >= end)

            return AVERROR_INVALIDDATA;



        ret = av_dict_set(dict, key, val, 0);

        if (ret < 0)

            break;

        data = val + strlen(val) + 1;

    }



    return ret;

}
