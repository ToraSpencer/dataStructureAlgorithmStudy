#include "Assistance.h"

// ��������inStream�������ո��Ʊ����ȡһ�ַ�
char GetChar(istream &inStream)
{
	char ch;								 
	while ((ch = (inStream).peek()) != EOF	// �ļ�������(peek()�������������н���1�ַ�,���ĵ�ǰλ�ò���)
		&& ((ch = (inStream).get()) == ' '	// �ո�( get()�������������н���1�ַ�,���ĵ�ǰλ�������1��λ��)
			|| ch == '\t'));					 
	return ch;							 
}




// ��mes����ͨ���쳣����
Error::Error(const char *mes)
{
	strcpy(message, mes);				// �����쳣��Ϣ
}


//  ��ʾ�쳣��Ϣ
void Error::Show()const
{
	cout << message << endl;			// ��ʾ�쳣��Ϣ	
}
