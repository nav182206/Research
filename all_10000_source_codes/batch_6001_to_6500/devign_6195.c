/* 
 * Benchmark Sample ID : devign_6195
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=30c367ed446b6ea53245589a5cf373578ac075d7
 */

static int parse_netdev(DeviceState *dev, const char *str, void **ptr)
{
    NICPeers *peers_ptr = (NICPeers *)ptr;
    NICConf *conf = container_of(peers_ptr, NICConf, peers);
    NetClientState **ncs = peers_ptr->ncs;
    NetClientState *peers[MAX_QUEUE_NUM];
    int queues, i = 0;
    int ret;
    queues = qemu_find_net_clients_except(str, peers,
                                          NET_CLIENT_OPTIONS_KIND_NIC,
                                          MAX_QUEUE_NUM);
    if (queues == 0) {
        ret = -ENOENT;
    if (queues > MAX_QUEUE_NUM) {
        ret = -E2BIG;
    for (i = 0; i < queues; i++) {
        if (peers[i] == NULL) {
            ret = -ENOENT;
        if (peers[i]->peer) {
            ret = -EEXIST;
        ncs[i] = peers[i];
        ncs[i]->queue_index = i;
    conf->queues = queues;
    return 0;
err:
    return ret;
