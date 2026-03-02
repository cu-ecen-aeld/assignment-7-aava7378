#ifndef ACCESS_OK_VERSION_H
#define ACCESS_OK_VERSION_H

#include <linux/version.h>
#include <linux/uaccess.h>

#ifndef VERIFY_READ
#define VERIFY_READ  0
#endif
#ifndef VERIFY_WRITE
#define VERIFY_WRITE 1
#endif

/*
 * access_ok() signature changed across kernel versions.
 *
 * Older kernels: access_ok(type, addr, size) with VERIFY_{READ,WRITE}
 * Newer kernels: access_ok(addr, size) (type removed)
 *
 * This wrapper keeps the scull code unchanged.
 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5,0,0)
static inline int access_ok_wrapper(int type, const void __user *addr,
                                    unsigned long size)
{
    return access_ok(type, addr, size);
}
#else
static inline int access_ok_wrapper(int type, const void __user *addr,
                                    unsigned long size)
{
    (void)type;
    return access_ok(addr, size);
}
#endif

#endif /* ACCESS_OK_VERSION_H */
