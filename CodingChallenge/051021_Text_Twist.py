#!/usr/bin/env python
# coding: utf-8

# In-Text Twist, players try to score points by forming words using the letters from a 6-letter scrambled word. They win the round if they can successfully unscramble the 6-letter word.
# 
# Create a function that takes in an array of already-guessed words, the unscrambled 6-letter word and returns the total number of points the player scored in a particular round using the following rubric:
# 
# 3-letter words are 1 pt
# 
# 4-letter words are 2 pts
# 
# 5-letter words are 3 pts
# 
# 6-letter words are 4 pts + 50 pt bonus (for unscrambling the word)
# 
# Remember that invalid words (words that cannot be formed from the 6-letter unscrambled words) count as 0 pts.
# 
# **Examples**
# 
# totalPoints(["cat", "create", "sat"], "caster") ➞ 2
# 
# // Since "create" is an invalid word.
# 
# totalPoints(["trance", "recant"], "recant") ➞ 108
# 
# // Since "trance" and "recant" score 54 pts each.
# 
# totalPoints(["dote", "dotes", "toes", "set", "dot", "dots", "sted"], "tossed") ➞ 13
# 
# // Since 2 + 3 + 2 + 1 + 1 + 2 + 2 = 13
# 
# **Notes**
# 
# If a 6-letter word has multiple anagrams, count each 6-letter unscramble as an additional 54 pts. For example, if the word is arches, and the player guessed arches and chaser, add 108 pts for both words

# In[1]:


from collections import Counter

def cal_textTwist(arr, s):
    
    sdict = dict(Counter(s))
    ddict = {3:1, 4:2, 5:3, 6:54}
    sum_scores = 0
    
    for a in arr:
        adict = dict(Counter(a))
        klist = list(adict.keys())
        not_found = False
        for k in klist:
            if k not in sdict.keys():
                not_found = True
                break
            else:
                if adict[k] > sdict[k]:
                    not_found = True
                    break
        if not_found == False:
            if len(klist) < 6:
                sum_scores += (len(klist) - 2)
            else:
                sum_scores += 54
        else:
            sum_scores += 0
            
    return sum_scores


# In[2]:


cal_textTwist(["cat", "create", "sat"], "caster")


# In[3]:


cal_textTwist(["trance", "recant"], "recant")


# In[4]:


cal_textTwist(["dote", "dotes", "toes", "set", "dot", "dots", "sted"], "tossed")


# In[ ]:




