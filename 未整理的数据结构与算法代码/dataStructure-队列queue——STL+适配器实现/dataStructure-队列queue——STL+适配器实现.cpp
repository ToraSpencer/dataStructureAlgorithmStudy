#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>

#include <list>
#include <queue>

using namespace std;
/*队列(queue):
 * 		任何满足先进先出结构(FIFO, fist in/fist out. 首进尾出或尾进首出)的都可以被称为队列。
 *		是逻辑结构的范畴，不拘泥与某种特定的物理结构。
 *
 *
 *
 */

//链表实现的queue——尾进首出
template <typename T>
class Queue
{public:
	//构造、析构函数：
	Queue(){}


	//访问、操作单个元素的成员函数：
	T fistEI()										//返回队列的第一个元素。
	{
		return list.front();
	}

	void enqueue(const T& el)						//从队列尾部加入元素。
	{
		list.push_back(el);
	}

	T dequeue()										//从队列首端取出第一个元素。
	{
		T el = list.front();
		list.pop_front();
		return el;
	}

	T front()										//返回队列首端第一个元素。
	{
		return list.front();
	}

	//其他成员函数：
	void clear()
	{
		list.clear();
	}

	bool isEmpty()
	{
		return list.empty();
	}


private:
	list<T> list;

};

//数组实现的queue——未完成
template <typename T, int size = 100>
class ArrayQueue
{public:
	//构造、析构函数：
	ArrayQueue():first(-1),last(-1){}

	//访问、操作单个元素的成员函数：
	void enqueue(T el){}




	//其他成员函数：
	bool isFool()
	{
		return 0;
	}

	bool isEmpty()
	{
		return 0;
	}


private:
	int first,last;
	T storage[size];
};

//test1:
void test1()
{
	cout << "" << endl << endl;
	Queue<double> q = Queue<double>();

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << "q.dequeue() = " << q.dequeue() << endl;
	cout << "q.dequeue() = " << q.dequeue() << endl;
	cout << "q.dequeue() = " << q.dequeue() << endl;
}

//test2:使用<queue>提供的容器适配器queue将list转换为队列——用队列的接口来覆盖list原有接口
void test2()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << "" << q.empty() << endl;
	cout << "" << q.size() << endl;




}

int main()
{
	//test1();
	test2();

	return 0;
}
