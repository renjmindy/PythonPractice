#!/usr/bin/env python
# coding: utf-8

# Write a recursive function that takes a string input and returns the string in a reversed case and order.
# 
# **Examples**
# 
# invert("dLROW YM sI HsEt") ➞ "TeSh iS my worlD"
# 
# invert("ytInIUgAsnOc") ➞ "CoNSaGuiNiTY"
# 
# invert("step on NO PETS") ➞ "step on NO PETS"
# 
# invert("XeLPMoC YTiReTXeD") ➞ "dExtErIty cOmplEx"
# 
# **Notes**
# 
# No empty strings and will neither contain special characters nor punctuation.
# 
# You are expected to solve this challenge using a recursive approach.
# 
# You can check on the Resources tab for more details about recursion in Java.

# In[1]:


def cal_caseANDindex(s):
    
    slist = list(s)
    nlist = []
    
    for s in slist:
        if s.islower():
            nlist.append(s.upper())
        else:
            nlist.append(s.lower())
            
    return ''.join(nlist[::-1])


# In[2]:


cal_caseANDindex("dLROW YM sI HsEt")


# In[3]:


cal_caseANDindex("ytInIUgAsnOc")


# In[4]:


cal_caseANDindex("step on NO PETS")


# In[5]:


cal_caseANDindex("XeLPMoC YTiReTXeD")


# In[ ]:




