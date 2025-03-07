// QuickEncryption.h
#ifndef QUICK_ENCRYPTION_H  
#define QUICK_ENCRYPTION_H

#include <Arduino.h>
#include <stdint.h>

#include "md2.h"
#include "md5.h"


typedef enum
{
      MD2_LOWERCASE_32L=1, MD2_UPPERCASE_32L, MD2_LOWERCASE_16L, MD2_UPPERCASE_16L
} MD2_MODE;

typedef enum
{
      MD5_LOWERCASE_32L=1, MD5_UPPERCASE_32L, MD5_LOWERCASE_16L, MD5_UPPERCASE_16L
} MD5_MODE;


String qe_MD2(char *input,MD2_MODE md2_mode);
String qe_md5(char *input,MD5_MODE md5_mode);


#endif //QUICK_ENCRYPTION_H  