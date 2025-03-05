/*
 * 本示例程序演示了如何调用qe_md5()函数快速实现MD5消息摘要操作
 * 示例中的MD5参考值：fc3ff98e8c6a0d3087d515c0473f8677
 * 日期：2025年3月5日
 */

#include "QuickEncryption.h"
#include <Arduino.h>

char text1[]={"hello world!"};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
	Serial.print(qe_md5(text1,LOWERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_md5(text1,UPPERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_md5(text1,LOWERCASE_16L));
  Serial.print("\n");
  Serial.print(qe_md5(text1,UPPERCASE_16L));
  Serial.print("\n");
  if(qe_md5(text1,LOWERCASE_32L) == "fc3ff98e8c6a0d3087d515c0473f8677")
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


