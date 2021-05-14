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
# 3
# 
# 4
# 
# ``
# Expected Output
# ``
# 
# >> 21
# 
# ``
# 02 Test 2
# ``
# 
# ``
# Input
# ``
# 
# 2 
# 
# 8
# 
# ``
# Expected Output
# ``
# 
# >> 20
# 
# ``
# 03 Test 3
# ``
# 
# ``
# Input
# ``
# 
# 0
# 
# 8
# 
# ``
# Expected Output
# ``
# 
# >> 0
# 
# ``
# 04 Test 4
# ``
# 
# ``
# Input
# ``
# 
# 27 
# 
# 6
# 
# ``
# Expected Output
# ``
# 
# >> 891

# In[1]:


def guess_number():

    import sys
    import math

    # Auto-generated code below aims at helping you parse
    # the standard input according to the problem statement.

    x = input()
    y = input()

    # Write an answer using print
    # To debug: print("Debug message...", file=sys.stderr, flush=True)
    
    ans = 0
    
    ans = (int(x) + int(y)) * int(x)
    
    print(f"answer: {ans}")
    
    pass


# In[2]:


guess_number()


# In[3]:


guess_number()


# In[4]:


guess_number()


# In[5]:


guess_number()


# In[ ]:




