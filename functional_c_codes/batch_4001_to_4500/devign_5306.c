/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5306
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=64a31d5c3d73396a88563d7a504654edc85aa854
 */

static off_t read_uint32(int fd, int64_t offset)

{

	uint32_t buffer;

	if (pread(fd, &buffer, 4, offset) < 4)

		return 0;

	return be32_to_cpu(buffer);

}
