#!/usr/bin/env python
# coding: utf-8

# Create a function that takes a string and returns true or false depending on whether or not the formula is correct.
# 
# **Examples**
# 
# formula("6 * 4 = 24") ➞ true
# 
# formula("18 / 17 = 2") ➞ false
# 
# formula("16 * 10 = 160 = 14 + 120") ➞ false
# 
# **Notes**
# 
# You have to figure out what a is.
# 
# You do not need to dynamically find the value of a (it's a constant and the same across all tests).
# 
# Ignore the spaces.

# In[1]:


import operator

ops = {'+' : operator.add, '-' : operator.sub,
       '*' : operator.mul, '/' : operator.truediv,  # use operator.div for Python 2
       '%' : operator.mod, '^' : operator.xor}

def eval_binary_expr(op1, oper, op2):
    
    op1, op2 = int(op1), int(op2)
    return ops.get(oper)(op1, op2)
    
def cal_formula(s):
    
    slist = list(s.split('='))
    olist = ['+', '-', '*', '/']
    mlist = []
    nlist = []
    rlist = []
    clist = []
    
    mlist = [s.replace(' ', '') for s in slist if any(o in s for o in olist)]
    nlist = [int(s) for s in slist if all(o not in s for o in olist)]
    
    #print(mlist, nlist)
    
    for m in mlist:
        #print(m, m[0], m[1], m[2])
        plist = list(m.split(a) for a in m if any(o in a for o in olist))
        qlist = list(b for b in m for o in olist if b == o)
        #print(plist, plist[0][0], plist[0][1], qlist[0])
        rlist.append(eval_binary_expr(plist[0][0], qlist[0], plist[0][1]))
        
    for i, j in enumerate(rlist):
        if len(nlist) == 1:
            if j == nlist[0]:
                clist.append(1)
            else:
                clist.append(-1)
        else:
            clist.append(0)
    
    if -1 in clist:
        return False
    else:
        return True


# In[2]:


cal_formula("6 * 4 = 24")


# In[3]:


cal_formula("18 / 17 = 2")


# In[4]:


cal_formula("16 * 10 = 160 = 14 + 120")


# In[ ]:




