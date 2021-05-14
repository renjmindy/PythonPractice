#!/usr/bin/env python
# coding: utf-8

# The game model is **REVERSE**: You don't have access to the statement. You have to guess what to do by observing the following set of tests:
# 
# ``
# 01 Test 1
# ``
# 
# ``
# Input
# ``
# 
# B
# 
# ``
# Expected Output
# ``
# 
# >> AB
# 
# ``
# 02 Test 2
# ``
# 
# ``
# Input
# ``
# 
# d
# 
# ``
# Expected Output
# ``
# 
# >> abcd
# 
# ``
# 03 Test 3
# ``
# 
# ``
# Input
# ``
# 
# 5
# 
# ``
# Expected Output
# ``
# 
# >> 012345
# 
# ``
# 04 Test 4
# ``
# 
# ``
# Input
# ``
# 
# Bd5
# 
# ``
# Expected Output
# ``
# 
# >> ABabcd012345
# 
# ``
# 05 Test 5
# ``
# 
# ``
# Input
# ``
# 
# Zz9
# 
# ``
# Expected Output
# ``
# 
# >> ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789

# In[1]:


def print_everything():

    import sys
    import math

    # Auto-generated code below aims at helping you parse
    # the standard input according to the problem statement.

    s = input()

    # Write an answer using print
    # To debug: print("Debug message...", file=sys.stderr, flush=True)
    
    ucase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    lcase = "abcdefghijklmnopqrstuvwxyz"
    
    uList = list(ucase)
    lList = list(lcase)
    sList = list(s)
    ansList = []
    
    for i in sList:
        if i.islower() == True:
            for j in range(0, len(lList), 1):
                if i == lList[j]:
                    ansList.append(''.join(lList[0:j+1]))
        elif i.isupper() == True:
            for j in range(0, len(uList), 1):
                if i == uList[j]:
                    ansList.append(''.join(uList[0:j+1]))
        else:
            if i.isdigit() == True:
                for j in range(0, int(i)+1, 1):
                    ansList.append(str(j))

    #print(ansList)
    print(f"answer: {''.join(ansList)}")
    
    pass


# In[2]:


print_everything()


# In[3]:


print_everything()


# In[4]:


print_everything()


# In[5]:


print_everything()


# In[6]:


print_everything()


# In[ ]:




