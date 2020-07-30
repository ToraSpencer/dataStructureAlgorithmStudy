/*
 *
 *
 *
 *
 *
 */

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

/*1.求和：
 * 		递归递推式：SUM({a,b,c}) = SUM({a,b}) + c;
 * 		递归终止条件：SUM(空集) = 0； SUM({a}) = a;
 */
template<typename T>
T SUM(T arr[], int size)
{
	if(size>1)
	{
		T temp = SUM(arr,size-1) + arr[size-1];		// 递归递推
		return temp;
	}
	else if(size == 1)
	{
		return arr[0];								// 递归终止
	}
	else if(size == 0)								// 递归终止
	{
		return 0;
	}
	else
	{
		throw invalid_argument("the argument should be a number array and an integer.");
	}

}

void test1()
{
	int arr[] = {2,5,1,6};
	int result = SUM(arr,4);
	cout << result<< endl;
}




/*2.快速排序：
 * 		递归递推式：Qsort({a,b,c,d,e,f,g}) = CAT(Qsort(b,e,g), {a}, Qsort({c,d,f}));
 * 						选取数组的第一个数字a为参考数字，b,e,g为小于等于a的元素，c,d,f为大于a的元素。
 * 						CAT()表示连接数组的函数。
 * 		递归终止条件：Qsort(空集) = 空集； Qsort({a}) = {a}; Qsort({1,2}) = {1,2}; Qsort({2,1}) = {1,2};
 */
template <typename T>
vector<T> CAT(vector<T> v1, vector<T> v2, vector<T> v3)
{
	vector<T> temp;


}

template <typename T>
vector<T> Qsort(vector<T> v)
{



}




int main()
{
	test1();

	return 0;
}
