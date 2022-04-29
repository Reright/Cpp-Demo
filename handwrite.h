#include "test_vector.h"
#include "test_list.h"
#include "test_deque.h"
#include "test_forward_list.h"
#include "test_map.h"
#include "test_priority_queue.h"
#include "test_stack.h"
#include "test_set.h"
#include "test_unordered_map.h"
#include "test_string.h"
#include "test_unordered_set.h"
using namespace std;

/*
快排的的一种思想是 “挖坑填数” + 分治法
递归过程概括为: 我把我的数给你，你往中间走一步
分治的代码都由一个while里面套了若干个while构成
*/
void quickrecur(vector<int>& s, int l, int r)
{
    if(l < r) {
        int i = l, j = r, x = s[l];  // x是本轮的中轴
        while(i < j) {
            while(j > i && s[j] >= x) {
                --j;
            }
            // 到这里可能是找到了s[j] < x, 也可能是j == i了
            if(j > i) {  // 确保是找到了s[j] < x
                s[i++] = s[j];
            }
            while(j > i && s[i] <= x) {
                ++i;
            }
            if(j > i) {  // 确保是找到了s[i] > x
                s[j++] = s[i];
            }
        }
        // 到这里必定有i == j
        s[i] = x;
        // 到这里x左边的都小于x，x右边的都大于x
        quickrecur(s, l, i - 1);
        quickrecur(s, i + 1, r);
    }
    return;
}

void QuickSort(vector<int>& s)
{
    for_each(s.begin(), s.end(), [](auto c){ cout << c << " "; }); cout << endl;
    quickrecur(s, 0, s.size() - 1);
    for_each(s.begin(), s.end(), [](auto c){ cout << c << " "; }); cout << endl;
}

void mergearray(vector<int>& a, int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}

/*
当进入这个函数时，可以认为s中的[l, m]是第一段排好序的
s中的[m + 1, r]是第二段排好序的；最终要把[l,r]排好序放到tmp中，
*/
void mergeArray(vector<int>& s, int tmp[], int l, int m, int r)
{
    // 剩下的就是将升序数组合并操作了,
    // 经典的合并两个有序数组代码，必须牢记
    // 原始问题是否是原地合并？
    int i = l, j = m + 1, k = l;
    while(k < r + 1) {
        if(j <= r) {
            while(i <= m && s[i] <= s[j])
                tmp[k++] = s[i++];
        }
        if(i <= m) {
            while(j <= r && s[j] <= s[i])
                tmp[k++] = s[j++];
        }
        if(i > m || j > r) {
            while(j <= r)
                tmp[k++] = s[j++];
            while(i <= m)
                tmp[k++] = s[i++];    
        }
    }
    
    // 最后把排好序的tmp[l, r]再放回s中
    /* 
    错误示范一
    while(k > l) {
        s[l + k - 1] = tmp[l + k - 1];
        --k;
    }
    错误示范二
    for (i = 0; i < k; i++)
	    s[l + i] = tmp[i];
    */
    // 正确示范一 
    for(int c = l; c < k; c++)
        s[c] = tmp[c]; 
	
    for_each(s.begin(), s.end(), [](auto c){ cout << c << " "; }); cout << endl;
    return;
}

void mergesort(vector<int>& s, int l, int r, int tmp[])
{
    if(l < r) {
        int mid = (l + r) / 2;
        mergesort(s, l, mid, tmp);
        mergesort(s, mid + 1, r, tmp);
        // mergearray(s, l, mid, r, tmp);
        mergeArray(s, tmp, l, mid, r);
    }
    /* 
    else if(l == r) {
        tmp[l] = s[l];
    }
    return;
    */
}

/*
归并排序的过程是: 递归拆分 + 合并
需要用到一个辅助数组
*/
void MergeSort(vector<int>& s)
{
    int size = s.size();
    if(size == 0 || size == 1)
        return;
    for_each(s.begin(), s.end(), [](auto c){ cout << c << " "; }); cout << endl;
    int* tmp = new int[size];
    // memset(tmp, 0, size);
    mergesort(s, 0, size - 1, tmp);
    for_each(s.begin(), s.end(), [](auto c){ cout << c << " "; }); cout << endl;
    delete[] tmp;
    tmp = nullptr;
    return;
}