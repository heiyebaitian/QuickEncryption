/*
 * 本示例程序演示了如何调用qe_MD2函数快速实现MD2消息摘要操作
 * 示例中的MD2参考值：76008dc5481f235664e357735905887f
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
  Serial.print("\nqe_MD2()\n");
	Serial.print(qe_MD2(text1,MD2_LOWERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD2(text1,MD2_UPPERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD2(text1,MD2_LOWERCASE_16L));
  Serial.print("\n");
  Serial.print(qe_MD2(text1,MD2_UPPERCASE_16L));
  Serial.print("\n");

  // 传入 String 输出 String
  Serial.print("\nqe_MD2_str()\n");
	Serial.print(qe_MD2_str(text2,MD2_LOWERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD2_str(text2,MD2_UPPERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD2_str(text2,MD2_LOWERCASE_16L));
  Serial.print("\n");
  Serial.print(qe_MD2_str(text2,MD2_UPPERCASE_16L));
  Serial.print("\n");

  // 传入 char 输出 char
  Serial.print("\nqe_MD2_char()\n");
  char output[33] = {"NULL"};
  qe_MD2_char(text1, output, sizeof(output), MD2_LOWERCASE_32L);
	Serial.printf("%s", output);
  Serial.print("\n");
  qe_MD2_char(text1, output, sizeof(output), MD2_UPPERCASE_32L);
  Serial.printf("%s", output);
  Serial.print("\n");
  qe_MD2_char(text1, output, sizeof(output), MD2_LOWERCASE_16L);
  Serial.printf("%s", output);
  Serial.print("\n");
  qe_MD2_char(text1, output, sizeof(output), MD2_UPPERCASE_16L);
  Serial.printf("%s", output);
  Serial.print("\n");


  if(qe_MD2(text1,MD2_LOWERCASE_32L) == "76008dc5481f235664e357735905887f")
  {
    Serial.print("\nMD2 verification passed.\n");
  }
  else
  {
    Serial.print("\nMD2 verification failed.\n");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}


