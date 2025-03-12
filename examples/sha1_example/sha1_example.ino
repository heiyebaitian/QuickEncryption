/*
 * 本示例程序演示了如何调用qe_SHA1函数快速实现SHA1消息摘要操作
 * 示例中的SHA1参考值：430ce34d020724ed75a196dfc2ad67c77772d169
 * 更新日期：2025年3月12日
 */

#include "QuickEncryption.h"
#include <Arduino.h>

char text1[]={"hello world!"};
String text2 = "hello world!";
String text_ev = "430ce34d020724ed75a196dfc2ad67c77772d169";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
  // 传入 char 输出 string
  
  Serial.print("\nqe_SHA1()\n");
	Serial.print(qe_SHA1(text1,SHA1_LOWERCASE));
  Serial.print("\n");
  Serial.print(qe_SHA1(text1,SHA1_UPPERCASE));
  Serial.print("\n");


  // 传入 String 输出 String
  // 注意：此方法存在输入长度限制，限制项在QuickEncryption.h 的 #define SHA1_INPUT_MAX 中更改
  Serial.print("\nqe_SHA1_str()\n");
	Serial.print(qe_SHA1_str(text2,SHA1_LOWERCASE));
  Serial.print("\n");
  Serial.print(qe_SHA1_str(text2,SHA1_UPPERCASE));
  Serial.print("\n");


  // 传入 char 输出 char
  Serial.print("\nqe_SHA1_char()\n");
  char output[41] = {"NULL"};
  qe_SHA1_char(text1, output, sizeof(output), SHA1_LOWERCASE);
	Serial.printf("%s", output);
  Serial.print("\n");
  qe_SHA1_char(text1, output, sizeof(output), SHA1_UPPERCASE);
  Serial.printf("%s", output);
  Serial.print("\n");



  if(qe_SHA1(text1,SHA1_LOWERCASE) == text_ev )
  {
    Serial.print("\nSHA1 verification passed.\n");
  }
  else
  {
    Serial.print("\nSHA1 verification failed.\n");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}