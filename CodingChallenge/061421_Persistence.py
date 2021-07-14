#!/usr/bin/env python
# coding: utf-8

# The additive persistence of an integer, n, is the number of times you have to replace n with the sum of its digits until n becomes a single-digit integer.
# 
# The multiplicative persistence of an integer, n, is the number of times you have to replace n with the product of its digits until n becomes a single-digit integer.
# 
# Create two functions that take an integer as an argument and:
# 
# Return its additive persistence.
# 
# Return its multiplicative persistence.
# 
# **Examples: Additive Persistence**
# 
# additivePersistence(1679583) ➞ 3
# 
# // 1 + 6 + 7 + 9 + 5 + 8 + 3 = 39
# 
# // 3 + 9 = 12
# 
# // 1 + 2 = 3
# 
# // It takes 3 iterations to reach a single-digit number.
# 
# additivePersistence(123456) ➞ 2
# 
# // 1 + 2 + 3 + 4 + 5 + 6 = 21
# 
# // 2 + 1 = 3
# 
# additivePersistence(6) ➞ 0
# 
# // Because 6 is already a single-digit integer.
# 
# **Examples: Multiplicative Persistence**
# 
# multiplicativePersistence(77) ➞ 4
# 
# // 7 x 7 = 49
# 
# // 4 x 9 = 36
# 
# // 3 x 6 = 18
# 
# // 1 x 8 = 8
# 
# // It takes 4 iterations to reach a single-digit number.
# 
# multiplicativePersistence(123456) ➞ 2
# 
# // 1 x 2 x 3 x 4 x 5 x 6 = 720
# 
# // 7 x 2 x 0 = 0
# 
# multiplicativePersistence(4) ➞ 0
# 
# // Because 4 is already a single-digit integer.
# 
# **Notes**
# 
# The input n is never negative.

# In[1]:


def cal_addPersistence(n):
    
    nlist = list(str(n))
    #print(nlist)
    counter = 0
    
    if len(nlist) <= 1:
        return 0
    else:
        while len(nlist) > 1:
            counter += 1
            sumN = 0
            sumN = sum([int(i) for i in nlist])
            nlist = list(str(sumN))
            #print(nlist)
        return counter


# In[2]:


cal_addPersistence(1679583)


# In[3]:


cal_addPersistence(123456)


# In[4]:


cal_addPersistence(6)


# In[5]:


from math import prod

def cal_mulPersistence(n):
    
    nlist = list(str(n))
    #print(nlist)
    counter = 0
    
    if len(nlist) <= 1:
        return 0
    else:
        while len(nlist) > 1:
            counter += 1
            prodN = 0
            prodN = prod([int(i) for i in nlist])
            nlist = list(str(prodN))
            #print(nlist)
        return counter


# In[6]:


cal_mulPersistence(77)


# In[7]:


cal_mulPersistence(123456)


# In[8]:


cal_mulPersistence(4)


# In[ ]:




