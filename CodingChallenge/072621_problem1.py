#!/usr/bin/env python
# coding: utf-8

# Find the Contiguous Subarray with Sum to a Given Value in an array.
# 
# Given an array of positive integer and given value X, find Contiguous sub array whose sum is equal to X.
# 
# **example**
# 
# 1
# 2
# 3
# 4
# 5
# 6
# 
# arr[]={14, 12, 70, 15, 99, 65, 21, 90};
# 
# X =97.
# 
# Sum found between index 1 to 3
# 
# Elements are 12, 17 and 15

# In[1]:


def cal_sumINsubarray(arr, n):
    
    nlist = []
    mlist = []
    
    minVal = min(arr)
    maxVal = max(arr)
    
    minIdx = arr.index(minVal)
    maxIdx = arr.index(maxVal)
    
    if n - maxVal in arr and abs(arr.index(n - maxVal) - maxIdx) == 1:
        nlist.append(maxIdx)
        nlist.append(arr.index(n - maxVal))
    elif n - minVal in arr and abs(arr.index(n - minVal) - minIdx) == 1:
        nlist.append(minIdx)
        nlist.append(arr.index(n - minVal))
    else:
        a = 0
        b = n
        c = 0
        while a < len(arr):
            if b > minVal:
                b -= arr[a]
                nlist.append(a)
                #print(a, b, arr[a])
                a += 1
            elif b == minVal:
                #print(a, b)
                nlist.append(arr.index(minVal))
                break
            else:
                b = n
                c += 1
                a = c
                nlist.clear()
        
    snlist = sorted(nlist)
    #print(snlist)
    if (snlist.index(snlist[-1]) - snlist.index(snlist[0])) == (len(snlist) - 1):
        mlist = [arr[i] for i in snlist]
        return mlist


# In[2]:


cal_sumINsubarray([14, 12, 70, 15, 99, 65, 21, 90], 97)


# In[ ]:




