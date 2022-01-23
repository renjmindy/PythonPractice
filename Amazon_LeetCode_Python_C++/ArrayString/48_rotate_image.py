class Solution:
    
    def tra(self, matrix: List[List[int]]) -> None:
        for i in range(len(matrix)):
            for j in range(i + 1, len(matrix), 1):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
                
    def ref(self, matrix: List[List[int]]) -> None:
        for i in range(len(matrix)):
            for j in range(len(matrix)//2):
                matrix[i][j], matrix[i][len(matrix) - 1 - j] = matrix[i][len(matrix) - 1 - j], matrix[i][j]
    
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        self.tra(matrix)
        self.ref(matrix)
