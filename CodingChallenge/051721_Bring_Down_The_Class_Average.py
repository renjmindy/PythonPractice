#!/usr/bin/env python
# coding: utf-8

# What is the percentage you can score on a test, which single-handedly brings down the class average by 5%? Given an array of your classmates scores, create a function that returns the answer. Round to the nearest percent.
# 
# **Examples**
# 
# takeDownAverage(["95%", "83%", "90%", "87%", "88%", "93%"]) ➞ "54%"
# 
# takeDownAverage(["10%"]) ➞ "0%"
# 
# takeDownAverage(["53%", "79%"]) ➞ "51%"
# 
# **Notes**
# 
# No tests will include empty arrays or require negative percentages.
# 
# Note that you need to return a string.

# In[1]:


def cal_classAverage(arr):
    
    nlist = []
    
    for a in arr:
        nlist.append(int(a.replace('%', '')))
        
    return str(round(((sum(nlist)/len(nlist)) - 5) * (len(nlist) + 1)) - sum(nlist)) + '%'


# In[2]:


cal_classAverage(["95%", "83%", "90%", "87%", "88%", "93%"])


# In[3]:


cal_classAverage(["10%"])


# In[4]:


cal_classAverage(["53%", "79%"])


# In[ ]:




