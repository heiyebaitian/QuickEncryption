/*
 * Copyright 2025 The QuickEncryption Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution
 */

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

