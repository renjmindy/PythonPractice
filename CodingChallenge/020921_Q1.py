#!/usr/bin/env python
# coding: utf-8

# Create a function that determines the minimum number of characters needed to make a strong password.
# 
# A password is considered strong if it satisfies the following criteria:
# 
# * Its length is at least 6.
# 
# * It contains at least one digit.
# 
# * It contains at least one lowercase English character.
# 
# * It contains at least one uppercase English character.
# 
# * It contains at least one special character: !@#\$\%\^\&\*\(\)\-\+
# 
# Types of characters in a form you can paste into your solution:
# 
# <code>
# 
#     static final String numbers = "0123456789";
# 
#     static final String lower_case = "abcdefghijklmnopqrstuvwxyz";
# 
#     static final String upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
# 
#     static final String special_characters = "!@#$%^&*()-+";
# 
# </code>

# In[ ]:


def cal_minPassword(s):
    
    slist = list(s.split(''))
    
    count_dig = 0
    count_low = 0
    count_upp = 0
    count_spe = 0
    count_out = 0
    
    symList = ['!',"'",'@','#','$','%','^','&','*','(',')','-','+']
    
    if len(slist) >= 6:
        for s in slist:
            if s.isdigit():
                count_dig += 1
            elif s.islower():
                count_low += 1
            elif s.isupper():
                count_upp += 1
            elif s in symList:
                count_spe += 1
            else:
                count_out += 1
    else:
        return False
    
    if count_dig >= 1 and count_low >= 1 and count_upp >= 1 and count_spe >= 1:
        return True
    else:
        return False

