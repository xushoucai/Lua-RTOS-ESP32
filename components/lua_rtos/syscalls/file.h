#ifndef __FILE_H
#define __FILE_H

#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/stat.h>

#include <sys/queue.h>

#define FFLAGS(oflags)  ((oflags) + 1)
#define OFLAGS(fflags)  ((fflags) - 1)

#ifndef FFSYNC
#define FFSYNC FSYNC
#endif

#ifndef FNONBLOCK
#define FNONBLOCK FNONBIO
#endif

#ifndef FIONBIO
#define FIONBIO FNONBIO
#endif

#define FMASK       (FREAD|FWRITE|FAPPEND|FASYNC|FFSYNC|FNONBLOCK)
#define FCNTLFLAGS  (FAPPEND|FASYNC|FFSYNC|FNONBLOCK)

struct file {
	LIST_ENTRY(file) f_list; /* list of active files */
    short   f_count;         /* reference count */
    caddr_t f_data;          /* vnode or socket */
    short   f_flag;          /* see fcntl.h */
    void   *f_fs;			 /* this is a reference to the file system's file struct that this file refers */
    char   *f_path;          /* this is the path of the opended file */
    void   *f_dir;			 /* this is a reference to the file systems's dir struct that this file refers */
    int     f_fd;
    int     f_fs_type;       /* type of files ystem */
    int     unit;            /* if file is linked to a device driver, this is the unit number */
};

LIST_HEAD(filelist, file);
extern struct filelist filehead;    /* head of list of open files */

#endif
