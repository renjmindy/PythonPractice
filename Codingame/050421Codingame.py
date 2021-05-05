#!/usr/bin/env python
# coding: utf-8

# Write a simaple calculator that operates in **unary** to sum a sequence of positive integers.
# 
# Unary is the **bijective numeration** base **1**, using the digit 1 to represent 1 but lacking a zero digit. It is a positional numbering system, but trivially so, since every position, as a power of 1, is a ones place, regardless of left or right direction.
# 
# Starting from 1, the first five numbers in unary are 1, 11, 111, 1111 and 11111.
# 
# `Input`
# 
# Line 1: An integer **count** representing the number of input values
# 
# Line 2: A string of **unary** values, separated by spaces
# 
# `Output`
# 
# Line 1: A string in unary notation representing the **summation**
# 
# `Constraints`
# 
# 2 <= count < 20
# 
# 1 <= length of each `unary` representation < 25
# 
# `Example`
# 
# `Input`
# 
# 5
# 
# 1 11 111 1111 11111
# 
# `Output`
# 
# 111111111111111

# In[ ]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

count = int(input())

uList = []

for unary in input().split():
    uList.append(unary)

# Write an answer using print
# To debug: print("Debug message...", file=sys.stderr, flush=True)

summation = ''.join(uList)

print(f"summation: {summation}")


# In[1]:


count = 5
uList = ['1', '11', '111', '1111', '11111']
summation = ''.join(uList)
print(f"summation: {summation}")


# In[ ]:




