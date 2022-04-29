#include "main.h"

/*
算法 - Algorithms
排序算法:  快速排序、归并排序、计数排序
搜索算法:  回溯、递归、剪枝技巧
图论:     最短路、最小生成树、网络流建模
动态规划:  背包问题、最长子序列、计数问题
基础技巧:  分治、倍增、二分、贪心

数据结构 - Data Structures
数组与链表: 单/双向链表、跳舞链
栈与队列
树与图:    最近公共祖先、并查集
哈希表
堆:        大 / 小根堆、可并堆
字符串:    字典树、后缀树
*/

using namespace std;

int main(int argc, char**  argv)
{
    // TestVector();
    // TestList();
    // TestForwardList();
    // TestMap();
    // TestSet();
    // TestString();
    // TestUnorderedSet();
    vector<int> s;
    cout << "----- QuickSort -----" << endl;
    QuickSort(s);
    cout << "----- MergeSort -----" << endl;
    MergeSort(s);
    shared_ptr<int> p1(new int);
    auto p2 = p1;
    auto use = p2.use_count();
    cout << "p2.use_count: "  << use << endl;
    return 0;
}