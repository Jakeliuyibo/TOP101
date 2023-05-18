#include <bits/stdc++.h>


using namespace std;

/* 递归二分查找，找到两数组第k大元素     */
int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k)
{
    /* 保证num1长度不超过nums2长度  */
    if(nums1.size()-i > nums2.size()-j)
    {
        return find(nums2, j, nums1, i, k);
    }

    if(nums1.size() == i) return nums2[j+k-1];


    /* 终止条件 */
    if(k==1) return min(nums1[i], nums2[j]);

    int idx1 = min((int)nums1.size() ,i + k/2);
    int idx2 = j + k - k/2;
    if(nums1[idx1-1] < nums2[idx2-1])
    {
        return find(nums1, idx1, nums2, j, k-(idx1-i));
    }
    else
    {
        return find(nums1, i, nums2, idx2, k-(idx2-j));
    }

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();
    int m = nums2.size();
    int len = n + m;
    if(len%2 == 0)          // 偶数
    {
        int left  = find(nums1, 0, nums2, 0, len/2);
        int right = find(nums1, 0, nums2, 0, len/2+1);
        return (left + right) / 2.0;
    }
    else                    // 奇数
    {
        return find(nums1, 0, nums2, 0, len/2+1);
    }
}