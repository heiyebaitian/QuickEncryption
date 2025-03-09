/*
 * Copyright 2025 The QuickEncryption Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution
 */

#include "QuickEncryption.h"

/* MD2计算函数 String输入输出
 * @param input 待计算的数据
 * @param md2_mode MD2输出模式，可选大小写模式，16/32长度模式
 * @return MD2String 计算结果,如发生错误则输出"ERROR",如计算失败则输出"NULL"
 */
String qe_MD2_str(String input, QE_MD2_MODE md2_mode){
  if(input.length() > MD2_INPUT_MAX) return "ERROR"; // 如果传入字符串超过最大输入上限则返回

  unsigned char md2[16];
  char input_char[MD2_INPUT_MAX  + 1]= {};

  input.toCharArray(input_char, input.length() + 1);  // 将输入数据String类型转换为char类型
  MD2((unsigned char *)input_char,strlen(input_char),md2);  // 计算MD2

  // 将输出结果转换为16进制字符串
  String MD2String = "";
  for (int i = 0; i < 16; i++) {
    if (md2[i] < 0x10) {
      MD2String += "0"; // 如果是单个十六进制数字，前面加0
    }
    MD2String += String(md2[i], HEX); // 将每个字节转换为两位十六进制数并追加到字符串
  }

  // 输出模式处理
  if(md2_mode == MD2_LOWERCASE_32L)
  {
    return MD2String;
  }

  if(md2_mode == MD2_UPPERCASE_32L)
  {
    MD2String.toUpperCase();
    return MD2String;
  }

  if(md2_mode == MD2_LOWERCASE_16L)
  {
    if (MD2String.length() != 32) {return "ERROR";}
    MD2String = MD2String.substring(8, 24);
    return MD2String;
  }

  if(md2_mode == MD2_UPPERCASE_16L)
  {
    if (MD2String.length() != 32) {return "ERROR";}
    MD2String = MD2String.substring(8, 24);
    MD2String.toUpperCase();
    return MD2String;
  }
  else return "NULL";
}

/* MD2计算函数 char输入输出
 * @param input 待计算的数据
 * @param output 输出的目标数组
 * @param outputSize 输出的目标数组的大小
 * @param md2_mode MD2输出模式，可选大小写模式，16/32长度模式
 * @return QE_RETURN_STATE 函数处理状态
 */
int qe_MD2_char(char *input, char *output, size_t outputSize,QE_MD2_MODE md2_mode){
  unsigned char md2[16];
  MD2((unsigned char *)input,strlen(input),md2);  // MD2计算
  String MD2String = "";

  // 将输出结果转换为16进制字符串
  for (int i = 0; i < 16; i++) {
    if (md2[i] < 0x10) {
      MD2String += "0"; // 如果是单个十六进制数字，前面加0
    }
    MD2String += String(md2[i], HEX); // 将每个字节转换为两位十六进制数并追加到字符串
  }

  // 输出模式处理
  if(md2_mode == MD2_LOWERCASE_32L)
  {
    if(outputSize < 33) return ERROR_ARRAY_LENGTH; // 输出数组大小不满足
    MD2String.toCharArray(output, MD2String.length() + 1); 
    return NORMAL;
  }

  if(md2_mode == MD2_UPPERCASE_32L)
  {
    MD2String.toUpperCase();
    if(outputSize < 33) return ERROR_ARRAY_LENGTH; // 输出数组大小不满足
    MD2String.toCharArray(output, MD2String.length() + 1); 
    return NORMAL;
  }

  if(md2_mode == MD2_LOWERCASE_16L)
  {
    if (MD2String.length() != 32) {return ERROR_MISCALCULATION;}
    MD2String = MD2String.substring(8, 24);
    if(outputSize < 17) return ERROR_ARRAY_LENGTH; // 输出数组大小不满足
    MD2String.toCharArray(output, MD2String.length() + 1); 
    return NORMAL;
  }

  if(md2_mode == MD2_UPPERCASE_16L)
  {
    if (MD2String.length() != 32) {return ERROR_MISCALCULATION;}
    MD2String = MD2String.substring(8, 24);
    MD2String.toUpperCase();
    if(outputSize < 17) return ERROR_ARRAY_LENGTH; // 输出数组大小不满足
    MD2String.toCharArray(output, MD2String.length() + 1); 
    return NORMAL;
  }

  else return ERROR_NULL;
}


/* MD2计算函数
 * @param input 待计算的数据
 * @param md2_mode MD2输出模式，可选大小写模式，16/32长度模式
 * @return MD2String 计算结果,如发生错误则输出"ERROR",如计算失败则输出"NULL"
 */
String qe_MD2(char *input,QE_MD2_MODE md2_mode){
  unsigned char md2[16];
  MD2((unsigned char *)input,strlen(input),md2);

  // 将输出结果转换为16进制字符串
  String MD2String = "";
  for (int i = 0; i < 16; i++) {
    if (md2[i] < 0x10) {
      MD2String += "0"; // 如果是单个十六进制数字，前面加0
    }
    MD2String += String(md2[i], HEX); // 将每个字节转换为两位十六进制数并追加到字符串
  }

  // 输出模式处理
  if(md2_mode == MD2_LOWERCASE_32L)
  {
    return MD2String;
  }

  if(md2_mode == MD2_UPPERCASE_32L)
  {
    MD2String.toUpperCase();
    return MD2String;
  }

  if(md2_mode == MD2_LOWERCASE_16L)
  {
    if (MD2String.length() != 32) {return "ERROR";}
    MD2String = MD2String.substring(8, 24);
    return MD2String;
  }

  if(md2_mode == MD2_UPPERCASE_16L)
  {
    if (MD2String.length() != 32) {return "ERROR";}
    MD2String = MD2String.substring(8, 24);
    MD2String.toUpperCase();
    return MD2String;
  }
  else return "NULL";
}



/* MD4计算函数
 * @param input 待计算的数据
 * @param md4_mode MD4输出模式，可选大小写模式，16/32长度模式
 * @return MD4String 计算结果,如发生错误则输出"ERROR",如计算失败则输出"NULL"
 */
String qe_MD4(char *input,QE_MD4_MODE md4_mode){
  unsigned char md4[16];
  MD4((unsigned char *)input,strlen(input),md4);

  // 将输出结果转换为16进制字符串
  String MD4String = "";
  for (int i = 0; i < 16; i++) {
    if (md4[i] < 0x10) {
      MD4String += "0"; // 如果是单个十六进制数字，前面加0
    }
    MD4String += String(md4[i], HEX); // 将每个字节转换为两位十六进制数并追加到字符串
  }

  // 输出模式处理
  if(md4_mode == MD4_LOWERCASE_32L)
  {
    return MD4String;
  }

  if(md4_mode == MD4_UPPERCASE_32L)
  {
    MD4String.toUpperCase();
    return MD4String;
  }

  if(md4_mode == MD4_LOWERCASE_16L)
  {
    if (MD4String.length() != 32) {return "ERROR";}
    MD4String = MD4String.substring(8, 24);
    return MD4String;
  }

  if(md4_mode == MD4_UPPERCASE_16L)
  {
    if (MD4String.length() != 32) {return "ERROR";}
    MD4String = MD4String.substring(8, 24);
    MD4String.toUpperCase();
    return MD4String;
  }
  else return "NULL";
}



/* MD5计算函数 String输入输出
 * @param input 待计算的数据
 * @param md5_mode MD5输出模式，可选大小写模式，16/32长度模式
 * @return MD5String 计算结果,如发生错误则输出"ERROR",如计算失败则输出"NULL"
 */
String qe_MD5_str(String input,QE_MD5_MODE md5_mode)
{
  if(input.length() > MD5_INPUT_MAX) return "ERROR"; // 如果传入字符串超过最大输入上限则返回
  MD5_CTX md5_calc;
  unsigned char md5[16];
  char input_char[MD5_INPUT_MAX  + 1]= {};

  input.toCharArray(input_char, input.length() + 1);  // 将输入数据String类型转换为char类型
  // 计算MD5
  MD5_Init(&md5_calc);
	MD5_Update(&md5_calc,(unsigned char *)input_char,strlen(input_char));
	MD5_Final(md5,&md5_calc);
  
  // 将输出结果转换为16进制字符串
  String MD5String = "";
  for (int i = 0; i < 16; i++) {
    if (md5[i] < 0x10) {
      MD5String += "0"; // 如果是单个十六进制数字，前面加0
    }
    MD5String += String(md5[i], HEX); // 将每个字节转换为两位十六进制数并追加到字符串
  }

  // 输出模式处理
  if(md5_mode == MD5_LOWERCASE_32L)
  {
    return MD5String;
  }

  if(md5_mode == MD5_UPPERCASE_32L)
  {
    MD5String.toUpperCase();
    return MD5String;
  }

  if(md5_mode == MD5_LOWERCASE_16L)
  {
    if (MD5String.length() != 32) {return "ERROR";}
    MD5String = MD5String.substring(8, 24);
    return MD5String;
  }

  if(md5_mode == MD5_UPPERCASE_16L)
  {
    if (MD5String.length() != 32) {return "ERROR";}
    MD5String = MD5String.substring(8, 24);
    MD5String.toUpperCase();
    return MD5String;
  }
  else return "NULL";
}



