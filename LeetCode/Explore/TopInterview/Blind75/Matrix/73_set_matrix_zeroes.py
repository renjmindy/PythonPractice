class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rp, cp = set(), set()
        
        for i in range(len(matrix)):
          for j in range(len(matrix[0])):
            if matrix[i][j] == 0:
              rp.add(i)
              cp.add(j)
              
        for i in range(len(matrix)):
          for j in range(len(matrix[0])):
            if i in rp or j in cp:
              matrix[i][j] = 0
