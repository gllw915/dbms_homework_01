/*
  Implementation of Affair Layer
 */
#include <string.h>
#include "affair.h"

#define LINE_MAX_LEN     1024

/* insert field into record */
static int field_insert(struct record_s *r,
                        struct field_s *f);
static int record_insert(char *line,
                         struct page_buffer_s *pbuf,
                         struct file_s *pfile);
/*
  Function: records_insert 
  Description: Records in file "src" will be read 
  and logged into database. And rid of each record
  will be written into file "dst".
  Return: return ERROR while a fault occur; otherwise return OK
*/
int records_insert(char *src, char *dst,
                   struct page_buffer_s *pbuf, struct file_s *pfile)
{
        /* open file "src" */
        if (!src) {
#ifdef BUGGING
                printf("Error 1: No source file\n");
#endif /* BUGGING */
                return ERROR;
        }

        FILE *fpr = fopen(src, "r");
        if (!fpr) {
#ifdef BUGGING
                printf("Error2: Can't open %s, Code %d\n", src, errno);
#endif /* BUGGING */
                return ERROR;
        }

        /* open file "dst" */
        if (!dst) {
#ifdef BUGGING
                printf("Error 3: No destination file\n");
#endif /* BUGGING */
                fclose(fpr);
                return ERROR;
        }

        FILE *fpw = fopen(dst, "w");
        if (!fpw) {
#ifdef BUGGING
                printf("Error 4: Can't open %s, Code %d\n", dst, errno);
#endif /* BUGGING */
                fclose(fpr);
                return ERROR;
        }

        char line[LINE_MAX_LEN];
        while (fgets(line, LINE_MAX_LEN, fpr)) {
                int ret = record_insert(line, pbuf, pfile);
                if (ret) {
                        fprintf(fpw, "%04x\n", ret);
                }
        }
        fclose(fpr);
        fclose(fpw);
        return OK;
}

/*
  Function: record_insert
  Description: 
 */
static int record_insert(char *line,
                         struct page_buffer_s *pbuf,
                         struct file_s *pfile) {
        int len = 0;
        if (!line || !strlen(line)) {
                return 0;
        }

        char *ptr = NULL, *save_ptr = NULL;
        int flag = 0;
        struct record_s record;
        memset(&record, 0, sizeof(struct record_s));
        while(ptr = strtok_r(flag != 0?NULL:line,
                             "\t\n\r ", &save_ptr)) {
                flag = 1;
                len = strlen(ptr);
                struct field_s *field 
                        = (struct field_s *)calloc(1, sizeof(struct field_s));
                unsigned char *data 
                        = (unsigned char *)calloc(len, sizeof(unsigned char));
                memcpy(data, ptr, len);
                field->len = len;
                field->data = data;
                field_insert(&record, field);
        }
        
        int ret = records_write(&record, pbuf, pfile);
        
        /* field free */
        while(record.flist) {
                struct field_s *tmp = record.flist->next;
                free(record.flist->data);
                record.flist->next = NULL;
                free(record.flist);
                record.flist = tmp;
        }
        return ret;
}

/*
  Function: field_insert
  Description: insert field into record;
 */
static int field_insert(struct record_s *r,
                        struct field_s *f)
{
        struct field_s *tail = r->flist;
        while(tail && tail->next) {
                tail = tail->next;
        }

        if (!tail) {
                tail = f;
        } else {
                tail->next = f;
        }
        return OK;
}

/*
  Function: records_display
  Description: Records tagged by rids in file "src" will be read
  from database, then written into file "dst".
  Return: return ERROR while a fault occur; otherwise return OK
*/
int records_display(char *src, char *dst,
                    struct page_buffer_s *pbuf, struct file_s *pfile)
{
        return 0;
}
