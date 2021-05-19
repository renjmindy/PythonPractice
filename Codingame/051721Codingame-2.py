#!/usr/bin/env python
# coding: utf-8

# **The program:**
# 
# You are given a text grid of size `N` by `N`.
# 
# Your program must choose words which are placed on the main and the secondary diagonals of the given grid.
# 
# The main diagonal is laid from the top-left to the bottom-right corner.
# The secondary diagonal is laid from the top-right to the bottom-left corner.
# 
# ``
# Input:
# ``
# 
# Line 1: An integer number `N` representing the grid size.
# 
# Next `N` lines: `N` characters.
# 
# ``
# Output:
# ``
# 
# Two words from the diagonals separated by a whitespace.
# 
# ``
# Constraints:
# ``
# 
# 0 < `N` <= 10
# 
# A grid contains only latin lowercase letters.
# 
# ``
# Example:
# ``
# 
# **Input**
# 
# 4
# 
# mooa
# 
# oano
# 
# otio
# 
# ioon
# 
# **Output**
# 
# main anti

# In[1]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())

ans1 = []
ans2 = []

for i in range(n):
    line = input()
    slist = list(line)
    ans1.append(slist[i])
    ans2.append(slist[len(slist)-i-1])

# Write an answer using print
# To debug: print("Debug message...", file=sys.stderr, flush=True)

print(f"answer {''.join(ans1)} {''.join(ans2)}")


# In[ ]:




