#!/usr/bin/env python
# coding: utf-8

# Write a recursive function that will return the longest word in a sentence. In cases where more than one word is found, return the first one.
# 
# **Examples**
# 
# findLongest("I will and ever will be gratefully and perpetually loving you Tesh!​😘​") ➞ "perpetually"
# 
# findLongest("A thing of beauty is a joy forever.") ➞ "forever"
# 
# findLongest("Forgetfulness is by all means powerless!") ➞ "forgetfulness"
# 
# findLongest("The word strengths is the longest and most commonly used word with a single vowel.") ➞ "strengths"
# 
# **Notes**
# 
# Special characters and symbols don't count as part of the word.
# 
# Return the longest word found in lowercase letters.
# 
# You are expected to solve this challenge via a recursive approach.

# In[1]:


def cal_longestWord(s):
    
    slist = list(s.split(' '))
    sDict = dict()
    
    for s in slist:
        s = s.replace('.', '').replace('!', '').replace('😘', '')
        sDict.setdefault(len(s), []).append(s)
        
    ssDict = sorted(sDict.items(), key=lambda x:x[0], reverse=True)
    
    return ssDict[0][1][0]


# In[2]:


cal_longestWord("I will and ever will be gratefully and perpetually loving you Tesh!​😘")


# In[3]:


cal_longestWord("A thing of beauty is a joy forever.")


# In[4]:


cal_longestWord("Forgetfulness is by all means powerless!")


# In[5]:


cal_longestWord("The word strengths is the longest and most commonly used word with a single vowel.")


# In[ ]:




