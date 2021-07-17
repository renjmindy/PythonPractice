#!/usr/bin/env python
# coding: utf-8

# Suppose a pair of identical characters serve as bookends for all characters in between them. Write a function that returns the total number of unique characters (books, so to speak) between all pairs of book ends.
# 
# The function will look like:
# 
# countUniqueBooks("stringSequence", "bookEnd")
# 
# **Examples**
# 
# countUniqueBooks("AZYWABBCATTTA", 'A') ➞ 4
# 
# // 1st bookend group: "AZYWA" : 3 unique books: "Z", "Y", "W"
# 
# // 2nd bookend group: "ATTTA": 1 unique book: "T"
# 
# // "ABBCA" not included since the first "A" was used in the 1st bookend group.
# 
# countUniqueBooks("$AA$BBCATT$C$$B$", '$') ➞ 3
# 
# countUniqueBooks("ZZABCDEF", 'Z') ➞ 0
# 
# **Notes**
# 
# No book characters will be identical to the bookend character.
# 
# There will always be an even number of bookends.
# 
# Once a bookend is used to complete a pair, a new bookend must be found to create another pair.
# 
# Return 0 if bookends contain zero books.

# In[1]:


def cal_books(arr, s):
    
    alist = list(arr)
    nini = -1
    nend = -1
    suml = 0
    
    for i, j in enumerate(alist):
        if j == s:
            if nini < 0:
                nini = i
            else:
                nend = i
                #print(list(set(alist[nini+1:nend])))
                suml += len(list(set(alist[nini+1:nend])))
                nini = -1
                nend = -1
                
    return suml


# In[2]:


cal_books("AZYWABBCATTTA", 'A')


# In[3]:


cal_books("ZZABCDEF", 'Z')


# In[ ]:




