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
# Trivially, words which are already palindromes should return 0.

# In[1]:


def cal_minSteps(s):
    
    slist = list(s)
    counter = 0
    
    for i in range(0, len(slist), 1):
        rlist = slist[i:]
        if rlist != rlist[::-1]:
            counter += 1
        else:
            break
            
    return counter


# In[2]:


cal_minSteps("race")


# In[3]:


cal_minSteps("mada")


# In[4]:


cal_minSteps("mirror")


# In[ ]:




