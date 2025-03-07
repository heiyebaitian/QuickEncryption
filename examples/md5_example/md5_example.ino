/*
 * 本示例程序演示了如何调用qe_MD5()函数快速实现MD5消息摘要操作
 * 示例中的MD5参考值：fc3ff98e8c6a0d3087d515c0473f8677
 * 更新日期：2025年3月7日
 */

#include "QuickEncryption.h"
#include <Arduino.h>

char text1[]={"hello world!"};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
	Serial.print(qe_MD5(text1,MD5_LOWERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD5(text1,MD5_UPPERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD5(text1,MD5_LOWERCASE_16L));
  Serial.print("\n");
  Serial.print(qe_MD5(text1,MD5_UPPERCASE_16L));
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


