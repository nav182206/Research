/* 
 * Benchmark Sample ID : devign_8159
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=113fe792fd4931dd0538f03859278b8719ee4fa2
 */

static void nfs_file_close(BlockDriverState *bs)

{

    NFSClient *client = bs->opaque;

    nfs_client_close(client);

    qemu_mutex_destroy(&client->mutex);

}
