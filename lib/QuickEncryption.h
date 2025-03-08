/*
 * Copyright 2025 The QuickEncryption Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution
 */

// QuickEncryption.h
#ifndef QUICK_ENCRYPTION_H  
#define QUICK_ENCRYPTION_H

#include <Arduino.h>
#include <stdint.h>

#include "md2.h"
#include "md5.h"

#define MD2_INPUT_MAX 64
#define MD5_INPUT_MAX 64

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
      MD5_LOWERCASE_32L=1, MD5_UPPERCASE_32L, MD5_LOWERCASE_16L, MD5_UPPERCASE_16L
} QE_MD5_MODE;



String qe_MD2_str(String input,QE_MD2_MODE md2_mode);
int qe_MD2_char(char *input, char *output, size_t outputSize,QE_MD2_MODE md2_mode);
String qe_MD2(char *input,QE_MD2_MODE md2_mode);

String qe_MD5_str(String input,QE_MD5_MODE md5_mode);
int qe_MD5_char(char *input, char *output, size_t outputSize, QE_MD5_MODE md5_mode);
String qe_MD5(char *input,QE_MD5_MODE md5_mode);


#endif //QUICK_ENCRYPTION_H  