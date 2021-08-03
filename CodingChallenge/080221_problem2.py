#!/usr/bin/env python
# coding: utf-8

# Write java Program to Find Smallest and Largest Element in an Array.
# 
# **Note** 
# 
# Number can not be repeated in the array.
# 
# **Example**
# 
# 1
# 2
# 3
# 4
# 5
# 6
# 
# int[] arr1={7,5,6,1,4,2}; Missing number : 3
# 
# int[] arr2={5,3,1,2}; Missing number : 4

# In[1]:


def cal_missNum(a):
    
    a.sort()
    
    for i in range(len(a)-1):
        if a[i+1] - a[i] > 1:
            return a[i] + 1


# In[2]:


cal_missNum([7,5,6,1,4,2])


# In[3]:


cal_missNum([5,3,1,2])


# In[ ]:




