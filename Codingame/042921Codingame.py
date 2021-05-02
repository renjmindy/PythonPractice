#!/usr/bin/env python
# coding: utf-8

# Given a Tetris board, just after a piece is landed, determine the `score` the player gets after the full lines clearing. A single row clear is worth 100 points, clearing four consecutive rows at once (known as a Tetris) gives 400 bonus points, so a Tetris is worth 800 points total. 
# 
# Example:
# 0    ..........
# 
# 1    ..........
# 
# 2    ..........
# 
# 3    ..........
# 
# 4    ..........
# 
# 5    ..........
# 
# 6    #.........
# 
# 7    #.........
# 
# 8    #.........
# 
# 9    ##........
# 
# 10   ##....#...
# 
# 11   ##....##..
# 
# 12   #....#####
# 
# 13   ##########
# 
# 14   #######..#
# 
# 15   ##########
# 
# In the above example lines 13 and 15 are full and each is worth 100 points, so the score a Player would get from this game is 200.
# 
# `Input`
# 
# 16 lines: Each line contains 10 characters, which are representing a row on the Tetris board.
# 
# Characters can be:
# 
# .  - Empty square
# \# - Occupied square
# 
# `Output`
# 
# The score for the player.
# 
# `Constraints`
# 
# The given Tetris board is always with 16 rows and 10 columns
# 
# `Example`
# 
# `Input`
# 
# 0    ..........
# 
# 1    ..........
# 
# 2    ..........
# 
# 3    ..........
# 
# 4    ..........
# 
# 5    ..........
# 
# 6    ..........
# 
# 7    ..........
# 
# 8    ..........
# 
# 9    ..........
# 
# 10   ..........
# 
# 11   ..........
# 
# 12   ..........
# 
# 13   ..........
# 
# 14   ..........
# 
# 15   ##########
# 
# `Output`
# 
# 100

# In[ ]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement

counter1 = 0
counter2 = 0
counter3 = 0

for i in range(0, 16, 1):
    board_row = input()
    if i > 0: 
        if counter1 == 16:
            counter2 += 1
            counter1 = 0
            score += 100
        else:
            counter1 = 0
        if i % 4 == 0:
            if counter2 == 4:
                counter3 += 1
                counter2 = 0
            else:
                counter2 = 0
    for j in list(board_row):
        if j == '#':
            counter1 += 1
    
    
score += (counter3 * 400)
    
# Write an answer using print
# To debug: print("Debug message...", file-sys.stderr, flush-True)

print("score")

