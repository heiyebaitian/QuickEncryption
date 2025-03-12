/*
 * Copyright 2025 The QuickEncryption Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution
 */

#ifndef __QE_FUNC__H
#define __QE_FUNC__H
#pragma once


void qe_cleanse(void *ptr, size_t len);

uint32_t le32toh(uint32_t val);
uint32_t be32toh(uint32_t val);
uint32_t htole32(uint32_t val);
uint32_t htobe32(uint32_t val);
bool isLittleEndian();

#endif
