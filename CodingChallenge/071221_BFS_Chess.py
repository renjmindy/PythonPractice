#!/usr/bin/env python
# coding: utf-8

# You will be given the location of a knight, and an end location. The knight can move in a "L" shape. "L" shape movement means that the knight can change it's x coordinate by 2 and it's y coordinate by 1 or it can change it's y coordinate by 2 and it's x coordinate by 1 (you can add and subtract from the x/y).
# 
# For example, if the knight is at the position (0, 0), it can move to:
# 
# (1,2), (1,-2), (2,1), (2,-1), (-1,2), (-1,-2), (-2,1), (-2, -1)
# Your job is to return the least amount of steps needed to go from the position K (knight's start position) to E (end). You will only be given the knight starter coordinates (x1, y1) and the end coordinates (x2, y2).
# 
# Constrains: 1 <= x1,y1,x2,y2 <= 8
# 
# 
# **Examples**
# 
# knightBFS(1, 1, 8, 8) ➞ 6
# 
# knightBFS(1, 1, 3, 2) ➞ 1
# 
# knightBFS(8, 8, 3, 3) ➞ 4
# 
# 
# **Notes**
# 
# This is a simplified version of this problem.
# 
# This travel will always be possible.
# 
# The chessboard is 8x8.

# In[1]:


def cal_steps(x1, y1, x2, y2):
    
    delta_x = abs(x2 - x1)
    delta_y = abs(y2 - y1)
    delta_s = delta_x + delta_y
    
    i, j = divmod(delta_s, 3)
    
    return i + j


# In[2]:


cal_steps(1, 1, 8, 8)


# In[3]:


cal_steps(1, 1, 3, 2)


# In[4]:


cal_steps(8, 8, 3, 3)


# In[ ]:




