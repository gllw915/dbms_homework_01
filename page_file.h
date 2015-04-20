/*

*/
#ifndef __PAGE_FILE_H_
#define __PAGE_FILE_H_

#include "base.h"

/* ҳ�ṹ */
struct page_s {
        int rid;          /* ��¼�� */
        int status;        /* ״̬ */
        int offset;        /* ҳƫ���� */
        int size;         /* ʣ��ռ� */

        /* next and prev */
        struct page_s    *next;    /* ��һ�� */
        struct page_s    *prev;    /* ��һ�� */
};

/* �ļ��ṹ */
struct file_s {
        char name[256];
        struct page_s    *pages;        /* ҳ�� */
        struct page_s    *idle_pages;    /* ����ҳ�� */

        /* ҳ���� */
        unsigned char data[PAGE_SIZE];
};


#endif /* __PAGE_FILE_H_ */
