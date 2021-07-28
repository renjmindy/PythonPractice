#!/usr/bin/env python
# coding: utf-8

# Given an array, create a function that returns an object detailing how many times each element was repeated. Sort the object by value in descending order.
# 
# **Examples**
# 
# countRepetitions(["cat", "dog", "cat", "cow", "cow", "cow"]) ➞ {"cow"=3, "cat"=2, "dog"=1}
# 
# countRepetitions([1, 5, 5, 5, 12, 12, 0, 0, 0, 0, 0, 0]) ➞ {0=6, 5=3, 12=2, 1=1}
# 
# countRepetitions(["Infinity", "null", "Infinity", "null", "null"]) ➞ {"null"=3, "Infinity"=2}
# 
# **Notes**
# 
# The array elements can be anything from string to numeric types.
# 
# The returned map object should be sorted in descending order by value.

# In[1]:


from collections import Counter
def cal_countRepetitions(s):
    
    return {k:v for k, v in sorted(dict(Counter(s)).items(), key=lambda x:x[1], reverse=True)}


# In[2]:


cal_countRepetitions(["cat", "dog", "cat", "cow", "cow", "cow"])


# In[3]:


cal_countRepetitions([1, 5, 5, 5, 12, 12, 0, 0, 0, 0, 0, 0])


# In[4]:


cal_countRepetitions(["Infinity", "null", "Infinity", "null", "null"])


# In[ ]:




