// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i=0; i<nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        std::sort(nums1.begin(), nums1.end());
        if(nums1.size() % 2 == 0){
            return ( nums1[nums1.size()/2-1] + nums1[ (nums1.size()/2)  ]) / 2.00 ;
        }
        else 
            return nums1[nums1.size()/2];
    }
};