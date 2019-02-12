# 17. Phone number combinations 
# https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

def letterCombinations(self, digits):
    """
    :type digits: str
    :rtype: List[str]
    """
    combos = {'0':[' '], '1':[], '2':['a','b','c'], '3':['d','e','f'], '4':['g','h','i'],
              '5':['j','k','l'], '6':['m','n','o'], '7':['p','q','r','s'],
              '8':['t','u','v'], '9':['w','x','y','z']}
    outputs = ['']
    for digit in digits:
        buffer_outputs = [ ]
        for letter in combos[digit]:
            for existing_str in outputs:
                buffer_outputs.append(existing_str+letter)
        outputs = buffer_outputs
    if(len(outputs) == 1 and digits != '0'): # check for stupid edge case
        outputs = [ ]
    return outputs