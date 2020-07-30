/*线性结构：
 * 		按照存储结构分类：顺序表、链表
 * 		按照操作分类：线性表、栈、队列
 *
 *顺序表：
 *		数组形式保存的线性表
 *		静态分配内存，开辟内存前需要知道元素数目。
 *
 *
 *
 */

#ifndef SRC_SEQUENCELIST_H_
#define SRC_SEQUENCELIST_H_

#include <iostream>
using namespace std;

//自定义类型
enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
			 NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};
#define DEFAULT_SIZE 1000			// 缺省元素个数
#define DEFAULT_INFINITY 1000000	// 缺省无穷大

template <typename T>
void disp(const T&);

template <typename T>
class SequenceList
{protected:
	int length;							//顺序表当前长度。
	int maxLength;						//顺序表最大长度。
	T*  pe;								//首元素指针。
public:
	//构造析构函数：
	SequenceList(int mlen = DEFAULT_SIZE);					//默认容量为DEFAULT_SIZE;
	SequenceList(T e[], int n, int mlen = DEFAULT_SIZE);	//使用已有数组构造顺序表。
	SequenceList(const SequenceList& s);					//拷贝构造函数。
	~SequenceList();

	//get/set方法：
	int getLength() const;
	int getMaxLength() const;
	T* getPe() const;

	//操作单个元素的方法：
	Status getElem(int i, T& e) const;						// 取第i个元素的值
	Status setElem(int i, const T& e);						// 修改第i个元素的值
	Status deleteElem(int i, T& e);      					// 删除第i个元素
	Status insertElem(int i, const T& e); 					// 在第i个位置插入元素
 	Status insertElem(const T& e);        					// 在表尾插入元素

	//其他普通方法：
 	bool isEmpty() const;
 	void clear();

	//遍历：
 	void traverse(void (*visit)(const T&)) const;

 	//查找：
 	int locateElem(const T& e) const;						// 元素定位，求指定元素在顺序表中的位置
};





//实现：
template <typename T>
void disp(const T& el)
{cout << el << "   ";}

template <typename T>
SequenceList<T>::SequenceList(int mlen):length(0),maxLength(mlen),pe(NULL){}

template <typename T>
SequenceList<T>::SequenceList(T e[], int n, int mlen)
{
	T* ptemp = new T[10];
	this->length = n;
	this->maxLength = mlen;
	this->pe = ptemp;
}

template <typename T>
SequenceList<T>::SequenceList(const SequenceList& s)
{
	int length = s.getLength();
	this->length = length;
	this->maxLength = s.getMaxLength();
	T temp[this->length];
	T* p = s.getPe();
	for(int i = 0; i<=this->length-1; i++){temp[i] = p[i];}
	this->pe = temp;
}

template <typename T>
SequenceList<T>::~SequenceList(){}

template <typename T>
int SequenceList<T>::getLength() const {return this->length;}

template <typename T>
int SequenceList<T>::getMaxLength() const {return this->maxLength;}

template <typename T>
T* SequenceList<T>::getPe() const {return pe;}

template <typename T>
Status SequenceList<T>::getElem(int i, T& e) const
{
	if((i<1)||(i>this->length)){return RANGE_ERROR;}			//超出索引范围，元素不存在。
	else
	{
		e = pe[i-1];
		return SUCCESS;
	}
}

template <typename T>
Status SequenceList<T>::setElem(int i, const T& e)
{
	if((i<1)||(i>this->length)){return RANGE_ERROR;}
	else
	{
		pe[i-1] = e;
		return SUCCESS;
	}

}

template <typename T>
Status SequenceList<T>::deleteElem(int i, T& e)
{
	if((i<1)||(i>this->length)){return RANGE_ERROR;}
	else
	{
		e = pe[i-1];					//用e返回被删除的元素值
		//被删元素右边所有元素左移一位：
		for(int j = i; j<=this->length-1; j++){pe[j-1] = pe[j];}
		this->length--;
		return SUCCESS;
	}
}

template <typename T>
Status SequenceList<T>::insertElem(int i, const T& e)
{
	if((i<1)||(i>this->length)){return RANGE_ERROR;}
	else
	{
		for(int j = this->length; j>=i; j--){pe[j] = pe[j-1];}
		pe[i-1] = e;
		this->length++;
		return SUCCESS;
	}
}

template <typename T>
Status SequenceList<T>::insertElem(const T& e)
{
	if(this->length == this->maxLength){return OVER_FLOW;}
	else
	{
		pe[length] = e;
		this->length++;
		return SUCCESS;
	}
}

template <typename T>
bool SequenceList<T>::isEmpty() const
{
	return this->length == 0;
}

template <typename T>
void SequenceList<T>::clear()
{
	this->length = 0;					//是否要释放内存？
}

template <typename T>
void SequenceList<T>::traverse(void (*visit)(const T&)) const
{
	for(int i = 0; i<= this->length-1; i++)
	{
		(*visit)(pe[i]);
	}
}

template <typename T>
int SequenceList<T>::locateElem(const T& e) const
{
	int i = 0;
	while((i <= this->length-1)&&(pe[i]!=e)){i++;}
	return i<=length-1 ? (i+1) : 0;
}



#endif /* SRC_SEQUENCELIST_H_ */
