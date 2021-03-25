#!/usr/bin/env python
# coding: utf-8

# ## Abbreviation

# You can perform the following operations on the string, a:
# 
# 1. Capitalize zero or more of a's lowercase letters.
# 
# 2. Delete all of the remaining lowercase letters in a.
# 
# Given two strings, a and b, determine if it's possible to make a equal to b as described. If so, print `YES` on a new line. Otherwise, print `NO`.
# 
# For example, given a = AbcDE and b = ABDE, in a we can convert b and delete c to match b. If a = AbcDE and b = AFDE, matching is not possible because letters may only be capitalized or discarded, not changed.
# 
# ### Function Description
# 
# Complete the function *abbreviation* in the editor below. It must return either *YES* or *NO*.
# 
# abbreviation has the following parameter(s):
# 
# * a: the string to modify
# 
# * b: the string to match
# 
# ### Input Format
# 
# The first line contains a single integer q, the number of queries.
# 
# Each of the next q pairs of lines is as follows:
# 
# - The first line of each query contains a single string, a.
# 
# - The second line of each query contains a single string, b.
# 
# ### Constraints
# 
# * 1 <= q <= 10
# 
# * 1 <= |a|, |b| <= 1000
# 
# * String a consists only of uppercase and lowercase English letters, ascii[A-Za-z].
# 
# * String b consists only of uppercase English letters, ascii[A-Z].
# 
# ### Output Format
# 
# For each query, print `YES` on a new line if it's possible to make string a equal to string b. Otherwise, print `NO`.
# 
# ### Sample Input
# 
# 1
# 
# daBcd
# 
# ABC
# 
# ### Sample Output
# 
# YES
# 
# ### Explanation
# 
# ![image.png](attachment:image.png)
# 
# We have a = `daBcd` and b = `ABC`. We perform the following operation:
# 
# 1. Capitalize the letters `a` and `c` in a so that a = `dABCd`.
# 
# 2. Delete all the remaining lowercase letters in a so that a = `ABC`.
# 
# Because we were able to successfully convert a to b, we print `YES` on a new line.

# In[1]:


#!/bin/python3

import math
import os
import random
import re
import sys


# In[2]:


# Complete the abbreviation function below.
def abbreviation(Q, a, b):
    
    match = ""
    result = []

    for q in range(0, Q):
        
        aList = list(a[q])
        bList = list(b[q])
        cList = []
        dList = []
        
        for ai in aList:
            if ai.upper() in bList:
                cList.append(ai.upper())
            else:
                cList.append(ai)
        
        for c in cList:
            if c == c.upper():
                dList.append(c)
            
        if dList == bList:
            match = 'YES'
        else:
            match = 'NO'
            
        print(bList, ' ', dList, ' ', match)
        
        result.append(match)
    
    return result


# In[3]:


Q = 1
a = ['daBcd']
b = ['ABC']
abbreviation(Q, a, b)


# In[4]:


Q = 10
a = ['Pi', 'AfPZN', 'LDJAN', 'UMKFW', 'KXzQ', 'LIT', 'QYCH', 'DFIQG', 'sYOCa', 'JHMWY'] 
b = ['P', 'APZNC', 'LJJM', 'UMKFW', 'K', 'LIT', 'QYCH', 'DFIQG', 'YOCN', 'HUVPW']
abbreviation(Q, a, b)


# In[5]:


Q = 3
a = ['AbCdE', 'beFgH', 'beFgH']
b = ['AFE', 'EFG', 'EFH']
abbreviation(Q, a, b)


# In[ ]:


#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the abbreviation function below.
def abbreviation(a, b):
    
    match = ""
    
    aList = list(a)
    bList = list(b)
    cList = []
    dList = []
    
    for ai in aList:
        if ai.upper() in bList:
            cList.append(ai.upper())
        else:
            cList.append(ai)
            
    for c in cList:
        if c == c.upper():
            dList.append(c)
            
    if dList == bList:
        match = 'YES'
    else:
        match = 'NO'
        
    #print(bList, ' ', dList, ' ', match)
        
    return match

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        
        a = input()
        #print(a)

        b = input()
        #print(b)

        result = abbreviation(a, b)

        fptr.write(result + '\n')

    fptr.close()

