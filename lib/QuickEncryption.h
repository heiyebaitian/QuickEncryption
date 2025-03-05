// QuickEncryption.h
#ifndef QUICK_ENCRYPTION_H  
#define QUICK_ENCRYPTION_H

#include <Arduino.h>
#include <stdint.h>

#include "md5.h"

typedef enum
{
      LOWERCASE_32L=1, UPPERCASE_32L, LOWERCASE_16L, UPPERCASE_16L
} MD5_MODE;


String qe_md5(char *input,MD5_MODE md5_mode);


#endif //QUICK_ENCRYPTION_H  