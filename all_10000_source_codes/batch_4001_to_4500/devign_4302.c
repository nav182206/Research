/* 
 * Benchmark Sample ID : devign_4302
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=563890c7c7e977842e2a35afe7a24d06d2103242
 */

static void test_media_insert(void)

{

    uint8_t dir;



    /* Insert media in drive. DSKCHK should not be reset until a step pulse

     * is sent. */

    qmp_discard_response("{'execute':'change', 'arguments':{"

                         " 'device':'floppy0', 'target': '%s' }}",

                         test_image);

    qmp_discard_response(""); /* ignore event

                                 (FIXME open -> open transition?!) */

    qmp_discard_response(""); /* ignore event */



    dir = inb(FLOPPY_BASE + reg_dir);

    assert_bit_set(dir, DSKCHG);

    dir = inb(FLOPPY_BASE + reg_dir);

    assert_bit_set(dir, DSKCHG);



    send_seek(0);

    dir = inb(FLOPPY_BASE + reg_dir);

    assert_bit_set(dir, DSKCHG);

    dir = inb(FLOPPY_BASE + reg_dir);

    assert_bit_set(dir, DSKCHG);



    /* Step to next track should clear DSKCHG bit. */

    send_seek(1);

    dir = inb(FLOPPY_BASE + reg_dir);

    assert_bit_clear(dir, DSKCHG);

    dir = inb(FLOPPY_BASE + reg_dir);

    assert_bit_clear(dir, DSKCHG);

}
