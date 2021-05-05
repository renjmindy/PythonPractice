#!/usr/bin/env python
# coding: utf-8

# The Collatz conjecture is a opened mathematics problem: given a number `N`, the repetition of the following operation will always eventually reach the loop 
# `1 => 4 => 2 => 1 ...`
# 
# * If `N` is even, `N` becomes `N`/2
# 
# * If `N` is odd, `N` becomes 3*`N`+1
# 
# Can you try it with the given number and print the number of steps it took to reach 1?
# 
# `Input`
# 
# A starting number `N`
# 
# `Output`
# 
# The number of steps to reach 1
# 
# `Constraints`
# 
# 0 < `N` <= 10^12
# 
# `Example`
# 
# `Input`
# 
# 16
# 
# `Output`
# 
# 4

# In[1]:


import sys
import math

def collatz_conjecture_math():

    # Auto-generated code below aims at helping you parse
    # the standard input according to the problem statement.

    n = int(input())

    while n == 0 or n == 1:
        print('please re-select a positive number greater than one!')
        n = int(input())
    
    # Write an answer using print
    # To debug: print("Debug message...", file=sys.stderr, flush=True)

    def Log2(x):
        return (math.log10(x) / math.log10(2));

    def isPowerOfTwo(x):
        return (math.ceil(Log2(x)) == math.floor(Log2(x)));

    if isPowerOfTwo(n):
        print(f"answer: {int(Log2(n))}")
    else:
        counter = 0
        while n != 1:
            if n % 2 != 0:
                n *= 3
                n += 1
                counter += 1
            else:
                n /= 2
                counter += 1
         
        print(f"ends up to {int(n)}")
        print(f"answer: {counter}")
        
    pass


# In[2]:


collatz_conjecture_math()


# In[3]:


collatz_conjecture_math()


# In[4]:


collatz_conjecture_math()


# In[5]:


collatz_conjecture_math()


# In[ ]:




