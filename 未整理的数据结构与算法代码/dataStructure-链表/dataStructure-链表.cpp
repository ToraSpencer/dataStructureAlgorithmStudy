
#include "LinkedList.h"

int main()
{

	LinkedList<int> l = LinkedList<int>();
	cout << "l.isEmpty() = " << l.isEmpty() << endl;
	cout << "l.insertElem(1) = " << l.insertElem(1) << endl;
	l.insertElem(2);
	l.insertElem(3);
	l.insertElem(4);
	l.insertElem(5);
	int temp;
	cout << "l.isEmpty() = " << l.isEmpty() << endl;
	cout << "l.getElem(4,temp) = " << l.getElem(4,temp) << endl;
	cout << "temp = " << temp << endl;
	l.traverse(disp);
	cout << "l.setElem(1,99) = " << l.setElem(1,99) << endl;
	cout << "temp = " << temp << endl;
	l.traverse(disp);
	cout << "l.delete(4,temp) = " << l.deleteElem(4,temp) << endl;
	cout << "temp = " << temp << endl;
	l.traverse(disp);
	cout << "l.insertElem(3,98); = " << l.insertElem(3,98) << endl;
	l.traverse(disp);
	cout << "l.insertElem(100) = " << l.insertElem(100) << endl;
	l.traverse(disp);
	cout << "l.locateElem(99) = " << l.locateElem(99) << endl;
	l.clear();
	cout << "l.isEmpty() = " << l.isEmpty() << endl;
	cout << endl;

	int arr[] = {-1,-2,-3,-4,-5};
	LinkedList<int> l1 = LinkedList<int>(arr,5);
	cout << "l1.isEmpty() = " << l1.isEmpty() << endl;
	cout << "l1.getElem(1,temp) = " << l1.getElem(1,temp) << endl;
	cout << "temp = " << temp << endl;
	l1.traverse(disp);
	cout << endl;

	LinkedList<int> l2 = LinkedList<int>(l1);
	l2.traverse(disp);





	return 0;
}
