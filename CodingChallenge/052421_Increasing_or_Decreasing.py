#!/usr/bin/env python
# coding: utf-8

# Write a program that accepts three numbers from the user and prints "increasing" if the numbers are in increasing order, "decreasing" if the numbers are in decreasing order, and "Neither increasing or decreasing order" otherwise. Go to the editor
# 
# **Test Data**
# 
# Input first number: 1524
# 
# Input second number: 2345
# 
# Input third number: 3321
# 
# **Expected Output :**
# 
# Increasing order

# In[1]:


def cal_orderTrend(n):
    
    nlist = list(str(n))
    slist = []
    
    for i in range(0, len(nlist)-1, 1):
        if int(nlist[i+1]) - int(nlist[i]) > 0:
            slist.append(1)
        elif int(nlist[i+1]) - int(nlist[i]) < 0:
            slist.append(-1)
        else:
            slist.append(0)
            
    if sum(slist) == len(nlist) - 1 or (0 in slist and sum(slist) == len(nlist) - 2):
        return 'increasing'
    elif sum(slist) == (-1) * (len(nlist) - 1) or (0 in slist and sum(slist) == (-1) * (len(nlist) - 2)):
        return 'decreasing'
    else:
        return 'Neither increasing or decreasing order'


# In[2]:


cal_orderTrend(1524)


# In[3]:


cal_orderTrend(2345)


# In[4]:


cal_orderTrend(3321)


# In[ ]:




