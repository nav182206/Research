/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6006
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eb89b4fc0994d682cd3f24b882164439c8c3af28
 */

static int device_open(AVFormatContext *ctx, uint32_t *capabilities)

{

    struct v4l2_capability cap;

    int fd;

    int res, err;

    int flags = O_RDWR;



    if (ctx->flags & AVFMT_FLAG_NONBLOCK) {

        flags |= O_NONBLOCK;

    }



    fd = open(ctx->filename, flags, 0);

    if (fd < 0) {

        av_log(ctx, AV_LOG_ERROR, "Cannot open video device %s : %s\n",

               ctx->filename, strerror(errno));



        return AVERROR(errno);

    }



    res = ioctl(fd, VIDIOC_QUERYCAP, &cap);

    // ENOIOCTLCMD definition only availble on __KERNEL__

    if (res < 0 && ((err = errno) == 515)) {

        av_log(ctx, AV_LOG_ERROR,

               "QUERYCAP not implemented, probably V4L device but "

               "not supporting V4L2\n");

        close(fd);



        return AVERROR(515);

    }



    if (res < 0) {

        av_log(ctx, AV_LOG_ERROR, "ioctl(VIDIOC_QUERYCAP): %s\n",

                 strerror(errno));

        close(fd);



        return AVERROR(err);

    }



    if ((cap.capabilities & V4L2_CAP_VIDEO_CAPTURE) == 0) {

        av_log(ctx, AV_LOG_ERROR, "Not a video capture device\n");

        close(fd);



        return AVERROR(ENODEV);

    }



    *capabilities = cap.capabilities;



    return fd;

}
