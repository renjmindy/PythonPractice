#!/usr/bin/env python
# coding: utf-8

# ## Q1: Array Operations: Next Greater Elements (NGE)

# ### Input Format
# 
# The first line of input contains an integer **N**, denoting the size of the array.
# 
# The next line contains **N** number of space-separated integers denoting the elements of array, **arr**. 
# 
# 
# ### Sample Input
# 
# 5     -- denotes N
# 
# 5 3 10 15 20 -- denotes N elements of array **arr**
# 
# 
# ### Output Format
# 
# The output should be in integer and should show all the elements of the array **result**, containing the NGE of each and every element separated by whitespace each and -1 if the NGE to be right.     
# 
# 
# ### Sample Output
# 
# 10 10 15 20 -1
# 
# 
# ### Explanation
# 
# The NGE of **5** is **10**. Hence, **result[0]=10**.
# 
# The NGE of **3** is **10**. Hence, **result[1]=10**.
# 
# The NGE of **10** is **15**. Hence, **result[2]=15**.
# 
# The NGE of **15** is **20**. Hence, **result[3]=20**.
# 
# The NGE of **20** does not exist as it is the rightmost integer in the array. 
# 
# Hence, **result[4]=-1**.
# 
# Therefore, the answer is **10 10 15 20 -1**.

# In[1]:


def nextGreaterElement(N, A):
    
    result = []
    
    for n_i in range(0, N, 1):
        for n_f in range(n_i+1, N, 1):
            if A[n_f] > A[n_i]:
                result.append(A[n_f])
                break
            else:
                continue
                
    result.append(-1)            
    print(result)
    
    return result


# In[2]:


N = 5
A = [5, 3, 10, 15, 20]
nextGreaterElement(N, A)


# In[ ]:




