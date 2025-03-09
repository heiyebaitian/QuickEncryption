/*
 * 本示例程序演示了如何调用qe_MD4函数快速实现MD4消息摘要操作
 * 示例中的MD4参考值：fc3ff98e8c6a0d3087d515c0473f8677
 * 更新日期：2025年3月9日
 */

#include "QuickEncryption.h"
#include <Arduino.h>

char text1[]={"hello world!"};
String text2 = "hello world!";
String text_ev = "3363b72840acd5f49f922fef598ee85d";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
  // 传入 char 输出 string
  Serial.print("\nqe_MD4()\n");
	Serial.print(qe_MD4(text1,MD4_LOWERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD4(text1,MD4_UPPERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD4(text1,MD4_LOWERCASE_16L));
  Serial.print("\n");
  Serial.print(qe_MD4(text1,MD4_UPPERCASE_16L));
  Serial.print("\n");

  if(qe_MD4(text1,MD4_LOWERCASE_32L) == text_ev )
  {
    Serial.print("\nMD4 verification passed.\n");
  }
  else
  {
    Serial.print("\nMD4 verification failed.\n");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}


