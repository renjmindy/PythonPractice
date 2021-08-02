#!/usr/bin/env python
# coding: utf-8

# Given two Strings A and B. Find the length of the Longest Common Subsequence (LCS) of the given Strings. Input: A = Minneapolis, B = Minnesota.

# In[1]:


def cal_longestS(s1, s2):
    
    maxLen = max(len(s1), len(s2))
    i = 0
    
    while i < maxLen:
        if s1[0:i+1] != s2[0:i+1]:
            return s1[0:i]
        i += 1


# In[2]:


cal_longestS('Minneapolis', 'Minnesota')


# In[ ]:




