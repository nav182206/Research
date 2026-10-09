/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4021
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1a6245a5b0b4e8d822c739b403fc67c8a7bc8d12
 */

static int nbd_receive_options(NBDClient *client)

{

    int csock = client->sock;

    uint32_t flags;



    /* Client sends:

        [ 0 ..   3]   client flags



        [ 0 ..   7]   NBD_OPTS_MAGIC

        [ 8 ..  11]   NBD option

        [12 ..  15]   Data length

        ...           Rest of request



        [ 0 ..   7]   NBD_OPTS_MAGIC

        [ 8 ..  11]   Second NBD option

        [12 ..  15]   Data length

        ...           Rest of request

    */



    if (read_sync(csock, &flags, sizeof(flags)) != sizeof(flags)) {

        LOG("read failed");

        return -EIO;

    }

    TRACE("Checking client flags");

    be32_to_cpus(&flags);

    if (flags != 0 && flags != NBD_FLAG_C_FIXED_NEWSTYLE) {

        LOG("Bad client flags received");

        return -EIO;

    }



    while (1) {

        int ret;

        uint32_t tmp, length;

        uint64_t magic;



        if (read_sync(csock, &magic, sizeof(magic)) != sizeof(magic)) {

            LOG("read failed");

            return -EINVAL;

        }

        TRACE("Checking opts magic");

        if (magic != be64_to_cpu(NBD_OPTS_MAGIC)) {

            LOG("Bad magic received");

            return -EINVAL;

        }



        if (read_sync(csock, &tmp, sizeof(tmp)) != sizeof(tmp)) {

            LOG("read failed");

            return -EINVAL;

        }



        if (read_sync(csock, &length, sizeof(length)) != sizeof(length)) {

            LOG("read failed");

            return -EINVAL;

        }

        length = be32_to_cpu(length);



        TRACE("Checking option");

        switch (be32_to_cpu(tmp)) {

        case NBD_OPT_LIST:

            ret = nbd_handle_list(client, length);

            if (ret < 0) {

                return ret;

            }

            break;



        case NBD_OPT_ABORT:

            return -EINVAL;



        case NBD_OPT_EXPORT_NAME:

            return nbd_handle_export_name(client, length);



        default:

            tmp = be32_to_cpu(tmp);

            LOG("Unsupported option 0x%x", tmp);

            nbd_send_rep(client->sock, NBD_REP_ERR_UNSUP, tmp);

            return -EINVAL;

        }

    }

}
