#ifndef HITCHHIKE_H
#define HITCHHIKE_H

#include <libaio.h>
#include <stdint.h>

#define __NR_io_submit_hit 452

#define HIT_MAX 126
struct hitchhiker {
	uint32_t max;
	uint32_t in_use;
	uint32_t size;
	uint32_t iov_use;
	uint64_t addr[127];
   	uint64_t iov[127];
};

static int io_submit_hit(io_context_t ctx, long nr, struct iocb **iocbpp, 
                                    struct hitchhiker **hit_bufs) {
    return syscall(__NR_io_submit_hit, ctx, nr, iocbpp, hit_bufs);
}

#endif