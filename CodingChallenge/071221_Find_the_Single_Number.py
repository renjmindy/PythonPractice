#!/usr/bin/env python
# coding: utf-8

# Write a function that accepts an array of numbers (where each number appears three times except for one which appears only once) and finds that unique number in the array and returns it.
# 
# **Examples**
# 
# singleNumber([2, 2, 3, 2]) ➞ 3
# 
# singleNumber([0, 1, 0, 1, 0, 1, 99]) ➞ 99
# 
# singleNumber([-1, 2, -4, 20, -1, 2, -4, -4, 2, -1]) ➞ 20
# 
# **Notes**
# 
# The function needs to be efficient in order to run under 12,000 milliseconds.

# In[1]:


from collections import Counter

def cal_singleNumber(arr):
    
    aDict = dict(Counter(arr))
    #minimum = min(sorted(aDict, key=aDict.get))
    minimum = sorted(aDict.items(), key=lambda x:x[1])[0][0]
    
    return minimum


# In[2]:


cal_singleNumber([2,2,3,2])


# In[3]:


cal_singleNumber([0,1,0,1,0,1,99])


# In[4]:


cal_singleNumber([-1,2,-4,20,-1,2,-4,-4,2,-1])


# In[ ]:




