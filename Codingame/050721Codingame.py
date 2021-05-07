#!/usr/bin/env python
# coding: utf-8

# The game mode is **REVERSE**: You do not have access to the statement. You have to guess what to do by observing the following set of tests:
# 
# ## Test 1
# 
# ``
# Input
# ``
# 
# 3
# 
# Tokyo 37
# 
# Paris 10
# 
# London 9
# 
# Lon
# 
# ``
# Expected Output
# ``
# 
# 9
# 
# ## Test 2
# 
# ``
# Input
# ``
# 
# 4
# 
# Shanghai 25
# 
# Madrid 6
# 
# Bangkok 10
# 
# Manila 13
# 
# Ma
# 
# ``
# Expected Output
# ``
# 
# 19
# 
# ### Test 3
# 
# ``
# Input
# ``
# 
# 2
# 
# Toronto 6
# 
# Rome 4
# 
# Mex
# 
# ``
# Expected Output
# ``
# 
# 0
# 
# ## Test 4
# 
# ``
# Input
# ``
# 
# 3
# 
# Osaka 19
# 
# Wuhan 8
# 
# Sydney 4
# 
# sak
# 
# ``
# Expected Output
# ``
# 
# 19

# In[ ]:


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())

for i in range(0, n, 1):
    inputs = input().split()
    city = inputs[0]
    population = int(inputs[1])
search = input()

# Write an answer using print
# To debug: print("Debug message...", file=sys.stderr, flush=True)

print("total")


# In[1]:


def search(n, city, population, stra=''):
    
    total = 0
    
    for i in range(0, n, 1):
        cList = list(city[i])
        if stra[0].isupper():
            if stra == ''.join(cList[0:len(stra)]):
                total += population[i]
            else:
                total += 0   
        else:
            if stra[0] in cList:
                for j in range(0, len(cList), 1):
                    if stra[0] == cList[j]:
                        if stra == ''.join(cList[j:len(stra)+1]):
                            total += population[i]
                        else:
                            total += 0
            else:
                total += 0
            
    return total


# In[2]:


n = 3
city = ['Tokyo', 'Paris', 'London']
population = [37, 10, 9]
stra = 'Lon'
print(f"total: {search(n, city, population, stra)}")


# In[3]:


n = 4
city = ['Shanghai', 'Madrid', 'Bangkok', 'Manila']
population = [25, 6, 10, 13]
stra = 'Ma'
print(f"total: {search(n, city, population, stra)}")


# In[4]:


n = 2
city = ['Toronto', 'Rome']
population = [6, 4]
stra = 'Mex'
print(f"total: {search(n, city, population, stra)}")


# In[5]:


n = 3
city = ['Osaka', 'Wuhan', 'Sydney'] 
population = [19, 8, 4]
stra = 'sak'
print(f"total: {search(n, city, population, stra)}")


# In[ ]:




