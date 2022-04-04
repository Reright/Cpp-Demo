#include "main.h"

using namespace std;

//交换函数
template <typename T>
inline void Swap(T& num1, T& num2)		//交换
{
	T tempnum = num1;
	num1 = num2, num2 = tempnum;
}

//普通排序，默认升序
template <typename T>
void Sort(T* left, T* right)  // 顺手就是一个快排..
{
	if (left >= right) return;

	T* i = left;
	T* j = right;

	T base = *left;

	while (i < j)
	{
		while (i < j && base <= *j) j--;

		while (i < j && base >= *i) i++;

		if (i >= j) continue;

		Swap(i, j);
	}

	*left = *i;
	*i = base;

	Sort(left, i - 1);
	Sort(j + 1, right);
}

//三个参数自定义规则排序重载
template <typename T, typename Callback>
void Sort(T* left, T* right, Callback funptr)
{
	if (left >= right) return;

	T* i = left;
	T* j = right;

	T base = *left;

	while (i < j)
	{
		while (i < j && (*funptr)(base, *j)) j--;

		while (i < j && funptr(base, *i)) i++;

		if (i >= j) continue;

		Swap(i, j);
	}

	*left = *i;
	*i = base;

	Sort(left, i - 1, funptr);
	Sort(j + 1, right, funptr);
}

//回调函数
bool compare(int num1, int num2)
{
	return num1 < num2;
}

// 这是lambda表达式哦，并不是回调函数
void ShowVec(vector<int>& v)
{
    std::for_each(v.cbegin(), v.cend(), [](auto& c){ cout << c << " "; });
    cout << endl;
}


int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    vector<int> vec;;
    for(int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    ShowVec(vec);

    constexpr int size = 6;

	int arr[size] = { 4,2,1,7,9,6 };

	Sort(arr, arr + size - 1, compare);	// 排序，第三个实参向Sort传递了compare的函数地址
    Sort(arr, arr + size - 1);	// 默认排序
    // std::for_each(arr)  普通数组有迭代器吗？
    for (auto &c : arr) {
        cout << c << " "; 
    }

    return 0;
}