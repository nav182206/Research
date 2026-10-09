/* 
 * Benchmark Sample ID : devign_756
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9730280d54634caa5d63f0d8fcd85da8311d2ebf
 */

static void virtio_crypto_get_config(VirtIODevice *vdev, uint8_t *config)

{

    VirtIOCrypto *c = VIRTIO_CRYPTO(vdev);

    struct virtio_crypto_config crypto_cfg;



    /*

     * Virtio-crypto device conforms to VIRTIO 1.0 which is always LE,

     * so we can use LE accessors directly.

     */

    stl_le_p(&crypto_cfg.status, c->status);

    stl_le_p(&crypto_cfg.max_dataqueues, c->max_queues);

    stl_le_p(&crypto_cfg.crypto_services, c->conf.crypto_services);

    stl_le_p(&crypto_cfg.cipher_algo_l, c->conf.cipher_algo_l);

    stl_le_p(&crypto_cfg.cipher_algo_h, c->conf.cipher_algo_h);

    stl_le_p(&crypto_cfg.hash_algo, c->conf.hash_algo);

    stl_le_p(&crypto_cfg.mac_algo_l, c->conf.mac_algo_l);

    stl_le_p(&crypto_cfg.mac_algo_h, c->conf.mac_algo_h);

    stl_le_p(&crypto_cfg.aead_algo, c->conf.aead_algo);

    stl_le_p(&crypto_cfg.max_cipher_key_len, c->conf.max_cipher_key_len);

    stl_le_p(&crypto_cfg.max_auth_key_len, c->conf.max_auth_key_len);

    stq_le_p(&crypto_cfg.max_size, c->conf.max_size);



    memcpy(config, &crypto_cfg, c->config_size);

}
