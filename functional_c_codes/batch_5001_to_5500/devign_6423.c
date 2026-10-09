/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6423
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=abd696e4f74a9d30801c6ae2693efe4e5979c2f2
 */

void virtio_setup_block(struct subchannel_id schid)

{

    struct vq_info_block info;

    struct vq_config_block config = {};



    virtio_reset(schid);



    config.index = 0;

    if (run_ccw(schid, CCW_CMD_READ_VQ_CONF, &config, sizeof(config))) {

        virtio_panic("Could not get block device configuration\n");

    }

    vring_init(&block, config.num, (void*)(100 * 1024 * 1024),

               KVM_S390_VIRTIO_RING_ALIGN);



    info.queue = (100ULL * 1024ULL* 1024ULL);

    info.align = KVM_S390_VIRTIO_RING_ALIGN;

    info.index = 0;

    info.num = config.num;

    block.schid = schid;



    if (!run_ccw(schid, CCW_CMD_SET_VQ, &info, sizeof(info))) {

        virtio_set_status(schid, VIRTIO_CONFIG_S_DRIVER_OK);

    }

}
