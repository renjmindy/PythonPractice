#!/usr/bin/env python
# coding: utf-8

# ## Piling Up!
# 
# There is a horizontal row of **n** cubes. The length of each cube is given. You need to create a new vertical pile of cubes. The new pile should follow these directions: if **cube_i** is on top of **cube_j** then **sideLength_j >= sideLength_i**.
# 
# When stacking the cubes, you can only pick up either the leftmost or the rightmost cube each time. Print "Yes" if it is possible to stack the cubes. Otherwise, print "No". Do not print the quotation marks.
# 
# ### Input Format
# 
# The first line contains a single integer **T**, the number of test cases.
# 
# For each test case, there are **2** lines.
# 
# The first line of each test case contains **n**, the number of cubes.
# 
# The second line contains **n** space separated integers, denoting the sideLengths of each cube in that order.
# 
# ### Constraints 
# 
# **1 <= T <= 5**
# 
# **1 <= n <= 10^5**
# 
# **1 <= sideLength < 2^31**
# 
# ### Output Format
# 
# For each test case, output a single line containing either "Yes" or "No" without the quotes.
# 
# ### Sample Input
# 
# 2
# 
# 6
# 
# 4 3 2 1 3 4
# 
# 3
# 
# 1 3 2
# 
# ### Sample Output
# 
# Yes
# 
# No
# 
# ### Explanation
# 
# In the first test case, pick in this order: **left - 4, right - 4, left - 3, right - 3, left - 2, right - 1**.
# 
# In the second test case, no order gives an appropriate arrangement of vertical cubes. **3** will always come after either **1** or **2**.

# In[1]:


def pile_up(T, n, l):
    
    result = []
    
    for t in range(0, T):
        
        sum_dL = 0
        sum_dR = 0
        
        dLList = []
        dRList = []
        
        for ni in range(0, (N[t]//2)-1, 1):
            dLList.append(L[t][ni+1] - L[t][ni])
            #print(t, ' ', L[t][ni+1], ' ', L[t][ni])
            
        for ni in range(N[t]-1, N[t]//2, -1):
            dRList.append(L[t][ni-1] - L[t][ni])
            #print(t, ' ', L[t][ni-1], ' ', L[t][ni])
            
        #print(dLList, ' ', dRList)
            
        sum_dL = sum(dLList)
        sum_dR = sum(dRList)
        
        #print (sum_dL, ' ', sum_dR)
        
        if (sum_dL < 0 and sum_dR < 0) or (sum_dL + sum_dR < 0):
            result.append('Yes')
        else:
            result.append('No')
            
    return result


# In[2]:


T = 2
N = [6, 3]
L = [(4, 3, 2, 1, 3, 4), (1, 3, 2)]
pile_up(T, N, L)


# Yes
# 
# No

# In[3]:


T = 1
N = [10]
L = [(1000000842, 1000000721, 1000000671, 1000000663, 1000000626, 1000000520, 1000000126, 999999978, 1000000266, 1000000501)]
pile_up(T, N, L)


# Yes

# In[ ]:




