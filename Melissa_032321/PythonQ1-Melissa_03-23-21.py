#!/usr/bin/env python
# coding: utf-8

# ## Q1: Mathematical Calculations: Counting Subsequences

# ### Input Format
# 
# The first line of input contains a single integer **N**.
# 
# The next line contains the string *S* of size **N**.
# 
# The next line contains an integer **Q** denoting the number of queries.
# 
# Next, **Q** lines contain an index (i) in each line denoting a query. 
# 
# 
# ### Sample Input
# 
# 5     -- denotes N
# 
# 01111 -- denotes string S
# 
# 2     -- denotes Q
# 
# 0     -- denotes the query
# 
# 0     -- denotes the query
# 
# 
# ### Output Format
# 
# Each line prints the sum of the number of sequences.
# 
# 
# ### Sample Output
# 
# 0
# 
# 1
# 
# ### Explanation
# 
# String after query 1: 11111 - This sequence does not have either 01 or 10
# 
# String after query 2: 01111 - This sequence has the subsequence 01.
# 
# Hence, the output is
# 
# 0
# 
# 1

# In[ ]:


def NumberofSubsequences(N, S, queries, Q):
    
    # this is default OUTPUT. You can change it
    
    result = []
    n = 0
    
    # write your Logic here:
    
    
    
    # OUTPUT [uncomment & modify if required]
    # Print each result on next line
    for i in result:
        print(i)
        
        
    # INPUT [uncomment & modify if required]
    N = int(input())
    S = str(input())
    Q = int(input())
    queries = []
    
    for i in range(Q):
        queries.append(int(input()))


# In[1]:


def NumberofSubsequences(N, S, queries, Q):
    
    result = []
    #
    #
    # no way to flip a char in one string
    # so we first convert a string to a list
    # then, loop over each element and match
    # now we can flip one single char if matched
    #
    #
    NS = list(S)
    #print('before flipping:', NS)
    
    for q in range(0, queries, 1):
        
        rn = 0
        
        S_1 = [] # first element in S
        S_2 = [] # second element in S 
        S_3 = [] # sum of first and second elements in S
             
        if NS[Q[q]] == '0':
            NS[Q[q]] = '1'
            #print('>>> here', Q[q], NS[Q[q]])
        else:
            NS[Q[q]] = '0'
            #print('>>> here', Q[q], NS[Q[q]])
            
        #print('after flipping:', NS)
        
        for n in range(0, N, 1): # 0 - (N-1)
        
            if n < N-1: # 0 - (N-2)
                S_1.append(int(NS[n]))
            
            if n > 0: # 1 - (N-1)   
                S_2.append(int(NS[n]))
            
        #print('S_1', S_1)
        #print('S_2', S_2)
            
        for n in range(0, N-1, 1):
            S_3.append(S_1[n] + S_2[n])
            
        #print('S_3', S_3)
        
        for n in range(0, len(S_3), 1):
            # 01 or 10 : sum of either (0, 1) or (1, 0) equals to 1
            if S_3[n] == 1:
                rn += 1
            else:
                rn += 0
                
        result.append(rn)
        
    for i in result:
        print(i)

    return result


# In[2]:


N = 5
S = '01111'
queries = 2
Q = [0, 0]
NumberofSubsequences(N, S, queries, Q)


# In[3]:


N = 1
S = '0'
queries = 1
Q = [0]
NumberofSubsequences(N, S, queries, Q)


# In[4]:


N = 10
S = '1110000010'
queries = 4
Q = [4, 1, 5, 4]
NumberofSubsequences(N, S, queries, Q)


# In[5]:


N = 99
S = '001011111010100101001101110111010110100001000001001010010100111100001001111011001001000111011010011'
queries = 1
Q = [36]
NumberofSubsequences(N, S, queries, Q)


# In[6]:


N = 10
S = '0000100011'
queries = 8
Q = [5, 6, 7, 9, 3, 2, 1, 4]
NumberofSubsequences(N, S, queries, Q)


# In[7]:


N = 99
S = '001110101101011110100101011111101011110101101001010010101001101010010111000101100000110111110001100'
queries = 10
Q = [44, 0, 19, 23, 95, 48, 64, 8, 9, 35]
NumberofSubsequences(N, S, queries, Q)


# In[ ]:




