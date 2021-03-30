#!/usr/bin/env python
# coding: utf-8

# ## Validating Email Addresses With a Filter
# 
# You are given an integer **N** followed by **N** email addresses. Your task is to print a list containing only valid email addresses in lexicographical order.
# 
# Valid email addresses must follow these rules:
# 
# * It must have the username@websitename.extension format type.
# 
# * The username can only contain letters, digits, dashes and underscores.
# 
# * The website name can only have letters and digits.
# 
# * The maximum length of the extension is **3**.
# 
# ### Concept
# 
# A filter takes a function returning True or False and applies it to a sequence, returning a list of only those members of the sequence where the function returned True. A Lambda function can be used with filters.
# 
# Let's say you have to make a list of the squares of integers from **0** to **9** (both included).
# 
# `>> l = list(range(10))`
# 
# `>> l = list(map(lambda x:x*x, l))`
# 
# Now, you only require those elements that are greater than **10** but less than **80**.
# 
# `>> l = list(filter(lambda x: x > 10 and x < 80, l))`
# 
# Easy, isn't it?
# 
# ### Input Format
# 
# The first line of input is the integer **N**, the number of email addresses.
# 
# **N** lines follow, each containing a string.
# 
# ### Constraints
# 
# Each line is a non-empty string.
# 
# ### Output Format
# 
# Output a list containing the valid email addresses in lexicographical order. If the list is empty, just output an empty list, [].
# 
# ### Sample Input
# 
# 3
# 
# lara@hackerrank.com
# 
# brian-23@hackerrank.com
# 
# britts_54@hackerrank.com
# 
# ### Sample Output
# 
# ['brian-23@hackerrank.com', 'britts_54@hackerrank.com', 'lara@hackerrank.com']
# 

# In[1]:


import re


# In[2]:


def fun(s):
    
    # return True if s is a valid email, else return False
    result = []
    
    for es in s:
        
        si = list(es)
        
        #print(si)
        
        uList = []
        wList = []
        eList = []
        cList = []
        
        countAt = 0
        countDt = 0
        
        for i in si:
            
            if countAt == 0 and countDt == 0:
                if i != '@':
                    uList.append(''.join(i))
                else:
                    countAt += 1
            
            elif countAt == 1 and countDt == 0:
                if i != '.':
                    wList.append(''.join(i))
                else:
                    countDt += 1
                
            elif countAt == 1 and countDt == 1:
                eList.append(''.join(i))
            
            else:
                print('something beyond!')
            
        #print('username:', uList)
        #print('websitename:', wList)
        #print('extension:', eList)
        
        if re.match("^[a-zA-Z0-9_-]*$", ''.join(uList)) and len(uList) > 0:
        #if re.match("^[\w\d_-]*$", ''.join(uList)):
            cList.append(1)
        else:
            cList.append(-1)
        
        if re.match("^[a-zA-Z0-9]*$", ''.join(wList)) and len(wList) > 0:
        #if re.match("^[\w\d]*$", ''.join(wList)):
            cList.append(1)
        else:
            cList.append(-1)
            
        if len(eList) <= 3 and len(eList) > 0:
            cList.append(1)
        else:
            cList.append(-1)
            
        if sum(cList) == 3:
            result.append(es)
    
    return sorted(result)
    


# def filter_mail(emails):
#     
#     return list(filter(fun, emails))
#     
# #### function that filters vowels
# def fun(variable):
# 
#     letters = ['a', 'e', 'i', 'o', 'u']
# 
#     if (variable in letters):
#     
#         return True
#         
#     else:
#     
#         return False
#   
# #### sequence
# sequence = ['g', 'e', 'e', 'j', 'k', 's', 'p', 'r']
#   
# #### using filter function
# filtered = filter(fun, sequence)
#   
# print('The filtered letters are:')
# 
# for s in filtered:
# 
#     print(s)

# In[3]:


N = 3
emails = ['lara@hackerrank.com', 'brian-23@hackerrank.com', 'britts_54@hackerrank.com']
fun(emails)
#filtered_emails = filter_mail(emails)
#filtered_emails.sort()
#print(filtered_emails)


# ['brian-23@hackerrank.com', 'britts_54@hackerrank.com', 'lara@hackerrank.com']

# In[4]:


N = 2
emails = ['harsh@gmail', 'iota_98@hackerrank.com']
fun(emails)
#filtered_emails = filter_mail(emails)
#filtered_emails.sort()
#print(filtered_emails)


# ['iota_98@hackerrank.com']

# In[5]:


N = 5
emails = ['dheeraj-234@gmail.com', 'itsallcrap', 'harsh_1234@rediff.in', 'kunal_shin@iop.az', 'matt23@@india.in']
fun(emails)
#filtered_emails = filter_mail(emails)
#filtered_emails.sort()
#print(filtered_emails)


# ['dheeraj-234@gmail.com', 'harsh_1234@rediff.in', 'kunal_shin@iop.az']

# In[6]:


N = 3
emails = ['fjladfk_iasdfad234@sdlkjf23335.in', 'ha@git@int.cz', 'prashant24_@gmail.com']
fun(emails)
#filtered_emails = filter_mail(emails)
#filtered_emails.sort()
#print(filtered_emails)


# ['fjladfk_iasdfad234@sdlkjf23335.in', 'prashant24_@gmail.com']

# In[7]:


N = 5
emails = ['its@gmail.com1', 'mike13445@yahoomail9.server', 'rase23@ha_ch.com', 'daniyal@gmail.coma', 'thatisit@thatisit']
fun(emails)
#filtered_emails = filter_mail(emails)
#filtered_emails.sort()
#print(filtered_emails)


# []

# In[8]:


N = 5
emails = ['itsme@gmail', '@something', '@something.com', '@something.co1', 'sone.com']
fun(emails)
#filtered_emails = filter_mail(emails)
#filtered_emails.sort()
#print(filtered_emails)


# []

# In[9]:


N = 3
emails = ['iu89_in.plus@google.com', 'ill@google.com', 'fill@google1.com']
fun(emails)
#filtered_emails = filter_mail(emails)
#filtered_emails.sort()
#print(filtered_emails)


# ['fill@google1.com', 'ill@google.com']

# In[10]:


N = 3
emails = ['learn.point@learningpoint.net', 'learnpoint@learningpoint.net', 'learnpoint@learningpoint.net1']
fun(emails)
#filtered_emails = filter_mail(emails)
#filtered_emails.sort()
#print(filtered_emails)


# ['learnpoint@learningpoint.net']

# In[11]:


N = 3
emails = ['it!%^#$@w3.com', '674&*($@djfj.in', 'itsnothing']
fun(emails)
#filtered_emails = filter_mail(emails)
#filtered_emails.sort()
#print(filtered_emails)


# []

# In[ ]:




