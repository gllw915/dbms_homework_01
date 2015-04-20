/*

*/
#ifndef __PAGE_FILE_H_
#define __PAGE_FILE_H_

#include "base.h"

/* 页结构 */
struct page_s {
        int rid;          /* 记录号 */
        int status;        /* 状态 */
        int offset;        /* 页偏移量 */
        int size;         /* 剩余空间 */

        /* next and prev */
        struct page_s    *next;    /* 下一项 */
        struct page_s    *prev;    /* 上一项 */
};

/* 文件结构 */
struct file_s {
        char name[256];
        struct page_s    *pages;        /* 页表 */
        struct page_s    *idle_pages;    /* 空闲页表 */

        /* 页缓存 */
        unsigned char data[PAGE_SIZE];
};


#endif /* __PAGE_FILE_H_ */
