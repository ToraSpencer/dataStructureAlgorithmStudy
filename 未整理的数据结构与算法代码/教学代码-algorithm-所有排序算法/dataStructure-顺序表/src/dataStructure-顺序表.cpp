#include "SequenceList.h"

int main()
{
	int arr[] = {1,2,3,4,5,6,7};

	SequenceList<int> s = SequenceList<int>(arr,10,100);

	s.setElem(1,1);
	s.setElem(2,2);
	s.setElem(3,3);
	s.setElem(4,4);
	s.setElem(5,5);
	s.setElem(6,6);
	s.setElem(7,7);
	s.setElem(8,8);
	s.setElem(9,9);
	s.setElem(10,10);
	s.traverse(disp);
	cout << "s.getLength() = " << s.getLength() << endl;
	cout << endl;

	s.insertElem(-1);
	s.insertElem(-2);
	s.insertElem(-3);
	s.traverse(disp);
	cout << "s.getLength() = " << s.getLength() << endl;
	cout << endl;

	int e;
	cout << "s.getElem(3,e) = " << s.getElem(3,e) << endl;
	cout << "e = " << e << endl;
	cout << endl;

	cout << "s.deleteElem(4,e) = " << s.deleteElem(4,e) << endl;
	cout << "e = " << e << endl;
	cout << "s.getLength() = " << s.getLength() << endl;
	cout << endl;

	s.traverse(disp);
	cout << "s.locateElem(8) = " << s.locateElem(8) << endl;
	cout << endl;

	cout << "s.isEmpty() = " << s.isEmpty() << endl;
	s.clear();
	cout << "s.isEmpty() = " << s.isEmpty() << endl;









	return 0;
}
