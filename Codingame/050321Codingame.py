#!/usr/bin/env python
# coding: utf-8

# Write last digit of number raised to the specified power.
# 
# ### Input
# 
# Integer N to raise
# 
# Integer P power
# 
# 
# ### Output
# 
# Integer R
# 
# ### Constraints 
# 
# 0 < N < 10^19
# 
# 0 < P < 10^6
# 
# ### Example
# 
# `Input`
# 
# 7 
# 
# 2
# 
# `Output`
# 
# 9

# In[ ]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
p = int(input())

# Write an answer using print
# To debug: print("Debug message...", file=sys.stderr, flush=True)

number = n**p
nList = list(number)

R = nList[-1]

print("R:", R)


# In[1]:


n=7
p=2

number=n**p
nList=list(str(number))

print(nList)

R=nList[-1]
print(R)


# In[ ]:




