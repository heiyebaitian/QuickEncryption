/*
 * Copyright 2025 The QuickEncryption Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution
 */

// QuickEncryption.h
#ifndef __QUICK_ENCRYPTION__H  
#define __QUICK_ENCRYPTION__H
#pragma once

#define QE_HWA_METHOD 1

#include <Arduino.h>
#include <stdint.h>

#include "md2.h"
#include "md4.h"
#include "sha256.h"



/* MD5计算加速优化
 * 现已支持:
 *  - ESP32系列:ESP32S3 | ESP32S2 | ESP32C3
 */
#if (CONFIG_IDF_TARGET_ESP32C3 || CONFIG_IDF_TARGET_ESP32S3 || CONFIG_IDF_TARGET_ESP32S2) && QE_HWA_METHOD == 1
  // 如果目标平台是 ESP32
  #warning You have enabled the ESP32-specific MD5 method. Please confirm that you are aware of the consequences of enabling this feature.
  #include "MD5Builder.h"
#else
  //使用默认方法
  #include "md5.h"

#endif

/* SHA1计算加速优化
 * 现已支持:
 *  - RP系列:RP2040 | RP2350A/B
 */
#if (PICO_RP2040 || PICO_RP2350 || PICO_RP2350A || PICO_RP2350B) && QE_HWA_METHOD == 1
  // 如果目标平台是 RP
  #warning You have enabled the RP-specific SHA1 method. Please confirm that you are aware of the consequences of enabling this feature.
  #include <Hash.h>
#else
  //使用默认方法
  #include "sha1.h"
#endif



#define MD2_INPUT_MAX 64
#define MD4_INPUT_MAX 64
#define MD5_INPUT_MAX 64
#define SHA1_INPUT_MAX 64
#define SHA256_INPUT_MAX 64



typedef enum
{
      NORMAL=0, ERROR_NULL, ERROR_MISCALCULATION, ERROR_ARRAY_LENGTH
} QE_RETURN_STATE;

typedef enum
{
      MD2_LOWERCASE_32L=1, MD2_UPPERCASE_32L, MD2_LOWERCASE_16L, MD2_UPPERCASE_16L
} QE_MD2_MODE;

typedef enum
{
      MD4_LOWERCASE_32L=1, MD4_UPPERCASE_32L, MD4_LOWERCASE_16L, MD4_UPPERCASE_16L
} QE_MD4_MODE;

typedef enum
{
      MD5_LOWERCASE_32L=1, MD5_UPPERCASE_32L, MD5_LOWERCASE_16L, MD5_UPPERCASE_16L
} QE_MD5_MODE;

typedef enum
{
      SHA1_LOWERCASE=1, SHA1_UPPERCASE
} QE_SHA1_MODE;

typedef enum
{
      SHA256_LOWERCASE=1, SHA256_UPPERCASE
} QE_SHA256_MODE;


String qe_MD2(char *input,QE_MD2_MODE md2_mode);
String qe_MD2_str(String input,QE_MD2_MODE md2_mode);
int qe_MD2_char(char *input, char *output, size_t outputSize,QE_MD2_MODE md2_mode);

String qe_MD4(char *input,QE_MD4_MODE md4_mode);
String qe_MD4_str(String input, QE_MD4_MODE md4_mode);
int qe_MD4_char(char *input, char *output, size_t outputSize,QE_MD4_MODE MD4_mode);

String qe_MD5(char *input,QE_MD5_MODE md5_mode);
String qe_MD5_str(String input,QE_MD5_MODE md5_mode);
int qe_MD5_char(char *input, char *output, size_t outputSize, QE_MD5_MODE md5_mode);

String qe_SHA1(char *input,QE_SHA1_MODE sha1_mode);
String qe_SHA1_str(String input, QE_SHA1_MODE sha1_mode);
int qe_SHA1_char(char *input, char *output, size_t outputSize,QE_SHA1_MODE sha1_mode);

String qe_SHA256(char *input, QE_SHA256_MODE sha256_mode);
String qe_SHA256_str(String input, QE_SHA256_MODE sha256_mode);
int qe_SHA256_char(char *input, char *output, size_t outputSize,QE_SHA256_MODE sha256_mode);

#endif //QUICK_ENCRYPTION_H  