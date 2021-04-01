#!/usr/bin/env python
# coding: utf-8

# ## Validating Credit Card Numbers
# 
# You and Fredrick are good friends. Yesterday, Fredrick received **N** credit cards from **ABCD Bank**. He wants to verify whether his credit card numbers are valid or not. You happen to be great at regex so he is asking for your help!
# 
# A valid credit card from **ABCD Bank** has the following characteristics:
# 
# ► It must start with a **4**, **5** or **6**.
# 
# ► It must contain exactly **16** digits.
# 
# ► It must only consist of digits (**0**-**9**).
# 
# ► It may have digits in groups of **4**, separated by one hyphen **"-"**.
# 
# ► It must NOT use any other separator like ' ' , '_', etc.
# 
# ► It must NOT have **4** or more consecutive repeated digits.
# 
# ### Examples:
# 
# #### Valid Credit Card Numbers
# 
# `4253625879615786`
# 
# `4424424424442444`
# 
# `5122-2368-7954-3214`
# 
# #### Invalid Credit Card Numbers
# 
# `42536258796157867       #17 digits in card number → Invalid`
# 
# `4424444424442444        #Consecutive digits are repeating 4 or more times → Invalid`
# 
# `5122-2368-7954 - 3214   #Separators other than '-' are used → Invalid`
# 
# `44244x4424442444        #Contains non digit characters → Invalid`
# 
# `0525362587961578        #Doesn't start with 4, 5 or 6 → Invalid`
# 
# ### Input Format
# 
# The first line of input contains an integer **N**.
# 
# The next **N** lines contain credit card numbers.
# 
# ### Constraints
# 
# **0 < N < 100**
# 
# ### Output Format
# 
# Print 'Valid' if the credit card number is valid. Otherwise, print 'Invalid'. Do not print the quotes.
# 
# ### Sample Input
# 
# `6`
# 
# `4123456789123456`
# 
# `5123-4567-8912-3456`
# 
# `61234-567-8912-3456`
# 
# `4123356789123456`
# 
# `5133-3367-8912-3456`
# 
# `5123 - 3567 - 8912 - 3456`
# 
# ### Sample Output
# 
# `Valid`
# 
# `Valid`
# 
# `Invalid`
# 
# `Valid`
# 
# `Invalid`
# 
# `Invalid`
# 
# ### Explanation
# 
# 4123456789123456 : **Valid**
# 
# 5123-4567-8912-3456 : **Valid**
# 
# 61234-`567`-8912-3456 : **Invalid**, because the card number is not divided into equal groups of **4**.
# 
# 4123356789123456 : **Valid**
# 
# 51`33`-`33`67-8912-3456 : **Invalid**, consecutive digits **3333** is repeating **4** times.
# 
# 5123 -- 4567 -- 8912 -- 3456 : **Invalid**, because space '  ' and - are used as separators.

# In[1]:


import numpy as np
import re


# In[2]:


def validate_card(N, A):
    
    result = []
    
    sList = ['4', '5', '6']
    
    for n in range(0, N, 1):
        
        aList = list(A[n])
        bList = [i for i in aList if i.isdigit() == True]
        pass1 = False
        pass2 = False
        pass3 = False
        pass4 = False
        
        if aList[0] in sList and len(bList) == 16 and ''.join(bList).isdigit():
            pass1 = True
        else:
            pass1 = False
        
        if pass1:
            hList = []
            
            if '-' not in aList:
                pass2 = True
            else:
                for i in range(0, len(aList), 1):
                    if aList[i] == '-':
                        hList.append(i+1)
                    else:
                        continue
                        
            for i in hList:
                if i % 5 != 0 or i == 0:
                    pass2 = False
                    break
                else:
                    pass2 = True
            
        if pass1 and pass2:
            
            if ' ' not in aList and '_' not in aList:
                pass3 = True
            else:
                pass3 = False
                
        if pass1 and pass2 and pass3:
            found = False
            cDict = dict()
            
            for i in range(0, len(aList), 1):
                cDict[aList[i]] = cDict.get(aList[i], 0) + 1
                
            for v in cDict.values():
                if v >= 4:
                    found = True
                    break
                else:
                    found = False
            
            if found:
                
                for k, v in cDict.items():
                    cList = []
                    dList = []
                    if v >= 4:
                        #print(k,' ',v)
                        for i in range(0, len(bList), 1):
                            if bList[i] == k:
                                cList.append(i+1)
                            else:
                                continue
                        dStr = ''.join(str(np.diff(np.array(cList))))
                        #print(cList,' ',dStr)
                        if dStr.find('1 1 1') == 1:
                            pass4 = False
                            break
                        else:
                            pass4 = True
                    else:
                        continue
                        
            else:
                pass4 = True
                
        print(pass1,' ',pass2,' ',pass3,' ',pass4)        
                
        if pass1 and pass2 and pass3 and pass4:
            result.append('Valid')
        else:
            result.append('Invalid')
            
    return ', '.join(result)


# In[3]:


N = 6
A = ['4123456789123456', '5123-4567-8912-3456', '61234-567-8912-3456', '4123356789123456', '5133-3367-8912-3456', 
     '5123 - 3567 - 8912 - 3456']
validate_card(N, A)


# Valid, Valid, Invalid, Valid, Invalid, Invalid

# In[4]:


N = 5
A = ['7165863385679329', '6175824393389297', '5252248277877418', '9563584181869815', '5179123424576876']
validate_card(N, A)


# Invalid, Valid, Valid, Invalid, Valid

# In[5]:


N = 5
A = ['7165863385679329', '6175824393389297', '5252248277877418', '9563584181869815', '5179123424576876']
validate_card(N, A)


# Invalid, Valid, Valid, Invalid, Valid

# In[6]:


N = 50
A = ['1182387522195848', '4898285859544556', '3533946521218854', '2178579985193175', '9691928949545344',
     '1327576477684519', '6885867822596993', '1958129523778579', '2357676157819124', '9832746248713726',
     '3673159777236652', '8626186974574971', '9687622296992497', '6731749895254584', '8231635922318254',
     '7728878259735616', '3347275338764373', '6624557432269847', '3164653818478977', '7683817293887423',
     '4654491168789767', '6942469919536219', '8434524674271379', '6619249165433473', '8842787232483367',
     '5349898497837349', '4841565975496529', '7635659522159832', '6699889899699968', '5274676861386577',
     '7261479482325831', '9855821811363989', '5462941623272486', '2168457338741692', '3493828267535654',
     '7688277563695358', '4621162653647299', '5588937472734175', '6313634439334582', '2621731928824298',
     '9356326214767474', '6399396262113367', '7326622854597675', '2179646384144599', '8723731421194264',
     '9893925198222769', '8493394862176119', '9182146786584817', '7865278423923993', '5437343432579992']
validate_card(N, A)


# Invalid, Valid, Invalid, Invalid, Invalid, Invalid, Valid, Invalid, Invalid, Invalid, Invalid, Invalid, Invalid, Valid, Invalid, Invalid, Invalid, Valid, Invalid, Invalid, Valid, Valid, Invalid, Valid, Invalid, Valid, Valid, Invalid, Valid, Valid, Invalid, Invalid, Valid, Invalid, Invalid, Invalid, Valid, Valid, Valid, Invalid, Invalid, Valid, Invalid, Invalid, Invalid, Invalid, Invalid, Invalid, Invalid, Valid

# In[7]:


N = 6
A = ['3695-7963-915827-75', '3143-4672-8798-2968-2968', '6444-4444-4444-4918', '6865396515642918', '6865396515642', 
     '4695-7963-9778-2775']
validate_card(N, A)


# Invalid, Invalid, Invalid, Valid, Invalid, Valid

# In[8]:


N = 4
A = ['3695-7963-  5827-75', '4143-4672-8798-2968-2968', '6865---------------3965---------------1564-------------2918',
     '6865396515642918']
validate_card(N, A)


# Invalid, Invalid, Invalid, Valid

# In[ ]:




