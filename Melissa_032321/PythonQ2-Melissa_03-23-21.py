#!/usr/bin/env python
# coding: utf-8

# ## Q2: Set Theory: Even Power  Set

# ### Input Format
# 
# The first line contains **N** denoting the size of the array.
# 
# The next line contains **N** space-separated integers of the set.
# 
# 
# ### Sample Input
# 
# 3     -- denotes N
# 
# 1 2 3 -- denotes string S
# 
# 
# ### Constraints
# 
# 1 <= **N** <= 102
# 
# 1 <= **A[i]** <= 104
# 
# 
# ### Output Format
# 
# The output contains the number of sets from powerset having even size.
# 
# 
# ### Sample Output
# 
# 4
# 
# 
# ### Explanation
# 
# Power set has collection of all subsets including null set, i.e. 
# 
# P = {(), (1), (2), (3), (1,2), (1,3), (2,3), (1,2,3)}
# 
# Out of them, only 4 sets are of even size. 
# 
# They are: 
# 
# (): size 0.
# 
# (1,2), (1,3) and (2,3) of size 2.
# 
# Hence the output is **4**.

# In[ ]:


def powerSet(N, A):
    
    # this is default OUTPUT. You can change it
    
    result = -404
    
    # write your Logic here:
    
    
    
    # INPUT [uncomment & modify if required]
    N = int(input())
    temp = input().split()
    A = list(map(int, temp))
    
    # OUTPUT [uncomment & modify if required]
    print(powerSet(N,A))


# In[1]:


def powerSet(N, A):
    
    m = N // 2
    #print('m:', m)
    
    result = 0
    
    num = 1
    
    for a in A:
        num *= a
        
    #print('num:', num)
    
    for i in range(1, m+1, 1): 
        dem1 = 1
        dem2 = 1
        
        for j in range(1, i*2+1): 
            dem1 *= j
        for k in range(1, (N-(i*2))+1):
            dem2 *= k
            
        #print('dem1:', dem1)
        #print('dem2:', dem2)
            
        result += num / (dem1 * dem2)
        
        #print('\t div:', num / (dem1 * dem2))
        
    result += 1
    print(result)
    
    return result


# In[2]:


N = 3
A = [1, 2, 3]
powerSet(N, A)


# In[3]:


N = 1
A = [1]
powerSet(N, A)


# In[4]:


N = 6
A = [1, 2, 3, 4, 5, 6]
powerSet(N, A)


# In[5]:


N = 15
A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
powerSet(N, A)


# In[6]:


N = 5
A = [1, 2, 3, 4, 5]
powerSet(N, A)


# In[7]:


N = 9
A = [1, 2, 3, 4, 5, 6, 7, 8, 9]
powerSet(N, A)


# In[ ]:




