/*
  Implementation of Affair Layer.
 */
#ifndef __AFFAIR_H_
#define __AFFAIR_H_

#include "base.h"
#include "page_buffer.h"

/* 
   Records in file "src" will be read and logged into database.
   And rid of each record will be written into file "dst".
 */
int records_insert(char *src, char *dst,
                   struct page_buffer_s *pbuf, struct file_s *pfile);

/*
  Records tagged by rids in file "src" will be read from database, then 
  written into file "dst".
 */
int records_display(char *src, char *dst,
                    struct page_buffer_s *pbuf, struct file_s *pfile);

#endif /* __AFFAIR_H_ */
