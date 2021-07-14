#!/usr/bin/env python
# coding: utf-8

# Create a function that takes a number num and returns each place value in the number.
# 
# **Examples**
# 
# numSplit(39) ➞ [30, 9]
# 
# numSplit(-434) ➞ [-400, -30, -4]
# 
# numSplit(100) ➞ [100, 0, 0]
# 
# numSplit(121317) ➞ [100000, 20000, 1000, 300, 10, 7]

# In[1]:


def cal_splitNumbers(n):
    
    nlist = list(str(abs(n)))
    #print(nlist, len(nlist))
    rlist = []
    
    for i, j in enumerate(nlist):
        rlist.append(int(j)*10**(len(nlist)-i-1))
    
    if n > 0:
        return rlist
    else:
        return list(map(lambda x:x*(-1), rlist))


# In[2]:


cal_splitNumbers(39)


# In[3]:


cal_splitNumbers(-434)


# In[4]:


cal_splitNumbers(100)


# In[5]:


cal_splitNumbers(121317)


# In[ ]:




