#include <string.h>
#include <Arduino.h>
#include "func.h"


typedef void *(*memset_t)(void *, int, size_t);

static volatile memset_t memset_func = memset;

/* 安全擦除内存
 * @param *ptr 擦除区域
 * @param len  区域大小
 */
void qe_cleanse(void *ptr, size_t len)
{
    memset_func(ptr, 0, len);
}