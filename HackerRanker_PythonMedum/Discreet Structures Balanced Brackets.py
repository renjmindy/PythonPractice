#!/usr/bin/env python
# coding: utf-8

# ## Discreet Structures: Balanced Brackets
# 
# A sequence of brackets is said to be **balanced** if:
# 
# 1. It starts with an opening bracket
# 
# 2. It ends with a closing bracket
# 
# 3. At any instance, the number of closing brackets should not exceed the number of opening brackets.
# 
# 4. The number of opening and closing brackets should be equal.
# 
# A string **S** consisting of only **'('** and **')'** with an integer **N** is given. 
# 
# From the string, a substring with **N**-balanced brackets is removed and the left and right side of the deleted substring is concatenated.
# 
# You need to repeatedly remove **N**-balanced brackets such that no more **N**-balanced brackets exist.
# 
# **Write a program to print the resultant string after performing the operations.**
# 
# ### Note
# 
# * An **N**-balanced bracket means having consecutive N-times **'('** followed by N-times **')'**.
# 
# * For e.g. **N=3**, String s = **"((()))"** is valid n-balanced parenthesis
# 
# * But **"() () ()"**, **"))) ((("**, **“) ((())"** and **"(() ())"** are not.
# 
# * If there are no N-balanced brackets present in the string, print the string itself.
# 
# ### Input Format
# 
# Each test case contains a single line with space-separated **string S** and **integer N**.
# 
# ### Sample Input
# 
# `((())())() 2   -- denotes string S & N`
# 
# ### Output Format
# 
# Print the resultant string after performing these operations.
# 
# ### Sample Output
# 
# `()`
# 
# ### Explanation
# 
# Firstly, substring "(())" from index 1 to 4 is removed, i.e., (****())().
# 
# String so formed is " (())()"
# 
# Substring "(())" from index 0 to 3 is removed, ie, ****().
# 
# String so formed is **()**.

# In[1]:


def balancedBrackets(S, N): 
    
    bList = ['(', ')']
    sList = list(S)
    rList = []
    
    oList = []
    eList = []
    dList = []
    dpList = []
    result = 0
    
    for si in range(0, len(sList), 1):
        
        if sList[si] == bList[0]:
            oList.append(si)
        else:
            eList.append(si)
            
    #print(oList)
    #print(eList)
    
    for i in range(0, len(oList), 1):
        if oList[i] < eList[i]:
            result += 1
            if eList[i] - oList[i] < N:
                dList.append(oList[i])
                dList.append(eList[i])
            else:
                if (eList[i] - oList[i]) % 4 > 0:
                    dpList.append(oList[i])
                    dpList.append(eList[i])
       
    #print(result,' ', len(S))
    #print(sorted(dList))
    #print(sorted(dpList))
    
    if result > 0:
        if result == len(S):
            for n in range(0, result % N, 1):
                rList += bList
        else:
            if result % N > 0:
                for n in range(0, result % N, 1):
                    rList += bList
                for n in range(0, 2*(len(oList)-result), 1):
                    if n % 2 == 0:
                        rList += ')'
                    else:
                        rList += '('
            else:
                dList += dpList[4:8]
                for i in sorted(dList):
                    rList += S[i]
    else:
        rList = S
            
    return ''.join(rList)
    


# In[2]:


S = "((())())()" 
N = 2
balancedBrackets(S, N)


# ()

# In[3]:


S = ")))(((" 
N = 2
balancedBrackets(S, N)


# )))(((

# In[4]:


S = "((())())(())()" 
N = 2
balancedBrackets(S, N)


# ()

# In[5]:


S = "((()))(((()))))()(" 
N = 2
balancedBrackets(S, N)


# ())()(

# In[6]:


S = "(((((((((((())))))))))))(((((())))))(((())))((()))(())()"
N = 4
balancedBrackets(S, N)


# (())((()))(())()

# In[7]:


S = "))(())(())(())((" 
N = 3
balancedBrackets(S, N)


# ))(())(())(())((

# In[ ]:




