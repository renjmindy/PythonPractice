#!/usr/bin/env python
# coding: utf-8

# Kevin and Stuart want to play the '**The Minion Game**'.
# 
# ### Game Rules
# 
# Both players are given the same string, **S**.
# 
# Both players have to make substrings using the letters of the string **S**.
# 
# Stuart has to make words starting with consonants.
# 
# Kevin has to make words starting with vowels.
# 
# The game ends when both players have made all possible substrings.
# 
# ### Scoring
# 
# A player gets +1 point for each occurrence of the substring in the string **S**.
# 
# ### For Example:
# 
# String **S** = BANANA
# 
# Kevin's vowel beginning word = ANA
# 
# Here, ANA occurs twice in BANANA. Hence, Kevin will get 2 Points.
# 
# For better understanding, see the image below:
# 
# ![image.png](attachment:image.png)
# 
# Your task is to determine the winner of the game and their score.
# 
# ### Function Description
# 
# Complete the minion_game in the editor below.
# 
# minion_game has the following parameters:
# 
# * string string: the string to analyze
# 
# ### Prints
# 
# * string: the winner's name and score, separated by a space on one line, or Draw if there is no winner
# 
# ### Input Format
# 
# A single line of input containing the string **S**.
# 
# **Note**: The string  will contain only uppercase letters: **[A-Z]**.
# 
# ### Constraints
# 
# `0 < len(S) <= 10^6`
# 
# ### Sample Input
# 
# `BANANA`
# 
# ### Sample Output
# 
# `Stuart 12`
# 
# Note :
# 
# Vowels are only defined as *AEIOU*. In this problem, Y is not considered a vowel.

# In[1]:


def c_minion_game(string):
    
    sList = list(string)
    vList = ['A', 'E', 'I', 'O', 'U']
    cResult = 0
    
    print(sList,'\n')
    
    for c in range(1, len(sList)+1):
        cList = []
        for s in range(0, len(sList)):
            if sList[s].upper() in vList: # a vowel found
                if len(cList) > 0:
                    cList.append(sList[s])
                    if (len(cList) == c): # last element is a vowel
                        print('2', cList)
                        cResult += 1
                        if len(cList) > 1:
                            nString = []
                            for char in range(1, len(cList)):
                                if cList[char] not in vList:
                                    nString.append(cList[char])
                                else:
                                    if len(nString) > 0:
                                        nString.append(cList[char])
                                    else:
                                        continue
                            cList.clear()
                            if len(nString) > 0:
                                cList += nString
                        else:
                            cList.clear()
            else: # a consonant found
                cList.append(sList[s])
                if (len(cList) == c): # last element is a consonant
                    print('1', cList)
                    cResult += 1
                    if len(cList) > 1:
                        nString = []
                        for char in range(1, len(cList)):
                            if cList[char] not in vList:
                                nString.append(cList[char])
                            else:
                                if len(nString) > 0:
                                    nString.append(cList[char])
                                else:
                                    continue
                        cList.clear()
                        if len(nString) > 0:
                            cList += nString
                    else:
                        cList.clear()
    
    return cResult


# In[2]:


def v_minion_game(string):
    
    sList = list(string)
    vList = ['A', 'E', 'I', 'O', 'U']
    vResult = 0
    
    print('\n', sList,'\n')
    
    for c in range(1, len(sList)+1):
        cList = []
        for s in range(0, len(sList)):
            if sList[s].upper() not in vList: # a consonant found
                if len(cList) > 0:
                    cList.append(sList[s])
                    if (len(cList) == c): # last element is a consonant
                        print('2', cList)
                        vResult += 1
                        if len(cList) > 1:
                            nString = []
                            for char in range(1, len(cList)):
                                if cList[char] in vList:
                                    nString.append(cList[char])
                                else:
                                    if len(nString) > 0:
                                        nString.append(cList[char])
                                    else:
                                        continue
                            cList.clear()
                            if len(nString) > 0:
                                cList += nString
                        else:
                            cList.clear()
            else: # a vowel found
                cList.append(sList[s])
                if (len(cList) == c): # last element is a vowel
                    print('1', cList)
                    vResult += 1
                    if len(cList) > 1:
                        nString = []
                        for char in range(1, len(cList)):
                            if cList[char] in vList:
                                nString.append(cList[char])
                            else:
                                if len(nString) > 0:
                                    nString.append(cList[char])
                                else:
                                    continue
                        cList.clear()
                        if len(nString) > 0:
                            cList += nString
                    else:
                        cList.clear()
    
    return vResult


# In[3]:


string = 'BANANA'
cResult = c_minion_game(string)
vResult = v_minion_game(string)
print('----------great--------------')
if cResult > vResult:
    print('Stuart '+str(cResult))
elif cResult < vResult:
    print('Kevin '+str(vResult))
else:
    print('Draw')


# Stuart 12

# In[4]:


string = 'BAANANAS'
cResult = c_minion_game(string)
vResult = v_minion_game(string)
print('----------great--------------')
if cResult > vResult:
    print('Stuart '+str(cResult))
elif cResult < vResult:
    print('Kevin '+str(vResult))
else:
    print('Draw')


# Kevin 19

# In[5]:


string = 'ANANAS'
cResult = c_minion_game(string)
vResult = v_minion_game(string)
print('----------great--------------')
if cResult > vResult:
    print('Stuart '+str(cResult))
elif cResult < vResult:
    print('Kevin '+str(vResult))
else:
    print('Draw')


# Kevin 12

# In[6]:


string = 'BANANANAAAS'
cResult = c_minion_game(string)
vResult = v_minion_game(string)
print('----------great--------------')
if cResult > vResult:
    print('Stuart '+str(cResult))
elif cResult < vResult:
    print('Kevin '+str(vResult))
else:
    print('Draw')


# Draw

# In[ ]:




