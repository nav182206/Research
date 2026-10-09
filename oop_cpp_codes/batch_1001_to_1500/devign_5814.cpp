/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5814
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b371539a3d9be9b05cb9ea8065e8e3617a45b02f
 */

static int mov_write_stbl_tag(ByteIOContext *pb, MOVTrack* track)

{

    offset_t pos = url_ftell(pb);

    put_be32(pb, 0); /* size */

    put_tag(pb, "stbl");

    mov_write_stsd_tag(pb, track);

    mov_write_stts_tag(pb, track);

    if (track->enc->codec_type == CODEC_TYPE_VIDEO &&

        track->hasKeyframes < track->entry)

        mov_write_stss_tag(pb, track);

    if (track->enc->codec_type == CODEC_TYPE_VIDEO &&

        track->hasBframes)

        mov_write_ctts_tag(pb, track);

    mov_write_stsc_tag(pb, track);

    mov_write_stsz_tag(pb, track);

    mov_write_stco_tag(pb, track);

    return updateSize(pb, pos);

}
