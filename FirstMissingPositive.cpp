// https://leetcode.com/problems/first-missing-positive/
// Jan 12, 2019
#include <set>
#include <vector>
#include <iostream>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        //runs in O(2n) => O(n) time 
        //first find smallest element and put all elements into a set 
        int smallestEl = INT_MIN;
        std::set<int> nums_set;
        for(int i=0; i<nums.size(); i++){
            nums_set.insert(nums[i]);
            if(smallestEl > nums[i])
                smallestEl = nums[i];
        }
        smallestEl = std::max(0,smallestEl);
        //count up from smallestEl until the first missing number
        while(nums_set.find(++smallestEl) != nums_set.end()){
            
        }
        return smallestEl;
    }
};
std::vector<int> make_vec(int* arr, int size){
    std::vector<int> ret_vec;
    for(int i=0; i<size; i++){
        ret_vec.push_back(arr[i]);
    }
    return ret_vec;
}
int main(){
    std::vector<std::vector<int> > tests;
    tests.push_back(std::vector<int>{-1,4,2,0,9}); //should be 1
    tests.push_back(std::vector<int>{1,2,3,4,6,7,9}); //should be 5
    tests.push_back(std::vector<int>{1,2,3,4,-1,6,7,9}); //should be 5
    tests.push_back(std::vector<int>{1,2,3,6,7,9,0}); //should be 4
    Solution sol;
    for(int i=0; i<tests.size(); i++){
        std::cout << "Array is: " ;
        for(int j=0; j<tests[i].size(); j++){
            std::cout << tests[i][j] << " " ;
        }
        std::cout << "\t answer is " << sol.firstMissingPositive(tests[i]) << std::endl;
    }
}
//to compile: g++ -std=c++11 FirstMissingPositive.cpp -o a.test