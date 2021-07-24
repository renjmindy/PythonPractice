#!/usr/bin/env python
# coding: utf-8

# Write a function that returns the next number that can be created from the same digits as the input.
# 
# **Examples**
# 
# nextNumber(19) ➞ 91
# 
# nextNumber(3542) ➞ 4235
# 
# nextNumber(5432) ➞ 5432
# 
# nextNumber(58943) ➞ 59348
# 
# **Notes**
# 
# If no larger number can be formed, return the number itself.
# 
# Bonus: See if you can do this without generating all digit permutations.

# In[1]:


def cal_nextNumber(n):
    
    nlist = list(str(n))
    snlist = sorted(nlist)
    
    current = nlist[0]
    nextNum = max(nlist)
    
    if current == nextNum:
        return n
    elif nlist[1] == nextNum:
        fNum = snlist[snlist.index(current)+1]
        snlist.remove(fNum)
        return int(fNum + ''.join(snlist))
    else:
        fNum = snlist[snlist.index(current)]
        sNum = snlist[snlist.index(nextNum)] 
        snlist.remove(current)
        snlist.remove(nextNum)
        return int(fNum + sNum + ''.join(snlist))


# In[2]:


cal_nextNumber(19)


# In[3]:


cal_nextNumber(3542)


# In[4]:


cal_nextNumber(5432)


# In[5]:


cal_nextNumber(58943)


# In[ ]:




