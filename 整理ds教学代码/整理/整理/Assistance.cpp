#include "Assistance.h"

// 从输入流inStream中跳过空格及制表符获取一字符
char GetChar(istream &inStream)
{
	char ch;								 
	while ((ch = (inStream).peek()) != EOF	// 文件结束符(peek()函数从输入流中接受1字符,流的当前位置不变)
		&& ((ch = (inStream).get()) == ' '	// 空格( get()函数从输入流中接受1字符,流的当前位置向后移1个位置)
			|| ch == '\t'));					 
	return ch;							 
}




// 由mes构构通用异常对象
Error::Error(const char *mes)
{
	strcpy(message, mes);				// 复制异常信息
}


//  显示异常信息
void Error::Show()const
{
	cout << message << endl;			// 显示异常信息	
}
