#!/usr/bin/env python
# coding: utf-8

# Your program must determine if a given string would be a safe password. Here, a password is considered safe if:
# 
# * It contains at least 8 characters
# 
# * It contains at least 1 digit (0-9)
# 
# * It contains at least 1 lowercase letter (a-z)
# 
# * It contains at least 1 uppercase letter (A-Z)
# 
# ``
# Input
# ``
# 
# Line 1: `P` a string containing a password
# 
# ``
# Output
# ``
# 
# Line 1: `true` if `P` is a safe password, `false` otherwise
# 
# ``
# Constraints
# ``
# 
# 0 < `P`.length < 100
# 
# ``
# Example
# ``
# 
# ``
# Input
# ``
# 
# 11/12/1978
# 
# ``
# Output
# ``
# 
# false

# In[1]:


def passwordCheck():

    import sys
    import math

    # Auto-generated code below aims at helping you parse
    # the standard input according to the problem statement.

    s = input()

    # Write an answer using print
    # To debug: print("Debug message...", file=sys.stderr, flush=True)
    
    found = False
    foundDigit = False
    foundLower = False
    foundUpper = False
    
    sList = list(s)
    
    if len(sList) >= 8:
        for i in sList:
            if i.isdigit():
                foundDigit = True
            elif i.islower():
                foundLower = True
            elif i.isupper():
                foundUpper = True
            else:
                continue
                
        if foundDigit and foundLower and foundUpper:
            found = True

    if found:
        checkPassword = 'true'
    else:
        checkPassword = 'false'
    
    
    print(f"true/false: {checkPassword}!!!")
    
    pass


# In[2]:


passwordCheck()


# In[3]:


passwordCheck()


# In[ ]:




