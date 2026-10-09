/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5835
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fff39a7ad09da07ef490de05c92c91f22f8002f2
 */

static void v9fs_mkdir(void *opaque)
{
    V9fsPDU *pdu = opaque;
    size_t offset = 7;
    int32_t fid;
    struct stat stbuf;
    V9fsQID qid;
    V9fsString name;
    V9fsFidState *fidp;
    gid_t gid;
    int mode;
    int err = 0;
    v9fs_string_init(&name);
    err = pdu_unmarshal(pdu, offset, "dsdd", &fid, &name, &mode, &gid);
    if (err < 0) {
    trace_v9fs_mkdir(pdu->tag, pdu->id, fid, name.data, mode, gid);
    fidp = get_fid(pdu, fid);
    if (fidp == NULL) {
    err = v9fs_co_mkdir(pdu, fidp, &name, mode, fidp->uid, gid, &stbuf);
    if (err < 0) {
        goto out;
    stat_to_qid(&stbuf, &qid);
    err = pdu_marshal(pdu, offset, "Q", &qid);
    if (err < 0) {
        goto out;
    err += offset;
    trace_v9fs_mkdir_return(pdu->tag, pdu->id,
                            qid.type, qid.version, qid.path, err);
out:
    put_fid(pdu, fidp);
out_nofid:
    pdu_complete(pdu, err);
    v9fs_string_free(&name);
