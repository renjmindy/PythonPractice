#!/usr/bin/env python
# coding: utf-8

# You must output for each participant in a race the traveled **distance** (in **meters**) at a given speed `S` (centimeters/second) in given amount of time `T` (minutes).
# 
# ``
# Input
# ``
# 
# Line 1: An integer `N` for the number of participants
# 
# Next `N` lines: Two space separated integers `S` and `T` representing respectively the speed `S` and the time `T`
# 
# ``
# Output
# ``
# 
# `N` Lines: An integer representing the **distance** traveled
# 
# ``
# Constraints
# ``
# 
# 0 <= `S` <= 150
# 
# 0 <= `T` <= 100000
# 
# ``
# Example
# ``
# 
# ``
# Input
# ``
# 
# 1
# 
# 20 10
# 
# ``
# Output
# ``
# 
# 120

# In[ ]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())

for i in range(n):
    s, t = [int(j) for j in input().split()]

# Write an answer using print
# To debug: print("Debug message...", file=sys.stderr, flush=True)

print("answer")


# In[1]:


def calculate_dist(n, s, t):
    
    d = []
    
    for i in range(0, n, 1):
        s[i] /= 100
        t[i] *= 60
        d.append(int(s[i]*t[i]))
        
    return d


# In[2]:


n = 1
s = [20]
t = [10]
calculate_dist(n, s, t)


# In[ ]:




