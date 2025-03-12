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



/* 数据转小端
 * @param val 输入值
 * @return 输出结果
 */
uint32_t le32toh(uint32_t val) {
  if(isLittleEndian()) {
    return val; // 如果是小端模式，则直接返回
  } else {
    // 大端模式下，反转字节序
    return ((val & 0xFF000000) >> 24) |
           ((val & 0x00FF0000) >> 8)  |
           ((val & 0x0000FF00) << 8)  |
           ((val & 0x000000FF) << 24);
  }
}

/* 数据转大端
 * @param val 输入值
 * @return 输出结果
 */
uint32_t be32toh(uint32_t val) {
  if(!isLittleEndian()) {
    return val; // 如果是大端模式，则直接返回
  } else {
    // 小端模式下，反转字节序
    return ((val & 0xFF000000) >> 24) |
           ((val & 0x00FF0000) >> 8)  |
           ((val & 0x0000FF00) << 8)  |
           ((val & 0x000000FF) << 24);
  }
}

/* 转换为主机字节序到小端字节序
 * @param val 输入值
 * @return 输出结果
 */
uint32_t htole32(uint32_t val) {
  // 转换为主机字节序到小端字节序
  return le32toh(val);
}

/* 转换为主机字节序到大端字节序
 * @param val 输入值
 * @return 输出结果
 */
uint32_t htobe32(uint32_t val) {
  // 转换为主机字节序到大端字节序
  return be32toh(val);
}


/* 大小端检测
 * @return 输出结果
 */
bool isLittleEndian() {
    // 使用联合体允许以不同方式解释同一块内存
    union {
        uint32_t value;  // 作为32位无符号整数访问
        uint8_t data[sizeof(uint32_t)];  // 作为字节数组访问
    } test = {0x01020304};  // 初始化为一个容易识别的值

    // 如果最低地址的字节是0x04，则表示系统是小端字节序
    return test.data[0] == 0x04;
}
