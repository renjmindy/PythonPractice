#!/usr/bin/env python
# coding: utf-8

# Suppose a hash # represents the BACKSPACE key being pressed. Write a function that transforms a string containing # into a string without any #.
# 
# **Examples**
# 
# erase("he##l#hel#llo") ➞ "hello"
# 
# erase("major# spar##ks") ➞ "majo spks"
# 
# erase("si###t boy") ➞ "t boy"
# 
# erase("####") ➞ ""
# 
# **Notes**
# 
# In addition to characters, backspaces can also remove whitespaces.
# 
# If the number of hashes exceeds the previous characters, remove those previous characters entirely (see example #3).
# 
# If there only exist backspaces, return an empty string

# In[1]:


def cal_backspaceAttack(s):
    
    slist = list(s)
    nlist = []
    
    for i, j in enumerate(slist):
        if j != '#':
            nlist.append(j)
        else:
            if nlist:
                del nlist[-1]
            
    return ''.join(nlist)


# In[2]:


cal_backspaceAttack("he##l#hel#llo")


# In[3]:


cal_backspaceAttack("major# spar##ks")


# In[4]:


cal_backspaceAttack("si###t boy")


# In[5]:


cal_backspaceAttack("####")


# In[ ]:




