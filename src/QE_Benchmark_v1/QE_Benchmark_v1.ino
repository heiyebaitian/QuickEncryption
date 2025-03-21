/*
 * Copyright 2025 The QuickEncryption Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution
 */

/*
 * 本程序提供了QuickEncryption库的多项基准测试功能，您可以使用此程序快速对目标平台的基准性能进行评估
 * 本程序将配合QuickEncryption库同步更新，您在编译本程序前请确保库版本为最新版本，以避免产生性能误差
 * 较新的库版本可能会提供更好的性能优化、安全优化、硬件加速适配等内容
 * 更新日期：2025年3月22日
 * 最低要求 QuickEncryption 版本：v0.2.0
 */

#include<Arduino.h>
#include "QuickEncryption.h"

#define TEXT_LENGTH 64
#define WARM_UP_CYCLE_NUMBER 200
#define MD2_CYCLE_NUMBER 10000
#define MD4_CYCLE_NUMBER 20000
#define MD5_CYCLE_NUMBER 20000
#define SHA1_CYCLE_NUMBER 20000
#define SHA256_CYCLE_NUMBER 20000


/* 自检测试
 * 通过对给定字符串进行计算并与预期值进行比对
 * @return 返回0为正常，其他值为异常
 */
int self_checking(){
  char text1[]={"6RZQ5vaxQ9hE#sLyk5eCLdCfA*RU38T%8fbXfcGz&Kxgy*!VN8BDtXv^w3#iSGXw"};
  const String md2_ev = "8c6fba25efe107b6972bc114f507a8e0";
  const String md4_ev = "1dda25c7373a4023981b27252046474d";
  const String md5_ev = "1cc6e3b39dc22371248d9d362a36f36d";
  const String sha1_ev = "cab391c07482239cd0bdccec8185d2e6f89509f1";
  const String sha256_ev = "9b0a201632faea9b9a5c8c2db792ebb321ebb0c8a8abba506174f70db920dc98";

  if(qe_MD2(text1,MD2_LOWERCASE_32L) != md2_ev) 
  {
    Serial.print("[QE_Benchmark] MD2 Self-check error!\n");
    Serial.printf("Source text:%s\n", text1);
    Serial.println("Expected value:" + md2_ev);
    Serial.println("Actual value:" + qe_MD2(text1,MD2_LOWERCASE_32L));
    return 1;
  }

  if(qe_MD4(text1,MD4_LOWERCASE_32L) != md4_ev)
  {
    Serial.print("[QE_Benchmark] MD4 Self-check error!\n");
    Serial.printf("Source text:%s\n", text1);
    Serial.println("Expected value:" + md4_ev);
    Serial.println("Actual value:" + qe_MD4(text1,MD4_LOWERCASE_32L));
    return 1;
  }

  if(qe_MD5(text1,MD5_LOWERCASE_32L) != md5_ev)
  {
    Serial.print("[QE_Benchmark] MD5 Self-check error!\n");
    Serial.printf("Source text:%s\n", text1);
    Serial.println("Expected value:" + md5_ev);
    Serial.println("Actual value:" + qe_MD5(text1,MD5_LOWERCASE_32L));
    return 1;
  }

  if(qe_SHA1(text1,SHA1_LOWERCASE) != sha1_ev)
  {
    Serial.print("[QE_Benchmark] SHA1 Self-check error!\n");
    Serial.printf("Source text:%s\n", text1);
    Serial.println("Expected value:" + sha1_ev);
    Serial.println("Actual value:" + qe_SHA1(text1,SHA1_LOWERCASE));
    return 1;
  }

  if(qe_SHA256(text1,SHA256_LOWERCASE) != sha256_ev)
  {
    Serial.print("[QE_Benchmark] SHA256 Self-check error!\n");
    Serial.printf("Source text:%s\n", text1);
    Serial.println("Expected value:" + sha256_ev);
    Serial.println("Actual value:" + qe_SHA256(text1,SHA256_LOWERCASE));
    return 1;
  }

  return 0;
}

/* 随机生成字符串
 * @param length 字符串长度
 * @return 返回生成的字符串
 */
String RandomString(int length) {
  const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+";
  int charsetLength = sizeof(charset) - 1;
  String result = "";

  for (int i = 0; i < length; i++) {
    int index = random(charsetLength);
    result += charset[index];
  }

  return result;
}


/* 基准测试程序
 * @return 返回0为正常，其他值为异常
 */
