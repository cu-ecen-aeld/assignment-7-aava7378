#ifndef PROC_OPS_VERSION_H
#define PROC_OPS_VERSION_H

#include <linux/version.h>

/*
 * Linux 5.6 introduced struct proc_ops and renamed callbacks
 * (proc_read/proc_write/...), older kernels used file_operations.
 *
 * Map proc_ops -> file_operations for older kernels so code can use proc_ops.
 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5,6,0)
#define proc_ops file_operations
#define proc_open open
#define proc_read read
#define proc_write write
#define proc_lseek llseek
#define proc_release release
#define proc_poll poll
#endif

#endif /* PROC_OPS_VERSION_H */
