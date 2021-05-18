#!/usr/bin/env python
# coding: utf-8

# We are given two integers `a` and `b`. For those two integers we look for positive integers which divide both `a` and `b` (without leaving a remainder). If there does not exist such an integer besides 1, we call `a` and `b` **coprime**.
# 
# ``
# Input
# ``
# 
# Line 1: A positive integer `a`.
# 
# Line 2: A positive integer `b`.
# 
# ``
# Output
# ``
# 
# The string "**true**" when the given integers are coprime or "**false**" when they are not.
# 
# ``
# Constraints
# ``
# 
# 1 <= `a`, `b` <= 2 * 10^7
# 
# ``
# Example
# ``
# 
# ``
# Input
# ``
# 
# 5 
# 
# 6
# 
# ``
# Output
# ``
# 
# true

# In[1]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

a = int(input())
b = int(input())

# Write an answer using print
# To debug: print("Debug message...", file=sys.stderr, flush=True)

ans = False

for i in range(2, a*b):
    if a*b % i == 0:
        ans = True
        break
    

print(f"answer: {ans}")


# In[ ]:




