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
        
        if (sum_dL <= 0 and sum_dR <= 0) or (sum_dL + sum_dR <= 0):
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

# In[4]:


T = 1
N = [10]
L = [(105965242, 494136789, 450676517, 36179826, 473818721, 461541657, 144408199, 760779501, 863646256, 76190127)]
pile_up(T, N, L)


# No

# In[5]:


T = 1
N = [2]
L = [(63642354, 583909562)]
pile_up(T, N, L)


# Yes

# In[6]:


T = 1
N = [3]
L = [(427731488, 922935208, 973233245)]
pile_up(T, N, L)


# Yes

# In[7]:


T = 1
N = [100]
L = [(1000000875, 1000000842, 1000000812, 1000000748, 1000000746, 1000000728, 1000000715, 1000000688, 1000000678, 1000000662, 
      1000000632, 1000000620, 1000000617, 1000000593, 1000000593, 1000000591, 1000000577, 1000000575, 1000000575, 1000000519, 
      1000000478, 1000000457, 1000000439, 1000000420, 1000000397, 1000000368, 1000000363, 1000000349, 1000000330, 1000000308, 
      1000000302, 1000000250, 1000000242, 1000000233, 1000000231, 1000000197, 1000000168, 1000000150, 1000000148, 1000000138, 
      1000000112, 1000000080, 1000000015, 1000000010, 999999997, 999999982, 999999981, 999999955, 999999920, 999999915, 
      999999912, 999999904, 999999907, 999999915, 999999938, 999999943, 999999974, 999999981, 999999985, 1000000011, 1000000111, 
      1000000123, 1000000143, 1000000180, 1000000188, 1000000191, 1000000196, 1000000201, 1000000240, 1000000264, 1000000275, 
      1000000314, 1000000319, 1000000331, 1000000357, 1000000380, 1000000383, 1000000426, 1000000429, 1000000435, 1000000451, 
      1000000480, 1000000488, 1000000582, 1000000598, 1000000617, 1000000666, 1000000683, 1000000717, 1000000727, 1000000739, 
      1000000743, 1000000767, 1000000789, 1000000802, 1000000811, 1000000848, 1000000852, 1000000853, 1000000869)]
pile_up(T, N, L)


# Yes

# In[8]:


T = 1
N = [3]
L = [(488028917, 637472922, 617949858)]
pile_up(T, N, L)


# No

# In[ ]:




