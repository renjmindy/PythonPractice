#!/usr/bin/env python
# coding: utf-8

# ## String Manipulation 
# 
# You are given **N strings**, each string is either an int, a long, a double or none of the above, i.e. just a string.
# 
# You are required to count the total number of int, long, double and other strings (which are not any of the three) in the N strings.
# 
# If the string is an int, it will be considered as an int only, and it will not affect the count of long or double. Similarly, if a string is long, it will not affect the count of double.
# 
# In most programming languages, there are 3 commonly used data types:
# 
# * **int** - an integer between **-2,147,483,648** and **2,147,483,647**.
# 
# * **long** - an integer between **-9,223,372,036,854,775,808** and **9,223,372,036,854,775,807**.
# 
# * **double** - a real number between **-1.79769313486231570E+308** and **1.79769313486231570E+308**.
# 
# **Find and print the total number of int, long, double and other strings among the N strings.**
# 
# ### Note
# 
# * An **int** is also a **long** and **double**, and a **long** is also a **double**
# 
# ### Input Format
# 
# The first line of input contains a single integer **N** denoting the number of input strings.  
# 
# The next N lines contain a string **S**.
# 
# **S** is either an integer number, a real number or a regular string of characters {a-z, A-Z, 0-9, '.'}
# 
# ### Sample Input
# 
# `6`
# 
# `123456`
# 
# `123456123456123456`
# 
# `123456123456123456.123456123456123456`
# 
# `123456123456123456.123456123456123456.123456123456123456`
# 
# `abcdef`
# 
# `45a.23`
# 
# ### Output Format
# 
# Output 4 integers denoting the count of int, long, double and regular strings respectively among the N strings.
# 
# ### Sample Output
# 
# `1 1 1 3`

# In[1]:


def dataTypeCounter(N, value):
    
    countN = 0
    countL = 0
    countD = 0
    countS = 0
    
    for n in range(0, N, 1):
        
        findN = False
        
        try: 
            value[n] == float(value[n])
                
            if float(value[n]) > -2147483648 and float(value[n]) < 2147483647:
                if '.' not in value[n]:
                    #print(value[n])
                    FindN = True
                    countN += 1
                    
            elif float(value[n]) > -9223372036854775808 and float(value[n]) < 9223372036854775807 and findN == False:
                if '.' not in value[n]:
                    #print(value[n])
                    countL += 1
                
            else:
                #print(value[n])
                #print('beyond')
                countD += 1
            
        except Exception as e:
            #print(e)
            countS += 1
            
    if countD != N - countS - countN - countL:
        countD = N - countS - countN - countL 
            
    return countN, countL, countD, countS


# In[2]:


N = 6
value = ['123456', '123456123456123456', '123456123456123456.123456123456123456', '123456123456123456.123456123456123456.123456123456123456', 'abcdef', '45a.23']
dataTypeCounter(N, value)


# 1 1 1 3 

# In[3]:


N = 10 
value = ['Ok921np3CBhdC777IjHXMNgrAtqZJW5nkcvIzCXZcT', 
         'FcllGGXCyi7643Rp0QryNfA.3XvUCGAVNN89ERiuqWjPHuYn', 
         '7', '7.79816653546852E22', '8.434597980560202E69', '865997311', 
         '91713888418031745', '385763320', '9.870908039667745E74', '4nEHP2']
dataTypeCounter(N, value)


# 3 1 3 3

# In[4]:


N = 10 
value = ['3.4948703399907227E64', 's7Exu', '5ZZIUvWO', '399023798', 
         'd7189wVWvhHmE48QBzqAFy8bXC8nAOwb', '281669337335135425', 
         '8.619398385033757E54', 'ivIwqtlAnd3QbS5FZ4p', '1.5844490907103497E87', 
         '4.2096543783575635']
dataTypeCounter(N, value)


# 1 1 4 4

# In[5]:


N = 20 
value = ['.T7YzaFmY19UcJNlnrQ8n5PlGqzmRmPWXSTvZTnJY5J', 
         '256843832646451265', 'CweXQWSHV9B.6TfTl0ebnSEm', 
         '700283486057007233', '3.0721966230022747E81', 
         '7.15747466355304E23', '9.007858210553325E39', 
         '8.764274453412214E93', 'ZCW5Yb0CJ1yCY3qPAJ', 
         '642167384304181121', 'Nvb4mJ90WmKfrG9HEbAxE1zD7c.0', 
         '2.7961665743256296E94', '619020717581792129', 
         '39840071062729137', '3.0375711528645208E16', 
         'dI1c.H72t.c3j8Qko', '943505203529260417', 
         '437842715338542657', 'yyWMLAa.5VL3xCf', '566407262']
dataTypeCounter(N, value)


# 1 7 6 6

# In[6]:


N = 7 
value = ['105882945036338433', '825451196530380673', '982712878407912193', 
         '9.802899796662464E77', '945258492498429057', 'W5SDRG..7', '774143472']
dataTypeCounter(N, value)


# 1 4 1 1

# In[7]:


N = 5 
value = ['105882945036338433', '825451196530380673', '9.802899796662464E77', 
         'W5SDRG..7', '774143472']
dataTypeCounter(N, value)


# 1 2 1 1

# In[ ]:




