# 36. Valid Sudoku
# https://leetcode.com/problems/valid-sudoku/description/

def isValidSudoku(self, board):
    """
    :type board: List[List[str]]
    :rtype: bool
    """
    def do_check(number_array):
        s_x, s_y, s_z = set(), set(), set()
        for n in number_array:
            if n[0] in s_x or n[1] in s_y or n[2] in s_z: return False
            s_x.add(n[0])
            s_y.add(n[1])
            s_z.add(n[2])
        return True
    def find_square(i, j):
        if i < 3:
            if j < 3: return 0
            if j > 2 and j < 6: return 1
            if j > 5: return 2
        if i > 2 and i < 6:
            if j < 3: return 3
            if j > 2 and j < 6: return 4
            if j > 5: return 5
        if i > 5: 
            if j < 3: return 6
            if j > 2 and j < 6: return 7
            if j > 5: return 8

    numbers = {str(i):[] for i in range(1,10)}
    for it,i in enumerate(board):
        for it2, j in enumerate(i):
            if(board[it][it2] != '.'):
                numbers[str(board[it][it2])].append([it, it2, find_square(it,it2)])
    for key in numbers.keys():
        number_array = numbers[key]
        if(not do_check(number_array)):
            return False
    return True 