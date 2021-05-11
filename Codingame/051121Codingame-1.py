#!/usr/bin/env python
# coding: utf-8

# Find the point closest to (0,0).
# 
# You are given a list of points, and you must find the point closest to the origin.
# 
# If two points have the same distance, return the one that was given first in th list.
# 
# The distance to use between two points is the Euclidean distance.
# 
# For two points `A` and `B`, the distance is sqrt((A.x - B.x)^2 + (A.y - B.y)^2)
# 
# The result may differ between languages due to floating point errors if you use sqrt.
# 
# Then, calculate the shortest distance without using sqrt.
# 
# ``
# Input
# ``
# 
# Line 1: `N` the number of input points
# 
# Next `N` lines: `x` and `y`, separated by a space, for each point
# 
# ``
# Output
# ``
# 
# `x` `y` of the point closest to (0,0)
# 
# ``
# Constraints
# ``
# 
# 1 <= N <= 100
# 
# -1000000 <= `x`, `y` <= 1000000
# 
# ``
# Example
# ``
# 
# ``
# Input
# ``
# 
# 3
# 
# 2 2
# 
# -1 1
# 
# -3 -3
# 
# ``
# Output
# ``
# 
# -1 1

# In[ ]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())

for i in range(n):
    x, y = [int(j) for j in input().split()]

# Write an answer using print
# To debug: print("Debug message...", file=sys.stderr, flush=True)

print("1 1")


# In[1]:


def shorest_dist(N, P):
    
    iMin = -1
    dMin = 1000000
    
    for i in range(0, N, 1):
        d = P[i][0]**2 + P[i][1]**2
        if d < dMin:
            iMin = i
            dMin = d
            
    return P[iMin]


# In[2]:


N = 3
P = [(2, 2), (-1, 1), (-3, -3)]
shorest_dist(N, P)


# In[ ]:




