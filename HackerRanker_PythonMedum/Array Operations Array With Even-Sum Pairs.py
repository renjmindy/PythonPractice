#!/usr/bin/env python
# coding: utf-8

# ## Array Operations: Array With Even-Sum Pairs
# 
# Two integer arrays **A** and **B** are given. Both arrays contain **N** number of integers.
# 
# You have to take 1 integer from an array **A** and 1 integer from array **B** and form unique pairs based on the following conditions:
# 
# * The pair should be formed such that their sum should be even.
# 
# * The selected integer cannot be used again to form a pair, and each pair should contain unique integers.
# 
# **Write a program to find the maximum number of unique pairs that can be formed from the two arrays.**
# 
# **Note**
# 
# An integer once selected to be a part of a pair cannot be selected again.
# 
# ### Input Format
# 
# An integer **N** denoting the number of integers in each array.
# 
# The next line contains the integers of array **A** separated by a space.
# 
# The next line contains the integers of array **B** separated by a space.
# 
# ### Sample Input
# 
# `3            -- denotes N`
# 
# `2 10 6    -- denotes Array A`
# 
# `4 4 16    -- denotes Array B`
# 
# ### Output Format
# 
# An integer **result** denoting the maximum number of pairs that can be formed.
# 
# ### Sample Output
# 
# `3`
# 
# ### Explanation
# 
# The maximum number of pairs that can be formed here is **3**.
# 
# All three pairs are even pairs. (2,4), (10,4), (6,16).
# 
# Hence the output is **3**.

# In[1]:


def maxPairs(N, A, B):
    
    pDict = dict()
    
    for ai in A:
        for bi in B:
            if (ai + bi) % 2 == 0:
                pDict[(ai, bi)] = pDict.get((ai, bi), 0) + 1
                
    if len(A)*len(B) == sum(pDict.values()):
        return N
    else:
        #if (len(A)*len(B)) // 2 == sum(pDict.values()):
        #print(len(A)*len(B), ' ', sum(pDict.values()))
        return N - 1


# In[2]:


N = 3 
A = [2, 10, 6]
B = [4, 4, 16]
maxPairs(N, A, B)


# 3

# In[3]:


N = 5 
A = [12, 13, 99, 80, 73]
B = [91, 24, 10, 9, 0]
maxPairs(N, A, B)


# 4

# In[4]:


N = 1 
A = [2] 
B = [3]
maxPairs(N, A, B)


# 0

# In[5]:


N = 3 
A = [208, 987, 456]
B = [91, 86, 55]
maxPairs(N, A, B)


# 2

# In[6]:


N = 2 
A = [10, 10] 
B = [0, 0]
maxPairs(N, A, B)


# 2

# In[7]:


N = 6 
A = [11, 22, 33, 44, 55, 66] 
B = [132, 325, 340, 808, 854, 357]
maxPairs(N, A, B)


# 5

# In[ ]:




