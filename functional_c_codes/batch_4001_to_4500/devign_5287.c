/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5287
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b49ae9138d5cadb47fb868297fbcdac8292fb666
 */

void vhost_net_ack_features(struct vhost_net *net, unsigned features)

{


    vhost_ack_features(&net->dev, vhost_net_get_feature_bits(net), features);

}
