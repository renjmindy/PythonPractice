#!/usr/bin/env python
# coding: utf-8

# There's a great war between the even and odd numbers. Many numbers already lost their life in this war and it's your task to end this. You have to determine which group sums larger: the even, or the odd. The larger group wins.
# 
# Create a function that takes an array of integers, sums the even and odd numbers separately, then returns the difference between sum of even and odd numbers.
# 
# **Examples**
# 
# warOfNumbers([2, 8, 7, 5]) ➞ 2
# 
# // 2 + 8 = 10
# 
# // 7 + 5 = 12
# 
# // 12 is larger than 10
# 
# // So we return 12 - 10 = 2
# 
# warOfNumbers([12, 90, 75]) ➞ 27
# 
# warOfNumbers([5, 9, 45, 6, 2, 7, 34, 8, 6, 90, 5, 243]) ➞ 168
# 
# **Notes**
# 
# The given array contains only positive integers.

# In[1]:


def cal_diffEvsO(arr):
    
    return abs(sum([i for i in arr if i % 2 == 0]) - sum([i for i in arr if i % 2 != 0]))


# In[2]:


cal_diffEvsO([2, 8, 7, 5])


# In[3]:


cal_diffEvsO([12, 90, 75])


# In[4]:


cal_diffEvsO([5, 9, 45, 6, 2, 7, 34, 8, 6, 90, 5, 243])


# In[ ]:




