/* 
 * Benchmark Sample ID : devign_1784
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4e240985d8b856e62e4e0377283138cf51cc398e
 */

static int mov_read_udta(MOVContext *c, ByteIOContext *pb, MOV_atom_t atom)

{

    uint64_t end = url_ftell(pb) + atom.size;



    while (url_ftell(pb) + 8 < end) {

        uint32_t tag_size = get_be32(pb);

        uint32_t tag      = get_le32(pb);

        uint64_t next     = url_ftell(pb) + tag_size - 8;



        if (next > end) // stop if tag_size is wrong

            break;



        switch (tag) {

        case MKTAG(0xa9,'n','a','m'):

            mov_parse_udta_string(pb, c->fc->title,     sizeof(c->fc->title));

            break;

        case MKTAG(0xa9,'w','r','t'):

            mov_parse_udta_string(pb, c->fc->author,    sizeof(c->fc->author));

            break;

        case MKTAG(0xa9,'c','p','y'):

            mov_parse_udta_string(pb, c->fc->copyright, sizeof(c->fc->copyright));

            break;

        case MKTAG(0xa9,'i','n','f'):

            mov_parse_udta_string(pb, c->fc->comment,   sizeof(c->fc->comment));

            break;

        default:

            break;

        }



        url_fseek(pb, next, SEEK_SET);

    }



    return 0;

}
