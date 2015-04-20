#include "affair.h"


int main(int argc, char *argv[])
{
        struct page_buffer_s pbuf;
        struct file_s pfile;
        
        page_buffer_init(&pbuf);

        int ret = records_insert("aaa.dat", "bbb.dat",
                                 &pbuf, &pfile);
        return ret;
}
