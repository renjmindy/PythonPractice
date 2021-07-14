#!/usr/bin/env python
# coding: utf-8

# Write a function that divides a phrase into word buckets, with each bucket containing n or fewer characters. Only include full words inside each bucket.
# 
# **Examples**
# 
# bucketize("she sells sea shells by the sea", 10)
# ➞ ["she sells", "sea shells", "by the sea"]
# 
# bucketize("the mouse jumped over the cheese", 7)
# ➞ ["the", "mouse", "jumped", "over", "the", "cheese"]
# 
# bucketize("fairy dust coated the air", 20)
# ➞ ["fairy dust coated", "the air"]
# 
# bucketize("a b c d e", 2)
# ➞ ["a", "b", "c", "d", "e"]
# 
# **Notes**
# 
# Spaces count as one character. Trim beginning and end spaces for each word bucket (see final example).
# 
# If buckets are too small to hold a single word, return an empty array: []
# 
# The final goal isn't to return just the words with a length equal (or lower) to the given n, but to return the entire given phrase bucketized (if possible). So, for the specific case of "by" the only word with a proper length, the phrase can't be bucketized, and the returned array has to be empty.

# In[1]:


def cal_wordBuckets(s, n):
    
    slist = list(s.split(' '))
    #print(slist)
    word_counter = 0
    nlist = []
    rlist = []
    
    for i, j in enumerate(slist):
        
        word_counter += (len(list(j)) + 1)
        
        if word_counter <= n:
            nlist.append(j)
            #print(nlist, word_counter)
        else:
            rlist.append(' '.join(nlist))
            word_counter = len(list(j))
            nlist.clear()
            nlist.append(j)
            #print('\t', nlist, word_counter)
            
    rlist.append(' '.join(nlist))
    
    return rlist


# In[2]:


cal_wordBuckets("she sells sea shells by the sea", 10)


# In[3]:


cal_wordBuckets("the mouse jumped over the cheese", 7)


# In[4]:


cal_wordBuckets("fairy dust coated the air", 20)


# In[5]:


cal_wordBuckets("a b c d e", 2)


# In[ ]:




