#!/usr/bin/env python
# coding: utf-8

# Given array of distinct integers, print all permutations of the array.
# 
# For example : array : [10, 20, 30]
# 
# Permutations are :
# 
# [10, 20, 30], [10, 30, 20], [20, 10, 30], [20, 30, 10], [30, 10, 20], [30, 20, 10]
# 
# Pick up an array of your choice and write the code that will print all the permutations.

# In[1]:


from itertools import permutations 
def cal_permutation(arr):
    
    a = permutations(arr, 3)
    
    return [i for i in a]


# In[2]:


print(cal_permutation([10, 20, 30]))


# In[ ]:




