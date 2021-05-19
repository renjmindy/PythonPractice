#!/usr/bin/env python
# coding: utf-8

# **The program:**
# 
# You must output the minimum number of bits required to code given numbers.
# 
# ``
# Input:
# ``
# 
# Line 1: An integer `N` for the number of tests.
# 
# **N Following lines:** An integer `X` which represents a number of to process.
# 
# ``
# Output:
# ``
# 
# For each number to process, the minimum number of bits required to code it.
# 
# ``
# Constraints:
# ``
# 
# 0 < `N` < 100
# 
# 0 <= `X` < 1000
# 
# ``
# Example:
# ``
# 
# **Input**
# 
# 2
# 
# 1
# 
# 6
# 
# **Output**
# 
# 1
# 
# 3

# In[1]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())

ans = 0

for i in range(n):
    x = int(input())
    if x > 1:
        ans = (x - 1) // 2
        
    ans += 1

# Write an answer using print
# To debug: print("Debug message...", file=sys.stderr, flush=True)

    print(f"result: {ans}")


# In[ ]:




