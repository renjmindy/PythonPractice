#!/usr/bin/env python
# coding: utf-8

# Write a function that receives an array of letters, an array of words (dictionary) and a mask. Return an array of words, sorted alphabetically, that match the given mask.
# 
# **Examples**
# 
# scrambled(['e', 'c', 'd', 'r', 'e', 'e'], [”red”, “dee”, “cede”, “reed”, “creed”, “decree”], “\*re\*\*”) ➞ [“creed”]
# 
# scrambled(['e', 'c', 'd', 'r', 'e', 'e'], [”red”, “dee”, “cede”, “reed”, “creed”, “decree”], “\*\*\*”) ➞ [“dee”, “red”]
# 
# **Notes**
# 
# The length of a mask will never exceed the number of letters given (or the longest word in the dictionary).

# In[1]:


def cal_scrambledLetters(arr1, arr2, s):
    
    slist = list(s)
    nlist = []
    
    for a in arr2:
        if len(a) == len(slist):
            nlist.append(a)
            
    return nlist


# In[2]:


cal_scrambledLetters(['e', 'c', 'd', 'r', 'e', 'e'], ['red', 'dee', 'cede', 'reed', 'creed', 'decree'], '*re**')


# In[3]:


cal_scrambledLetters(['e', 'c', 'd', 'r', 'e', 'e'], ['red', 'dee', 'cede', 'reed', 'creed', 'decree'], '***')


# In[ ]:




