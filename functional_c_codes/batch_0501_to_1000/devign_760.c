/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_760
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e9016ee2bda1b7757072b856b2196f691aee3388
 */

void virtio_net_set_config_size(VirtIONet *n, uint32_t host_features)

{

    int i, config_size = 0;


    for (i = 0; feature_sizes[i].flags != 0; i++) {

        if (host_features & feature_sizes[i].flags) {

            config_size = MAX(feature_sizes[i].end, config_size);

        }

    }

    n->config_size = config_size;

}
