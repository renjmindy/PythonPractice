#!/usr/bin/env python
# coding: utf-8

# **The program:**
# 
# You have intercepted an enemy communication, but the signal is encrypted. However, you know that the message was encrypted using the following algorithm:
# 
# For every letter in the message, write an integer `E` representing the distance of that letter from the letter `z` in the English alphabet. For spaces, write a value of `-1`
# 
# You must decrypt this communication, or risk losing the war!
# 
# ``
# Input:
# ``
# 
# **Line 1:** An integer `N` for the number of letters to decrypt. 
# 
# **Next `N` lines:** An integer `E` representing a single letter of the message.
# 
# ``
# Output:
# ``
# 
# **Line 1:** A lowercase string representing the decrypted message.
# 
# ``
# Constraints:
# ``
# 
# 1 <= `N` <= 100
# 
# ``
# Example:
# ``
# 
# Input
# 
# 5 
# 
# 18
# 
# 21
# 
# 14
# 
# 14
# 
# 11
# 
# Output
# 
# hello

# In[1]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

alphabet = {25:'a', 24:'b', 23:'c', 22:'d', 21:'e', 20:'f', 19:'g', 18:'h', 17:'i', 16:'j', 15:'k', 14:'l', 13:'m', 12:'n', 
            11:'o', 10:'p', 9:'q', 8:'r', 7:'s', 6:'t', 5:'u', 4:'v', 3:'w', 2:'x', 1:'y', 0:'z'}

n = int(input())

sList = []

for i in range(n):
    e = int(input())
    sList.append(alphabet[e])

# Write an answer using print
# To debug: print("Debug message...", file=sys.stderr, flush=True)

print(f"answer: {''.join(sList)}")


# In[ ]:




