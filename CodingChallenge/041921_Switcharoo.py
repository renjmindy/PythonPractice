#!/usr/bin/env python
# coding: utf-8

# Create a function that takes a string and returns a new string with its first and last characters swapped, except under two conditions:
# 
# If the length of the string is less than two, return "Incompatible.".
# 
# If the first and last characters are the same, return "Two's a pair.".
# 
# **Examples**
# 
# flipEndChars("Cat, dog, and mouse.") ➞ ".at, dog, and mouseC"
# 
# flipEndChars("ada") ➞ "Two's a pair."
# 
# flipEndChars("Ada") ➞ "adA"
# 
# flipEndChars("z") ➞ "Incompatible."
# 
# **Notes**
# 
# Tests are case sensitive (e.g. "A" and "a" are not the same character).

# In[1]:


def cal_stringReverse(s):
    
    if len(list(s)) < 2:
        return 'Incompatible.'
    
    elif list(s)[0] == list(s)[-1]:
        return 'Two\'s a pair.'
    
    else:
        return ''.join(list(s[-1]) + list(s[1:-1]) + list(s[0]))


# In[2]:


cal_stringReverse("Cat, dog, and mouse.")


# In[3]:


cal_stringReverse("ada")


# In[4]:


cal_stringReverse("Ada")


# In[5]:


cal_stringReverse("z")


# In[ ]:




