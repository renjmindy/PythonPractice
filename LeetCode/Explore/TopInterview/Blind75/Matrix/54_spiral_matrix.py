class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = list()
        l, t, r, b = 0, 0, len(matrix[0]) - 1, len(matrix) - 1
        
        while len(ans) < len(matrix) * len(matrix[0]):
          
          for j in range(l, r + 1, 1):
            ans.append(matrix[t][j])
            
          for i in range(t + 1, b + 1, 1):
            ans.append(matrix[i][r])
            
          if t < b:
            for j in range(r - 1, l - 1, -1):
              ans.append(matrix[b][j])
              
          if l < r:
            for i in range(b - 1, t, -1):
              ans.append(matrix[i][l])
              
          l += 1
          r -= 1
          t += 1
          b -= 1
              
        return ans
