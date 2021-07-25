#!/usr/bin/env python
# coding: utf-8

# Given an incomplete palindrome as a string, return the minimum letters needed to be added on to the end to make the string a palindrome.
# 
# **Examples**
# 
# minPalindromeSteps("race") ➞ 3
# 
# // Add 3 letters: "car" to make "racecar"
# 
# minPalindromeSteps("mada") ➞ 1
# 
# // Add 1 letter: "m" to make "madam"
# 
# minPalindromeSteps("mirror") ➞ 3
# 
# // Add 3 letters: "rim" to make "mirrorrim"
# 
# **Notes**
# 
# Trivially, words that are already palindromes should return 0.

# In[1]:


def cal_minSteps(s):
    
    slist = list(s)
    nlist = slist.copy()
    
    if slist == slist[::-1]:
        return 0
    
    for i, j in enumerate(slist):
        nlist.remove(j)
        if nlist == nlist[::-1]:
            return i + 1
    


# In[2]:


cal_minSteps("race")


# In[3]:


cal_minSteps("mada")


# In[4]:


cal_minSteps("mirror")


# In[ ]:




