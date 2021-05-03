#!/usr/bin/env python
# coding: utf-8

# ## Find Angle MBC
# 
# ![image.png](attachment:image.png)
# 
# 
# ### Input Format
# 
# The first line contains the length of side AB.
# 
# The second line contains the length of side BC.
# 
# ### Constraints
# 
# * 0 < AB <= 100
# 
# * 0 < BC <= 100
# 
# Lengths AB and BC are natural numbers.
# 
# ### Output Format
# 
# Output angle MBC in degrees.
# 
# **Note**: Round the angle to the nearest integer.
# 
# ### Examples:
# 
# If angle is 56.5000001°, then output 57°.
# If angle is 56.5000000°, then output 57°.
# If angle is 56.4999999°, then output 56°.
# 
# 0° < theta < 90°
# 
# ### Sample Input
# 
# ``
# 10
# ``
# 
# ``
# 10
# ``
# 
# ### Sample Output
# 
# ``
# 45°
# ``

# In[1]:


from math import atan2, degrees
N = 10
M = 10
print(str(int(round(degrees(atan2(N,M)))))+'°')


# In[ ]:




