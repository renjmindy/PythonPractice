#!/usr/bin/env python
# coding: utf-8

# Create a function that takes a number as an argument and returns "Fizz", "Buzz" or "FizzBuzz".
# 
# * If the number is a multiple of 3 the output should be "Fizz".
# 
# * If the number given is a multiple of 5, the output should be "Buzz".
# 
# * If the number given is a multiple of both 3 and 5, the output should be "FizzBuzz".
# 
# * If the number is not a multiple of either 3 or 5, the number should be output on its own as shown in the examples below.
# 
# The output should always be a string even if it is not a multiple of 3 or 5.
# 
# **Examples**
# 
# <code>
#     
#     fizz_buzz(3) ➞ "Fizz"
# 
#     fizz_buzz(5) ➞ "Buzz"
# 
#     fizz_buzz(15) ➞ "FizzBuzz"
# 
#     fizz_buzz(4) ➞ "4"
# 
# </code>

# In[1]:


def cal_fb(n):
    
    return ('Fizz'*(not n%3) + 'Buzz'*(not n%5)) if n%3 == 0 or n%5 == 0 else str(n) 


# In[2]:


cal_fb(3)


# In[3]:


cal_fb(5)


# In[4]:


cal_fb(15)


# In[5]:


cal_fb(4)


# In[ ]:




