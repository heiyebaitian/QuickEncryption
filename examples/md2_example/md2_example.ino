/*
 * 本示例程序演示了如何调用qe_MD2()函数快速实现MD2消息摘要操作
 * 示例中的MD2参考值：76008dc5481f235664e357735905887f
 * 更新日期：2025年3月7日
 */

#include "QuickEncryption.h"
#include <Arduino.h>

char text1[]={"hello world!"};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
	Serial.print(qe_MD2(text1,MD2_LOWERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD2(text1,MD2_UPPERCASE_32L));
  Serial.print("\n");
  Serial.print(qe_MD2(text1,MD2_LOWERCASE_16L));
  Serial.print("\n");
  Serial.print(qe_MD2(text1,MD2_UPPERCASE_16L));
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