int QE_Benchmark(){
  randomSeed(analogRead(0) + micros()); // 设置随机数种子为 不使用的引脚读取一个模拟量并加上当前系统运行时间
  String buffer = "";
  String text = "";
  char char_text[TEXT_LENGTH+1] = {};

  Serial.printf("\n\n----------QE Benchmark v1----------\n");

  /* MD2 测试*/
  // 测试前预热
  for(int i=0; i <= WARM_UP_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_MD2( char_text, MD2_LOWERCASE_32L); // 计算MD2值存入缓冲区
    if(buffer != qe_MD2( char_text, MD2_LOWERCASE_32L)) return 1; // 再次计算并校验结果
  }

  unsigned long MD2_time = micros();
  double MD2_rate = 0;
  for(int i=0; i <= MD2_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_MD2( char_text, MD2_LOWERCASE_32L); // 计算MD2值存入缓冲区
    if(buffer != qe_MD2( char_text, MD2_LOWERCASE_32L)) return 1; // 再次计算并校验结果
  }
  MD2_time = micros() - MD2_time;
  MD2_rate = (TEXT_LENGTH * MD2_CYCLE_NUMBER * 2 / 1024.0) / (MD2_time/1000000.0); // 计算速率
  Serial.printf("MD2:%.2lf KB/s\n",MD2_rate);

  /* MD4 测试*/
  // 测试前预热
  for(int i=0; i <= WARM_UP_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_MD4( char_text, MD4_LOWERCASE_32L); // 计算MD4值存入缓冲区
    if(buffer != qe_MD4( char_text, MD4_LOWERCASE_32L)) return 1; // 再次计算并校验结果
  }

  unsigned long MD4_time = micros();
  double MD4_rate = 0;
  for(int i=0; i <= MD4_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_MD4( char_text, MD4_LOWERCASE_32L); // 计算MD4值存入缓冲区
    if(buffer != qe_MD4( char_text, MD4_LOWERCASE_32L)) return 1; // 再次计算并校验结果
  }
  MD4_time = micros() - MD4_time;
  MD4_rate = (TEXT_LENGTH * MD4_CYCLE_NUMBER * 2 / 1024.0) / (MD4_time/1000000.0); // 计算速率
  Serial.printf("MD4:%.2lf KB/s\n",MD4_rate);

  /* MD5 测试*/
  // 测试前预热
  for(int i=0; i <= WARM_UP_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_MD5( char_text, MD5_LOWERCASE_32L); // 计算MD5值存入缓冲区
    if(buffer != qe_MD5( char_text, MD5_LOWERCASE_32L)) return 1; // 再次计算并校验结果
  }

  unsigned long MD5_time = micros();
  double MD5_rate = 0;
  for(int i=0; i <= MD5_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_MD5( char_text, MD5_LOWERCASE_32L); // 计算MD5值存入缓冲区
    if(buffer != qe_MD5( char_text, MD5_LOWERCASE_32L)) return 1; // 再次计算并校验结果
  }
  MD5_time = micros() - MD5_time;
  MD5_rate = (TEXT_LENGTH * MD5_CYCLE_NUMBER * 2 / 1024.0) / (MD5_time/1000000.0); // 计算速率
  Serial.printf("MD5:%.2lf KB/s\n",MD5_rate);

  /* SHA1 测试*/
  // 测试前预热
  for(int i=0; i <= WARM_UP_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_SHA1( char_text, SHA1_LOWERCASE); // 计算SHA1值存入缓冲区
    if(buffer != qe_SHA1( char_text, SHA1_LOWERCASE)) return 1; // 再次计算并校验结果
  }

  unsigned long SHA1_time = micros();
  double SHA1_rate = 0;
  for(int i=0; i <= SHA1_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_SHA1( char_text, SHA1_LOWERCASE); // 计算SHA1值存入缓冲区
    if(buffer != qe_SHA1( char_text, SHA1_LOWERCASE)) return 1; // 再次计算并校验结果
  }
  SHA1_time = micros() - SHA1_time;
  SHA1_rate = (TEXT_LENGTH * SHA1_CYCLE_NUMBER * 2 / 1024.0) / (SHA1_time/1000000.0); // 计算速率
  Serial.printf("SHA1:%.2lf KB/s\n",SHA1_rate);

  /* SHA256 测试*/
  // 测试前预热
  for(int i=0; i <= WARM_UP_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_SHA256( char_text, SHA256_LOWERCASE); // 计算SHA256值存入缓冲区
    if(buffer != qe_SHA256( char_text, SHA256_LOWERCASE)) return 1; // 再次计算并校验结果
  }

  unsigned long SHA256_time = micros();
  double SHA256_rate = 0;
  for(int i=0; i <= SHA256_CYCLE_NUMBER; i++){
    text = RandomString(TEXT_LENGTH); // 生成长度 TEXT_LENGTH 的随机字符串
    text.toCharArray(char_text, text.length() + 1); 
    buffer = qe_SHA256( char_text, SHA256_LOWERCASE); // 计算SHA256值存入缓冲区
    if(buffer != qe_SHA256( char_text, SHA256_LOWERCASE)) return 1; // 再次计算并校验结果
  }
  SHA256_time = micros() - SHA256_time;
  SHA256_rate = (TEXT_LENGTH * SHA256_CYCLE_NUMBER * 2 / 1024.0) / (SHA256_time/1000000.0); // 计算速率
  Serial.printf("SHA256:%.2lf KB/s\n",SHA256_rate);

  Serial.printf("-----------------------------------\n");
  return 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);

  if(self_checking() != 0)
  {
    Serial.print("\n[QE_Benchmark] Self-check error!\n");
    while(1);
  }
  else Serial.print("\n[QE_Benchmark] Self-test normal.\n");

  Serial.print("[QE_Benchmark] Benchmark will begin to run.\n");

  //  程序异常则抛出错误
  if(QE_Benchmark() != 0){
    Serial.print("\n[QE_Benchmark] QE_Benchmark error!\n");
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}



