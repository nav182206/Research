/* 
 * Benchmark Sample ID : devign_3547
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=69d34a360dfe773e17e72c76d15931c9b9d190f6
 */

static off_t read_off(BlockDriverState *bs, int64_t offset)

{

	uint64_t buffer;

	if (bdrv_pread(bs->file, offset, &buffer, 8) < 8)

		return 0;

	return be64_to_cpu(buffer);

}
