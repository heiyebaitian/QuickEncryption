/*
 * 本示例程序演示了如何调用qe_MD5函数快速实现MD5消息摘要操作
 * 示例中的MD5参考值：fc3ff98e8c6a0d3087d515c0473f8677
 * 更新日期：2025年3月8日
 */

#include "QuickEncryption.h"
#include <Arduino.h>

char text1[]={"hello world!"};
String text2 = "hello world!";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
  // 传入 char 输出 string
  Serial.print("\nqe_MD5()\n");
	Serial.print(qe_MD5(text1,MD5_LOWERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD5(text1,MD5_UPPERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD5(text1,MD5_LOWERCASE_16L));
  Serial.print("\n");
  Serial.print(qe_MD5(text1,MD5_UPPERCASE_16L));
  Serial.print("\n");

  // 传入 String 输出 String
  // 注意：此方法存在输入长度限制，限制项在QuickEncryption.h 的 #define MD5_INPUT_MAX 中更改
  Serial.print("\nqe_MD5_str()\n");
	Serial.print(qe_MD5_str(text2,MD5_LOWERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD5_str(text2,MD5_UPPERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD5_str(text2,MD5_LOWERCASE_16L));
  Serial.print("\n");
  Serial.print(qe_MD5_str(text2,MD5_UPPERCASE_16L));
  Serial.print("\n");

  // 传入 char 输出 char
  Serial.print("\nqe_MD5_char()\n");
  char output[33] = {"NULL"};
  qe_MD5_char(text1, output, sizeof(output), MD5_LOWERCASE_32L);
	Serial.printf("%s", output);
  Serial.print("\n");
  qe_MD5_char(text1, output, sizeof(output), MD5_UPPERCASE_32L);
  Serial.printf("%s", output);
  Serial.print("\n");
  qe_MD5_char(text1, output, sizeof(output), MD5_LOWERCASE_16L);
  Serial.printf("%s", output);
  Serial.print("\n");
  qe_MD5_char(text1, output, sizeof(output), MD5_UPPERCASE_16L);
  Serial.printf("%s", output);
  Serial.print("\n");


  if(qe_MD5(text1,MD5_LOWERCASE_32L) == "fc3ff98e8c6a0d3087d515c0473f8677")
  {
    Serial.print("\nMD5 verification passed.\n");
  }
  else
  {
    Serial.print("\nMD5 verification failed.\n");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}


