#!/usr/bin/env python
# coding: utf-8

# Create a function that returns a number which can block the player from reaching 3 in a row in a game of Tic Tac Toe. The number given as an argument will correspond to a grid of Tic Tac Toe: topleft is 0, topright is 2, bottomleft is 6, and bottomright is 8.
# 
# Create a function that takes two numbers a, b and returns another number.
# This number should be the final one in a line to block the player from winning.
# 
# **Examples**
# 
# blockPlayer(0, 3) ➞ 6
# 
# blockPlayer(0, 4) ➞ 8
# 
# blockPlayer(3, 5) ➞ 4
# 
# **Notes**
# 
# The values given will always have two filled squares in a line.

# In[1]:


def cal_blockSquare(a, b):
    
    tlist = [0, 1, 2]
    mlist = [3, 4, 5]
    blist = [6, 7, 8]
    llist = [0, 3, 6]
    nlist = [1, 4, 7]
    rlist = [2, 5, 8]
    dlist = [0, 4, 8]
    clist = [2, 4, 6]
    
    if a in tlist and b in tlist:
        tlist.remove(a)
        tlist.remove(b)
        return tlist[0]
    elif a in mlist and b in mlist:
        mlist.remove(a)
        mlist.remove(b)
        return mlist[0]
    elif a in blist and b in blist:
        blist.remove(a)
        blist.remove(b)
        return blist[0]
    elif a in llist and b in llist:
        llist.remove(a)
        llist.remove(b)
        return llist[0]
    elif a in nlist and b in nlist:
        nlist.remove(a)
        nlist.remove(b)
        return nlist[0]
    elif a in rlist and b in rlist:
        rlist.remove(a)
        rlist.remove(b)
        return rlist[0]
    elif a in dlist and b in dlist:
        dlist.remove(a)
        dlist.remove(b)
        return dlist[0]
    elif a in clist and b in clist:
        clist.remove(a)
        clist.remove(b)
        return clist[0]
    else:
        return 'n/a'


# In[2]:


cal_blockSquare(0, 3)


# In[3]:


cal_blockSquare(0, 4)


# In[4]:


cal_blockSquare(3, 5)


# In[ ]:




