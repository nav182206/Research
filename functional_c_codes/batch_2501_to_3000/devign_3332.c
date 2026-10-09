/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3332
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bb12e761e8e7b5c3c3d77bd08de9f007727a941e
 */

int vhost_set_vring_enable(NetClientState *nc, int enable)

{

    VHostNetState *net = get_vhost_net(nc);

    const VhostOps *vhost_ops;



    nc->vring_enable = enable;



    if (!net) {

        return 0;

    }



    vhost_ops = net->dev.vhost_ops;

    if (vhost_ops->vhost_set_vring_enable) {

        return vhost_ops->vhost_set_vring_enable(&net->dev, enable);

    }



    return 0;

}