/* MD5计算函数 char输入输出
 * @param input 待计算的数据
 * @param output 输出的目标数组
 * @param outputSize 输出的目标数组的大小
 * @param md5_mode MD5输出模式，可选大小写模式，16/32长度模式
 * @return QE_RETURN_STATE 函数处理状态
 */
int qe_MD5_char(char *input, char *output, size_t outputSize, QE_MD5_MODE md5_mode)
{
  MD5_CTX md5_calc;
  unsigned char md5[16];

  // 计算MD5
  MD5_Init(&md5_calc);
	MD5_Update(&md5_calc,(unsigned char *)input,strlen(input));
	MD5_Final(md5,&md5_calc);
  
  // 将输出结果转换为16进制字符串
  String MD5String = "";
  for (int i = 0; i < 16; i++) {
    if (md5[i] < 0x10) {
      MD5String += "0"; // 如果是单个十六进制数字，前面加0
    }
    MD5String += String(md5[i], HEX); // 将每个字节转换为两位十六进制数并追加到字符串
  }

  // 输出模式处理
  if(md5_mode == MD5_LOWERCASE_32L)
  {
    if(outputSize < 33) return ERROR_ARRAY_LENGTH; // 输出数组大小不满足
    MD5String.toCharArray(output, MD5String.length() + 1); 
    return NORMAL;
  }

  if(md5_mode == MD5_UPPERCASE_32L)
  {
    if(outputSize < 33) return ERROR_ARRAY_LENGTH; // 输出数组大小不满足
    MD5String.toCharArray(output, MD5String.length() + 1); 
    MD5String.toUpperCase();
    return NORMAL;
  }

  if(md5_mode == MD5_LOWERCASE_16L)
  {
    if (MD5String.length() != 32) {return ERROR_MISCALCULATION;}
    MD5String = MD5String.substring(8, 24);
    if(outputSize < 17) return ERROR_ARRAY_LENGTH; // 输出数组大小不满足
    MD5String.toCharArray(output, MD5String.length() + 1); 
    return NORMAL;
  }

  if(md5_mode == MD5_UPPERCASE_16L)
  {
    if (MD5String.length() != 32) {return ERROR_MISCALCULATION;}
    MD5String = MD5String.substring(8, 24);
    MD5String.toUpperCase();
    if(outputSize < 17) return ERROR_ARRAY_LENGTH; // 输出数组大小不满足
    MD5String.toCharArray(output, MD5String.length() + 1); 
    return NORMAL;
  }
  else return ERROR_NULL;
}



/* MD5计算函数
 * @param input 待计算的数据
 * @param md5_mode MD5输出模式，可选大小写模式，16/32长度模式
 * @return MD5String 计算结果,如发生错误则输出"ERROR",如计算失败则输出"NULL"
 */
String qe_MD5(char *input,QE_MD5_MODE md5_mode)
{
  MD5_CTX md5_calc;
  unsigned char md5[16];

  // 计算MD5
  MD5_Init(&md5_calc);
	MD5_Update(&md5_calc,(unsigned char *)input,strlen(input));
	MD5_Final(md5,&md5_calc);
  
  // 将输出结果转换为16进制字符串
  String MD5String = "";
  for (int i = 0; i < 16; i++) {
    if (md5[i] < 0x10) {
      MD5String += "0"; // 如果是单个十六进制数字，前面加0
    }
    MD5String += String(md5[i], HEX); // 将每个字节转换为两位十六进制数并追加到字符串
  }

  // 输出模式处理
  if(md5_mode == MD5_LOWERCASE_32L)
  {
    return MD5String;
  }

  if(md5_mode == MD5_UPPERCASE_32L)
  {
    MD5String.toUpperCase();
    return MD5String;
  }

  if(md5_mode == MD5_LOWERCASE_16L)
  {
    if (MD5String.length() != 32) {return "ERROR";}
    MD5String = MD5String.substring(8, 24);
    return MD5String;
  }

  if(md5_mode == MD5_UPPERCASE_16L)
  {
    if (MD5String.length() != 32) {return "ERROR";}
    MD5String = MD5String.substring(8, 24);
    MD5String.toUpperCase();
    return MD5String;
  }
  else return "NULL";
}



