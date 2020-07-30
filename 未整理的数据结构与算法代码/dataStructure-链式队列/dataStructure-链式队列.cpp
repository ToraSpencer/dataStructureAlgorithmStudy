

#include "LinkQueue.h"

int main()
{
	LinkQueue<int> q = LinkQueue<int>();
	cout << "q.isEmpty() = " << q.isEmpty() << endl;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	q.enQueue(6);
	cout << "q.isEmpty() = " << q.isEmpty() << endl;
	cout << "q.getLength() = " << q.getLength() << endl;
	q.traverse(disp);
	cout << endl;

	int temp;
	cout << "q.getHead(temp) = " << q.getHead(temp) << endl;
	cout << "temp = " << temp << endl;
	cout << "q.delQueue(temp)" << q.delQueue(temp) << endl;
	cout << "temp = " << temp << endl;
	cout << "q.delQueue(temp) = " << q.delQueue(temp) << endl;
	cout << "q.delQueue(temp) = " << q.delQueue(temp) << endl;
	q.traverse(disp);
	cout << "q.delQueue(temp) = " << q.delQueue(temp) << endl;
	cout << "q.delQueue(temp) = " << q.delQueue(temp) << endl;
	cout << "q.delQueue(temp) = " << q.delQueue(temp) << endl;
	cout << "q.delQueue(temp) = " << q.delQueue(temp) << endl;
	cout << "q.isEmpty() = " << q.isEmpty() << endl;






	return 0;
}
