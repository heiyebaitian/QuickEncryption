#include "QuickEncryption.h"


/* MD2计算函数
 * @param input 待计算的数据
 * @param md2_mode MD2输出模式，可选大小写模式，16/32长度模式
 * @return MD2String 计算结果,如发生错误则输出"ERROR",如计算失败则输出"NULL"
 */
String qe_MD2(char *input,MD2_MODE md2_mode){
  unsigned char md2[16];
  MD2((unsigned char *)input,strlen(input),md2);
  String MD2String = "";
  for (int i = 0; i < 16; i++) {
    if (md2[i] < 0x10) {
      MD2String += "0"; // 如果是单个十六进制数字，前面加0
    }
    MD2String += String(md2[i], HEX); // 将每个字节转换为两位十六进制数并追加到字符串
  }

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

/* MD5计算函数
 * @param input 待计算的数据
 * @param md5_mode MD5输出模式，可选大小写模式，16/32长度模式
 * @return md5String 计算结果,如发生错误则输出"ERROR",如计算失败则输出"NULL"
 */
String qe_md5(char *input,MD5_MODE md5_mode)
{
  MD5_CTX md5_calc;
  unsigned char md5[16];
  MD5_Init(&md5_calc);
	MD5_Update(&md5_calc,(unsigned char *)input,strlen(input));
	MD5_Final(md5,&md5_calc);
  String md5String = "";
  for (int i = 0; i < 16; i++) {
    if (md5[i] < 0x10) {
      md5String += "0"; // 如果是单个十六进制数字，前面加0
    }
    md5String += String(md5[i], HEX); // 将每个字节转换为两位十六进制数并追加到字符串
  }

  if(md5_mode == MD5_LOWERCASE_32L)
  {
    return md5String;
  }

  if(md5_mode == MD5_UPPERCASE_32L)
  {
    md5String.toUpperCase();
    return md5String;
  }

  if(md5_mode == MD5_LOWERCASE_16L)
  {
    if (md5String.length() != 32) {return "ERROR";}
    md5String = md5String.substring(8, 24);
    return md5String;
  }

  if(md5_mode == MD5_UPPERCASE_16L)
  {
    if (md5String.length() != 32) {return "ERROR";}
    md5String = md5String.substring(8, 24);
    md5String.toUpperCase();
    return md5String;
  }
  else return "NULL";
}



