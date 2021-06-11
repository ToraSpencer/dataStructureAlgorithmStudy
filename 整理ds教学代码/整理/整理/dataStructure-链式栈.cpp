#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>

#include "LinkedListNode.h"
#include "LinkStack.h"



using namespace std;



int main()
{
	LinkedListNode<int>* p1 = NULL;
	LinkedListNode<int> n1 = LinkedListNode<int>();
	p1 = &n1;
	LinkedListNode<int> n2 = LinkedListNode<int>(1,p1);
	LinkedListNode<int> n3 = LinkedListNode<int>(n2);

	LinkStack<int> s = LinkStack<int>();
	cout << "s.isEmpty() = " << s.isEmpty() << endl;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	int temp;



	LinkedListNode<int>* p = s.getTop();
	cout << "p->data = " << p->data << endl;
	s.Traverse(disp);
	cout << endl;


	cout << "s.isEmpty() = " << s.isEmpty() << endl;
	s.pop(temp);
	s.Top(temp);
	cout << "temp = " << temp << endl;
	s.pop(temp);
	cout << "temp = " << temp << endl;
	s.pop(temp);
	cout << "temp = " << temp << endl;
	s.pop(temp);
	cout << "temp = " << temp << endl;
	s.pop(temp);
	cout << "temp = " << temp << endl;
	cout << "s.isEmpty() = " << s.isEmpty() << endl;


	return 0;
}


