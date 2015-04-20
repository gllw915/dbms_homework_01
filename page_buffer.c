/*

 */
#include "page_buffer.h"
#include "base.h"
static int count = 0;

/* 
 Function: page_buffer_init
 Description:缓冲区初始化，pfub指向缓冲区；
 Return: 返回值不为零时说明发生错误; 
*/
int page_buffer_init(struct page_buffer_s *pbuf) {
        count = 0;
        return OK;
}

/* 
 Function: record_write
 Description:将记录插入到数据库，precd指向要写入的数据，并把记录id通过precd->rid返回；pfub和pfile分别指缓冲区和页表；
 Return: 返回值不为零时说明发生错误; 
*/
int records_write(struct record_s *precd,
                  struct page_buffer_s *pbuf,
                  struct file_s *pfile)
{
        count++;
        return count;
}

/* 
 Function: record_read
 Description:将precd->rid对应的记录从数据库中读取出来，pfub和pfile分别指缓冲区和页表；
 Return: 返回值不为零时说明发生错误; 
*/
int records_read(struct record_s *precd,
                 struct page_buffer_s *pbuf,
                 struct file_s *pfile)
{
        return OK;
}
