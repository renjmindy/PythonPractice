#!/usr/bin/env python
# coding: utf-8

# Write a function that mimics the following described arithmetic operations.
# 
# Starting with either 3 or 5 and given these operations:
# 
# add 5
# 
# multiply by 3
# 
# You should say if it is possible to reach the target number n.
# 
# **Examples**
# 
# only5and3(14) ➞ true
# 
# // 14 = 3*3 + 5
# 
# only5and3(25) ➞ true
# 
# // 25 = 5+5+5+5+5
# 
# only5and3(7) ➞ false
# 
# // There exists no path to the target number 7
# 
# **Notes**
# 
# Only addition and multiplication arithmetic operations are allowed.
# 
# You can solve this problem recursively or algebraically.

# In[1]:


def cal_fiveANDthree(n):
    
    while n > 1:
        
        if n % 3 > 0:
            n -= 5
            #print(n)
        else:
            n /= 3
            #print(n)
            
    if n == 1 or n == 0:
        return True
    else:
        return False


# In[2]:


cal_fiveANDthree(14)


# In[3]:


cal_fiveANDthree(25)


# In[4]:


cal_fiveANDthree(7)


# In[ ]:




