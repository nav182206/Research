/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_181
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=64a31d5c3d73396a88563d7a504654edc85aa854
 */

static off_t read_off(int fd, int64_t offset)

{

	uint64_t buffer;

	if (pread(fd, &buffer, 8, offset) < 8)

		return 0;

	return be64_to_cpu(buffer);

}
