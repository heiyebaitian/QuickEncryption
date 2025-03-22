/*
 * 本示例程序演示了如何调用qe_SHA256函数快速实现SHA256消息摘要操作
 * 示例中的SHA256参考值：7509e5bda0c762d2bac7f90d758b5b2263fa01ccbc542ab5e3df163be08e6ca9
 * 更新日期：2025年3月22日
 */

#include "QuickEncryption.h"
#include <Arduino.h>

char text1[]={"hello world!"};
String text2 = "hello world!";
String text_ev = "7509e5bda0c762d2bac7f90d758b5b2263fa01ccbc542ab5e3df163be08e6ca9";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
  // 传入 char 输出 string
  
  Serial.print("\nqe_SHA256()\n");
	Serial.print(qe_SHA256(text1,SHA256_LOWERCASE));
  Serial.print("\n");
  Serial.print(qe_SHA256(text1,SHA256_UPPERCASE));
  Serial.print("\n");


  // 传入 String 输出 String
  // 注意：此方法存在输入长度限制，限制项在QuickEncryption.h 的 #define SHA256_INPUT_MAX 中更改
  Serial.print("\nqe_SHA256_str()\n");
	Serial.print(qe_SHA256_str(text2,SHA256_LOWERCASE));
  Serial.print("\n");
  Serial.print(qe_SHA256_str(text2,SHA256_UPPERCASE));
  Serial.print("\n");


  // 传入 char 输出 char
  Serial.print("\nqe_SHA256_char()\n");
  char output[41] = {"NULL"};
  qe_SHA256_char(text1, output, sizeof(output), SHA256_LOWERCASE);
	Serial.printf("%s", output);
  Serial.print("\n");
  qe_SHA256_char(text1, output, sizeof(output), SHA256_UPPERCASE);
  Serial.printf("%s", output);
  Serial.print("\n");



  if(qe_SHA256(text1,SHA256_LOWERCASE) == text_ev )
  {
    Serial.print("\nSHA256 verification passed.\n");
  }
  else
  {
    Serial.print("\nSHA256 verification failed.\n");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}