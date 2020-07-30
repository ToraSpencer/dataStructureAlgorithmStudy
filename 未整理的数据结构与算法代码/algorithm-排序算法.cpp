#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

/* 排序算法： 1.交换排序
 * 					1.1冒泡排序
 * 					1.2快速排序
 * 		    2.插入排序
 * 		    3.选择排序
 * 		    4.归并排序
 * 		    5.基数排序
 */




// 遍历输出数组的函数：
template <typename T>
void dispArray(T arr[], int size)
{
	for(int i = 0; i<=size-1; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
}



/* 1.1冒泡排序————大元素逐步往后移动，如同气泡上浮。
 */

//迭代实现，迭代的每次基本操作为交换逆序的一对数字。
template <typename T>
void BubbleSort(T arr[], int size)
{
	bool finish = false;				// 判断是否可以提前结束排序的flag；
	T temp;
	int i = 0;
	while(i<=size-1 && finish==false)
	{
		finish = true;					// 下面的for循环扫描之后若没有发现逆序数字对，则可以结束排序。
		for(int j = 0;j<=size-i-2;j++)
		{
			if(arr[j]>arr[j+1])
			{
				finish = false;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		i++;
	}

}

void test1_1()
{
	int arr[] = {2,3,4,0,99,12,78,1};
	dispArray(arr,8);
	BubbleSort(arr,8);
	dispArray(arr,8);

}




/* 1.2快速排序————分而治之————递归
 * 		递归终止：（1）QuickSort(空集) = 空集；
 * 		递归递推：
 */

// 面向顺序表的快速排序：QuickSort()
template <typename T>
void QuickSort(T arr[], int low, int high)
{
	T cri = arr[low];
	T criIndex;
	T temp;
	if(low > high)
	{
		throw invalid_argument("high must not less than low;");
		return;
	}
	else if(low==high){return;}				//递归终止
	else
	{
		int i = low+1,j = high;
		while(i<j)
		{
			while(i<j && arr[i]<cri)
			{
				arr[i-1] = arr[i];
				i++;
			}
			while(i<j && arr[j]>cri)
			{
				j--;
			}

			if(i<j)
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
			else
			{
				if(arr[i]>cri)
				{
					arr[i-1] = cri;
					criIndex = i-1;
				}
				else
				{
					arr[i-1] = arr[i];
					arr[i] = cri;
					criIndex = i;
				}
			}
		}
	}
	if(criIndex>low){QuickSort(arr,low,criIndex-1);}
	if(criIndex<high){QuickSort(arr,criIndex+1,high);}
}



// 遍历打印vector元素的函数
template <typename T>
void dispVector(vector<T> v)
{
	vector<int>::const_iterator it1,it2;
	it1 = v.cbegin();
	it2 = v.cend();
	while(it1!=it2)
	{
		cout << *it1 << "   ";
		it1++;
	}
	cout << endl;
}



/* 面向STL动态数组vector的快速排序：Qsort_vec()
 *		递归终止：Qsort_vec(空v) = v;
 *				Qsort_vec(v == {a}) = v;
 *				Qsort_vec(v == {a,b}, a<=b) = {a,b};
 *				Qsort_vec(v == {a,b}, a>b) = {b,a};
 *		递归递推：Qsort_vec(v) = Qsort_vec(v_less)~cri~Qsort_vec(v_greater)	//~符号表示连接vector
 */
template <typename T>
vector<T> Qsort_vec(const vector<T>& v)
{
	vector<T> v_less, v_greater,v_sorted;
	T cri;
	const T *p;

	if(v.size()<=1){return v;}			// 递归终止1、2；
	else if(v.size()==2)
	{
		if(v.front() <= v.back()){return v;}		// 递归终止3；
		else										// 递归终止4；
		{
			v_sorted.push_back(v.back());
			v_sorted.push_back(v.front());
			return v_sorted;
		}
	}
	else
	{
		cri = *v.begin();
		p = &v.front();
		p++;
		for(; p<=&v.back(); p++)
		{
			if(*p <= cri){v_less.push_back(*p);}
			else{v_greater.push_back(*p);}
		}

		v_less = Qsort_vec(v_less);						// 递归递推
		v_greater = Qsort_vec(v_greater);				// 递归递推

		// 连接vector
		v_sorted = v_less;
		v_sorted.push_back(cri);
		v_sorted.insert(v_sorted.end(),v_greater.begin(),v_greater.end());

		return v_sorted;
	}
}


void test1_2()
{
	int arr[] = {2,1,0,9,8,-1,10,99,8};
	vector<int> v(arr,arr+9);

	cout << "测试Qsort_vec()：" << endl;
	dispVector(v);
	vector<int> v_sorted = Qsort_vec(v);
	dispVector(v_sorted);
}






/* 2.1直接插入排序(straight insert sort)
 *
 *
 */

// 遍历打印自定义链表的函数：
template <typename T>
void dispLink(LinkedListNode<T>* head)
{
	LinkedListNode<T>* p = head;
	while(p!=nullptr)
	{
		cout << p->data << "   ";
		p = p->next;
	}
	cout << endl;
}



// 遍历打印STL双向链表list的函数：
template <typename T>
void dispList(const list<T>& l)
{
	auto beg = l.begin();
	auto end = l.end();
	while(beg!=end)
	{
		cout << *beg << "   " ;
		beg++;
	}
	cout << endl;
	return ;
}



// 面向自定义链表的直接插入排序：SIsort_link()
template <typename T>
LinkedListNode<T>* SIsort_link(LinkedListNode<T>* h)
{
	LinkedListNode<T>* head = h;
	LinkedListNode<T>* p = nullptr;
	LinkedListNode<T>* q = nullptr;
	LinkedListNode<T>* pp = nullptr;
	LinkedListNode<T>* qq = nullptr;

	if(h==nullptr){return nullptr;}
	else
	{
		p = h->next;
		q = h;
		while(p!=nullptr)
		{
			while(p->data>=q->data)				// 双指针，按顺序扫描元素对，顺序对不处理，指针后移；逆序对则停止，转入下面的插入环节。
			{
				q = p;
				p = p->next;
			}
			if(p->data < head->data)			// 情形1：插到表头
			{
				q->next = p->next;
				p->next = head;
				head = p;
				p = q->next;
			}
			else								// 情形2：插到表中
			{
				pp = head;
				while(pp!=p)							// 双指针扫描，pp指针检索出第一个大于待插入元素的元素。
				{
					qq = pp;
					pp = pp->next;
					if(p->data<pp->data)
					{
						q->next = p->next;
						qq->next = p;
						p->next = pp;
						p = q->next;
						break;
					}

				}
			}
		}
	}
	return head;
}


// 面向STL双向链表list的直接插入排序：SIsort_list()
template <typename T>
list<T> SIsort_list(const list<T>& l)
{
	list<T> l_sorted;
	auto beg = l.cbegin();
	auto end = l.cend();
	auto p = l.cbegin();
	auto q = l.cbegin();
	if(beg == end){return l;}
	else
	{
		p++;
		l_sorted.push_back(*q);
		auto pp = l_sorted.cbegin();
		while(p!=end)
		{
			while(*q <= *p)			// 双指针法，逐个扫描相邻元素对，顺序对直接放入新list，碰到逆序对跳出循环做处理。
			{
				q = p;
				p++;
				l_sorted.push_back(*q);
			}
			if(*p <= *beg)						// 处理逆序对元素，情形1：插入表头
			{
				l_sorted.insert(l_sorted.begin(),*p);
				p++;
			}
			else								// 情形2：插入表中
			{
				while(*pp < *p)
				{
					pp++;
				}
				l_sorted.insert(pp,*p);
				pp = l_sorted.cbegin();
				p++;
			}}}
	return l_sorted;
}

 
void test2_1()
{
	cout << "测试SIsort_link()" << endl;
	int arr[] = {2,0,0,6,8,-1};
	LinkedList<int> l = LinkedList<int>(arr,6);
	LinkedListNode<int>* head = l.head;
	dispLink(head);
	LinkedListNode<int>* newHead = SIsort_link(head);
	dispLink(newHead);
	cout << endl;

	cout << "测试SIsort_list()" << endl;
	int *p1 = arr;
	int *p2 = &arr[6];
	list<int> ll(p1,p2);
	dispList(ll);
	list<int> ll_sorted = SIsort_list(ll);
	dispList(ll_sorted);
}




int main()
{
	//test1_1();
	test1_2();
	//test2_1();


	return 0;
}



