class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for i in range(len(matrix)):
            if target < matrix[i][0]:
                break
            else:
                if target in matrix[i]:
                    return True
        return False
