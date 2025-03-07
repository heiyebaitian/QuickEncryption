#include <string.h>
#include <Arduino.h>
#include "func.h"


typedef void *(*memset_t)(void *, int, size_t);

static volatile memset_t memset_func = memset;

void qe_cleanse(void *ptr, size_t len)
{
    memset_func(ptr, 0, len);
}