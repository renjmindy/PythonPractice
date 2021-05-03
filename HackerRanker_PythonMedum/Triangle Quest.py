#!/usr/bin/env python
# coding: utf-8

# ## Triangle Quest
# 
# You are given a positive integer **N**. Print a numerical triangle of height **N-1** like the one below:
# 
# ``
# 1
# 22
# 333
# 4444
# 55555
# ......
# ``
# 
# Can you do it using only **arithmetic operations, a single for loop and print statement?**
# 
# Use no more than two lines. The first line (the for statement) is already written for you. You have to complete the print statement.
# 
# **Note**: Using anything related to strings will give a score of .
# 
# ### Input Format
# 
# A single line containing integer, **N**.
# 
# ### Constraints
# 
# 1 <= N <= 9
# 
# ### Output Format
# 
# Print **N-1** lines as explained above.
# 
# ### Sample Input
# 
# ``
# 5
# ``
# 
# ### Sample Output
# 
# ``
# 1
# 22
# 333
# 4444
# ``

# In[1]:


N = 5
for i in range(1, N, 1):
    print((10**i//9)*i)


# In[ ]:




