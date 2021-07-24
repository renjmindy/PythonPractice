#!/usr/bin/env python
# coding: utf-8

# A number may not be a palindrome, but its descendant can be. A number's direct child is created by summing each pair of adjacent digits to create the digits of the next number.
# 
# For instance, 123312 is not a palindrome, but its next child 363 is, where: 3 = 1 + 2; 6 = 3 + 3; 3 = 1 + 2.
# 
# Create a function that returns true if the number itself is a palindrome or any of its descendants down to the first 2 digit number (a 1-digit number is trivially a palindrome).
# 
# **Examples**
# 
# palindromedescendant(11211230) ➞ true
# 
# // 11211230 ➞ 2333 ➞ 56 ➞ 11
# 
# palindromeDescendant(13001120) ➞ true
# 
# // 13001120 ➞ 4022 ➞ 44
# 
# palindromeDescendant(23336014) ➞ true
# 
# // 23336014 ➞ 5665
# 
# palindromeDescendant(11) ➞ true
# 
# // Number itself is a palindrome.
# 
# **Notes**
# 
# Numbers will always have an even number of digits.

# In[1]:


def cal_palindrome(n):
    
    nlist = list(str(n))
    
    if len(nlist) % 2 != 0:
        return False
    else:
        if nlist == nlist[::-1]:
            return True
        else:
            msize = len(nlist)
            while msize >= 2:
                mlist = []
                for i in range(0, len(nlist), 2):
                    mlist.append(int(nlist[i])+int(nlist[i+1]))
        
                msize = len(mlist)
                nlist = mlist.copy()
                #print(msize, nlist)
        
                if nlist == nlist[::-1]:
                    return True
        
            return False    


# In[2]:


cal_palindrome(11211230)


# In[3]:


cal_palindrome(13001120)


# In[4]:


cal_palindrome(23336014)


# In[5]:


cal_palindrome(11)


# In[ ]:




