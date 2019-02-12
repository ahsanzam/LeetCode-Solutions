# 1. TwoSum
# https://leetcode.com/problems/two-sum/description/

def twoSum(self, nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    for it,i in enumerate(nums[:-1]):
        for jt, j in enumerate(nums[it+1:]):
            if(j+i == target): 
                return [it,jt+it+1]        
    # given assumption that there is always a solution