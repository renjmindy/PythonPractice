#!/usr/bin/env python
# coding: utf-8

# Let's say that there exists a machine that gives out free coins, but with a twist!
# 
# Separating two people is a wall, and this machine is placed in such a way that both people are able to access it. Spending a coin in this machine will give the person on the other side 3 coins and vice versa.
# 
# If both people continually spend coins for each other (SHARING), then they'll both gain a net profit of 2 coins per turn. However, there is always the possibility for someone to act selfishly (STEALING): they spend no coins, yet they still receive the generous 3 coin gift from the other person!
# 
# Here's an example of Red taking advantage of Green! Red chose to betray
# 
# **The Challenge**
# 
# Assuming that both people start with 3 coins each, create a function that calculates both people's final number of coins. You will be given two arrays of strings, with each string being the words "share" or "steal".
# 
# **Examples**
# 
# getCoinBalances(["share"], ["share"]) ➞ [5, 5]
# 
# // Both people spend one coin, and receive 3 coins each.
# 
# getCoinBalances(["steal"], ["share"]) ➞ [6, 2]
# 
# // Person 1 gains 3 coins, while person 2 loses a coin.
# 
# getCoinBalances(["steal"], ["steal"]) ➞ [3, 3]
# 
# // Neither person spends any coins and so no one gets rewarded.
# 
# getCoinBalances(["share", "share", "share"], ["steal", "share", "steal"]) ➞ [3, 11]
# 
# **Notes**
# 
# No tests will include a negative number of coins.
# 
# All words will be given in lowercase.
# 
# This challenge is adapted from a famous game theory example called the Prisoner's Dilemma.

# In[1]:


def cal_coinexchange(arr1, arr2):
    
    coin1 = []
    coin2 = []
    
    for i, j in enumerate(arr1):
        if j == 'share' and arr2[i] == j:
            coin1.append(2)
            coin2.append(2)
        elif j == 'share' and arr2[i] != j:
                coin1.append(-1)
                coin2.append(3)
        else:
            if j == arr2[i]:
                coin1.append(0)
                coin2.append(0)
            else:
                coin1.append(3)
                coin2.append(-1)
                
    return [sum(coin1)+3, sum(coin2)+3]             


# In[2]:


cal_coinexchange(["share"], ["share"])


# In[3]:


cal_coinexchange(["steal"], ["share"])


# In[4]:


cal_coinexchange(["steal"], ["steal"])


# In[5]:


cal_coinexchange(["share", "share", "share"], ["steal", "share", "steal"])


# In[ ]:




