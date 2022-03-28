class Solution:
  
    def transpose(self, matrix: List[List[int]]):
      for i in range(0, len(matrix), 1):
        for j in range(0, i, 1):
          tmp = matrix[i][j]
          matrix[i][j] = matrix[j][i]
          matrix[j][i] = tmp
          
    def reversal(self, matrix: List[List[int]]):
      for i in range(0, len(matrix), 1):
        matrix[i] = matrix[i][::-1]
          
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        self.transpose(matrix)
        self.reversal(matrix)
