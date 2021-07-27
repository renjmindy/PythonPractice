#!/usr/bin/env python
# coding: utf-8

# This classic problem dates back to Roman times. There are 41 soldiers arranged in a circle. Every third soldier is to be killed by their captors, continuing around the circle until only one soldier remains. He is to be freed. Assuming you would like to stay alive, at what position in the circle would you stand?
# 
# Generalize this problem by creating a function that accepts the number of soldiers n and the interval at which they are killed i, and returns the position of the fortunate survivor.
# 
# **Examples**
# 
# josephus(41, 3) ➞ 31
# 
# josephus(35, 11) ➞ 18
# 
# josephus(11, 1) ➞ 11
# 
# josephus(2, 2) ➞ 1
# 
# **Notes**
# 
# Assume the positions are numbered 1 to n going clockwise around the circle.
# 
# If the interval is 3, the first soldiers to die are at positions 3, 6, and 9.

# In[1]:


def cal_josephus(n1, n2):
    
    plist = list(range(1, n1+1,1))
    idx = n2 - 1
    
    while len(plist) > 1:
        plist.pop(idx)
        idx += (n2 - 1)
        idx %= len(plist)
    
    return plist[-1]


# In[2]:


cal_josephus(41, 3)


# In[3]:


cal_josephus(35, 11)


# In[4]:


cal_josephus(11, 1)


# In[5]:


cal_josephus(2, 2)


# In[ ]:




