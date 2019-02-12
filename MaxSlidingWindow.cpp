// https://leetcode.com/problems/sliding-window-maximum/
// Jan 21, 2019 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> resultVec;
        if(!nums.size()) return resultVec;
        for(int i=0; i<nums.size()-k+1; i++){ //O(nk)
            int maxNum = nums[i];
            for(int j=1; j<k && i+j < nums.size(); j++)
                maxNum = max(maxNum,nums[i+j]);
            resultVec.push_back(maxNum);
        }
        return resultVec;
    }
};