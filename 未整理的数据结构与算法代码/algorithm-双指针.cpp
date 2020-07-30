#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

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


/* arrange()：在不开辟新数组内存的情况下，对输入数组进行整理，以数组第一个元素为基准cri，数组中小于cri的数排在cri前面，大于cri的数排在其后面。
 */
template <typename T>
void arrange(T arr[], int low, int high)
{
	if(low > high)
	{
		throw invalid_argument("high must not less than low;");
		return;
	}
	else if(low==high){return;}
	else
	{
		int i = low+1,j = high;
		T cri = arr[low];
		T temp;
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
				if(arr[i]>cri){arr[i-1] = cri;}
				else{arr[i-1] = arr[i];arr[i] = cri;}
			}
		}
	}
}

void test1()
{
	int arr[] = {5,1,2,3,8,11,2,9,0};
	dispArray(arr,9);
	arrange(arr,0,8);
	dispArray(arr,9);

	int arr1[] = {1};
	dispArray(arr1,1);
	arrange(arr1,0,0);
	dispArray(arr1,1);

}


int main()
{
	test1();




	return 0;
}



