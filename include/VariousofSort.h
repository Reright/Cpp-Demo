#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <numeric>
#include "time.h"

using namespace std;

/* 挖坑填数法, 直观易懂, 
* 不用交换数据
*/
void QuickSort(vector<int>& arr, int l, int r)
{
    if(l < r) {
        int i = l, j = r, x = arr[l];
        while(i < j) {
            while(i < j && arr[j] >= x)
                j--;
            // 此时arr[j]是小于x的, 需要被换到左边;
            // 此时"坑"是arr[i];
            if(i < j)
                arr[i++] = arr[j];
            while(i < j && arr[i] < x)
                i++;
            // 此时arr[i]是大于x的, 需要被换到后边
            // 此时"坑"是arr[j]
            if(i < j)
                arr[j--] = arr[i];
        }
        // 当从上面的while出来,必定有i==j
        arr[i] = x;
        // for_each(arr.begin(), arr.end(), [](auto c){ cout << c << " "; }); cout << endl;
        QuickSort(arr, l, i - 1);  // i == j, 刚好重合, 不用包含在任何一半中
        QuickSort(arr, i + 1, r);
    }
    return;
}

/*
* 可以随机选取pivot, 代码很简洁.
* 要注意区间的划分, 必须是[l,j]和[j+1, r]
*/
void QuickSortRandom(vector<int>& arr, int l, int r)
{
    if(l < r) {
        // int pivot = l;  // 每次都选择最左边的元素作为基准
        int pivot = rand() % (r - l + 1) + l; // 从l到r中选一个随机元素出来
        int x = arr[pivot];
        int i = l - 1, j = r + 1;
        while(i < j) {
            do i++; while (arr[i] < x);
            do j--; while (arr[j] > x);
            if (i < j)
                swap(arr[i], arr[j]);
        }
        QuickSortRandom(arr, l, j);  // j必须包含在左边
        QuickSortRandom(arr, j + 1, r);
    }
    return;
}

/* 
 * 先随机选取一个基准值,目标是把比基准值小的都放在左边, 大的放在右边;
 * 刚开始先把基准跟最左边的元素互换, 目的是使得夹逼的过程不受自身的干扰;
 * 然后从右边开始,在遇到左指针之前找一个比基准值小的数,停下;
 * 再从左边开始, 在遇到右指针之前找一个比基准值大的数,停下;
 * 如果左右指针不重合, 交换他们; 重复上述过程,直到左右指针交汇;
 * 左右指针交汇时, 由于是右指针先移动的,所以可以保证交汇处一定有a[i] < a[left];
 * 可以放心的交换a[i]和a[left];此时i的左侧都比a[i]小,右侧都比a[i]大
 * 为什么说"由于是右指针先移动的,所以可以保证交汇处一定有a[i] < a[left]"呢?
 * 假设一种极限情况,j在遇到i之前,一直都是比基准大的,那么i不用移动,j过来直接交汇;
 * 此时i == j == left, 那么a[i]和a[left]交换没有问题;但如果这种情况下i先移动,那么不管在哪里
 * 停下, i == j时,必定有a[i] > a[l]的, 则不能正确的交换.
 * 同理, 可以把基准值放到最右侧, 让左侧指针先移动,也是对的
 */
void QuickSortSwap(vector<int>& arr, int l , int r) {
    if(l >= r) return;
    int index = rand()%(r-l+1) + l; // 随机产生一个下标
    int pivot = arr[index];   // 把它作为哨兵
    swap(arr[l], arr[index]); // 注意：先把它放在最前面
    int i=l, j=r;
    while(i<j){
        // 注意：先移动右边j，这样while结束后i处是比pivot小的数字，才可以与pivot交换
        while(i<j && arr[j]>=pivot) // 注意：大于等于的放右边
            j--;
        while(i<j && arr[i]<=pivot) // 小于等于的放左边
            i++;
        if(i!=j) // 最多i==j
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[i]); // 再把start处的pivot放在中间
    QuickSortSwap(arr, l, i-1);
    QuickSortSwap(arr, i+1, r); // 注意：i已经排过序
    return ;
}

static void mergearray(vector<int>& a, int first, int mid, int last, int tmp[], int b)
{
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;
    while(i <= m && j <= n) {
        if(a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while(i <= m)
        tmp[k++] = a[i++];
    while(j <= n)
        tmp[k++] = a[j++];
    for(i = 0; i < k; i++)
        a[first + i] = tmp[i];
}

static void mergesort(vector<int>& a, int first, int last, int tmp[], int b)
{
    if(first < last) {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, tmp, 0);  // 左边有序
        mergesort(a, mid + 1, last, tmp, 0);  // 右边有序
        mergearray(a, first, mid, last, tmp, 0);  // 再将两个有序数列合并
    }
}

static void MergeSort(vector<int>& a, int n)
{
    int* p = new int[n];  // 开辟这块空间重复使用,可以削减内存使用量
    mergesort(a, 0, n - 1, p, 0);  // idx: [0, n-1]
    delete[] p;
    return;
}

void InsertSort(vector<int>& a, int n)
{
    int i, j;
    // 甚至不需要判断n是否为0或1
    for (i = 1; i < n; i++) {
        for (j = i; j >= 1 && a[j] < a[j - 1]; j--)
            swap(a[j], a[j - 1]);
    }
}

void CountSort(vector<int>& nums) {
    int size = nums.size();
    int mi = *min_element(nums.begin(), nums.end());
    int ma = *max_element(nums.begin(), nums.end());
    int hash[ma - mi + 1];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < size; i++) {
        hash[nums[i] - mi]++;
    }
    int k = 0, l = 0;
    while (l < ma - mi + 1) {
        while (hash[l]--)
            nums[k++] = l + mi;
        l++;
    }
    return;
}

void ShowNums(vector<int>& nums)
{
    for_each(nums.begin(), nums.end(), [](auto c){ cout << c << " "; });
    cout << endl;
}

void TestVariousofSort()
{
    const int nsize = 8;
    vector<int> nums;
    srand((unsigned int)time(NULL));
    int i;
    for (i = 0; i < nsize; i++)
        nums.push_back(rand() % 100 + 1);
    
    cout << "\n------QuickSort 1------" << endl;
    ShowNums(nums);
    QuickSort(nums, 0, nsize - 1);
    ShowNums(nums);

    for (i = 0; i < nsize; i++)
        nums[i] = rand() % 100 + 1;
    cout << "\n------QuickSort 2------" << endl;
    ShowNums(nums);
    QuickSortRandom(nums, 0, nsize - 1);
    ShowNums(nums);

    for (i = 0; i < nsize; i++)
        nums[i] = rand() % 100 + 1;
    cout << "\n------QuickSort 3------" << endl;
    ShowNums(nums);
    QuickSortSwap(nums, 0, nsize - 1);
    ShowNums(nums);
}


void* MemMove(void* dest,  void* src, int len) {
	if (dest == NULL || src == NULL || len <= 0)
		return NULL;	
	if (dest < src) {
		char* d = (char*)dest;
		char* s = (char*)src;
		while (len--)
			*d++ = *s++;
	} else {
		char* d = (char*)dest + len;
		char* s = (char*)src + len;
		while (len--)
			*--d = *--s;
	}
	return dest;
}
