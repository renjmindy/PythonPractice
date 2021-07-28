#!/usr/bin/env python
# coding: utf-8

# You are given an input list of strings, ordered by ascending length. Write a function that returns True if, for each pair of consecutive strings, the second string can be formed from the first by adding a **single letter** either at the **beginning or end**.
# 
# **Examples**
# 
# <code>
#     
#     can_build(["a", "at", "ate", "late", "plate", "plates"]) 
#     ➞ True
#     
#     can_build(["a", "at", "ate", "late", "plate", "plater", "platter"]) 
#     ➞ False# "platter" is formed by adding "t" in the middle of "plater"
#     
#     can_build(["it", "bit", "bite", "biters"]) 
#     ➞ False# "biters" is formed by adding two letters 
#     
#     - we can only add one
#     can_build(["mean", "meany"]) 
#     ➞ True
# 
# </code>
#     
# **Notes**
# 
# * Return False a word is **NOT** formed by adding **only one letter**.
# 
# * Return False if the letter is added to the **middle** of the previous word.
# 
# * Letters in tests will all be **lower case**.

# In[1]:


def cal_buildAword(s):
    
    for i in range(0, len(s)-1, 1):
        if len(s[i+1]) - len(s[i]) != 1:
            return False
        
    curr = ''
    prev = ''
    
    for i, j in enumerate(s):
        if i == 0:
            curr = j
        else:
            prev = curr
            curr = j
            print(prev, '-->', curr)
            if curr[1:] != prev and curr[0:-1] != prev:
                return False
            
    return True


# In[2]:


cal_buildAword(["a", "at", "ate", "late", "plate", "plates"])


# In[3]:


cal_buildAword(["a", "at", "ate", "late", "plate", "plater", "platter"])


# In[4]:


cal_buildAword(["it", "bit", "bite", "biters"])


# In[5]:


cal_buildAword(["mean", "meany"])


# In[ ]:




