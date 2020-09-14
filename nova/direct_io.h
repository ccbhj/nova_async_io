#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/aio.h>
#include <linux/bitmap.h>
#include <linux/mm.h>
#include <linux/uio.h>
/*file.c*/
extern ssize_t nova_wrap_rw_iter(struct kiocb *iocb, struct iov_iter *iter);

/* direct_io.c */
ssize_t do_nova_inplace_file_write_async(struct file *filp, struct page **kaddr,
    size_t len, loff_t ppos);

ssize_t nova_dax_file_write_async(struct file *filp, struct page **kaddr,
                                  size_t len, loff_t ppos);
ssize_t nova_dax_file_read_async(struct file *filp, struct page **kaddr,
                                 size_t len, loff_t ppos);
ssize_t nova_direct_IO(struct kiocb *iocb, struct iov_iter *iter);

static void queue_wait_work(struct nova_inode_info *ino_info);
int sb_init_wq(struct super_block *sb);
void nova_async_work(struct work_struct *p_work);
