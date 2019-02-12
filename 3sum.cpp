//3Sum
//Solved by me on Jan 16, 2019
//https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<vector<int>> solutionSet;
        std::vector<vector<int>> solutionVec;
        if(nums.size() < 3) return solutionVec;
        std::sort(nums.begin(), nums.end()); //O(nlong)
        for(int i=0; i<nums.size()-2; i++){ //O(n^2)
            int left = i+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[left]+nums[right]+nums[i];
                if(sum == 0){
                    solutionSet.insert(vector<int>{nums[left],nums[right],nums[i]});
                    right--; left++;
                }
                else if(sum > 0) right--;
                else left++;
            }
        }
        for(std::set<vector<int>>::iterator i=solutionSet.begin(); i!=solutionSet.end(); i++) //O(n)
            solutionVec.push_back(*i);
        return solutionVec;
    }
};