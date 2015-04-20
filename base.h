/* 
   Global Definition
 */
#ifndef __BASE_H_
#define __BASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUGGING

#ifndef OK
#define OK       0
#define ERROR   -1
#endif /* OK */

/* page's size */
#ifndef PAGE_SIZE
#define PAGE_SIZE    (8 * 1024)
#endif /* PAGE_SIZE */

/* page buffer's number */
#ifndef PAGE_NUM
#define PAGE_NUM   10
#endif /*PAGE_NUM*/

#endif /* __BASE_H_ */
