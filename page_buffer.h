/*

 */
#ifndef __PAGE_BUFFER_H_
#define __PAGE_BUFFER_H_

#include "base.h"
#include "page_file.h"

/* field's structure */
struct field_s {
        int len;              /* length of field data */
        unsigned char *data;  /* data of field */
        struct field_s *next; /* next field */
};

/* record's structure */
struct record_s {
        int rid;         /* record identification */
        int num;         /* num of fields */

        /* list of fields */
        struct field_s *flist;
};


/* frame's structure */
struct frame_s {
        int pid;           /* page identification */
        int pin_count;     /* number of refernces */
        int dirty;         /* flag for modified */

        /* page data */
        unsigned char data[PAGE_SIZE];
};

/* switch queue's structure */
struct switch_queue_s {
        int head;    /* offset of queue header */
        int tail;    /* offset of queue tail */

        /* queue data */
        struct frame_s *frame[PAGE_NUM];
};

/* page buffer's structure */
struct page_buffer_s {
        struct frame_s pool[PAGE_NUM];  /* pools of buffer */
        struct switch_queue_s queue;      /* switch queue */
};

/* 
 Function: page_buffer_init
 Description:缓冲区初始化，pfub指向缓冲区；
 Return: 返回值不为零时说明发生错误; 
*/
int page_buffer_init(struct page_buffer_s *pbuf);

/* 
 Function: record_write
 Description:将记录插入到数据库，precd指向要写入的数据，并把记录id通过precd->rid返回；pfub和pfile分别指缓冲区和页表；
 Return: 返回值不为零时说明发生错误; 
*/
int records_write(struct record_s *precd,
                  struct page_buffer_s *pbuf,
                  struct file_s *pfile);

/* 
 Function: record_read
 Description:将precd->rid对应的记录从数据库中读取出来，pfub和pfile分别指缓冲区和页表；
 Return: 返回值不为零时说明发生错误; 
*/
int records_read(struct record_s *precd,
                 struct page_buffer_s *pbuf,
                 struct file_s *pfile);



#endif /* __PAGE_BUFFER_H_ */
