#!/usr/bin/env python
# coding: utf-8

# In golf course, each hole has a "pair" value which is the maximum number of swings that players should ideally need to clear the hole.
# 
# Once a player has cleared the hole, the pair is subtracted from the player's effective swing count, resulting in the player's score for that hole (i.e. 2 swings for a pair 3 scores -1)
# 
# The final score for a player on a course is the total of his scores for each hole in the course.
# 
# Given a score card for a 18-hole course, your program must output the player's score.
# 
# `Input`
# 
# Line 1: 18 numbers separated by spaces, representing the pairs for each hole.
# 
# Line 2: 18 numbers separated by spaces, representing the player's swing count for each hole.
# 
# `Output`
# 
# Line 1: the player's final score for the course.
# 
# `Example`
# 
# `Input`
# 
# 4 4 3 4 4 5 4 3 5 4 3 4 5 4 4 3 4 5
# 
# 4 3 2 4 3 4 3 3 4 4 3 4 6 4 5 3 3 4
# 
# `Output`
# 
# -6

# In[ ]:


import sys
import math

# Auto generated code below aims at helping you parse
# the standard input according to the problem statement.

for i in input().split():
    pList.append(int(i))
    
for i in input().split():
    sList.append(int(i))

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

score = 0

for i in range(0, len(sList), 1):
    score += (sList[i] - pList[i])
    
print(f"answer: {score}")

