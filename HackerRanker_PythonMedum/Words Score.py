#!/usr/bin/env python
# coding: utf-8

# ## Words Score
# 
# In this challenge, the task is to debug the existing code to successfully execute all provided test files.
# 
# Consider that vowels in the alphabet are a, e, i, o, u and y.
# 
# Function score_words takes a list of lowercase words as an argument and returns a score as follows:
# 
# The score of a single word is **2** if the word contains an even number of vowels. Otherwise, the score of this word is **1**. The score for the whole list of words is the sum of scores of all words in the list.
# 
# Debug the given function score_words such that it returns a correct score.
# 
# Your function will be tested on several cases by the locked template code.
# 
# ### Input Format
# 
# The input is read by the provided locked code template. In the first line, there is a single integer  denoting the number of words. In the second line, there are **n** space-separated lowercase words.
# 
# ### Constraints
# 
# * **1 <= n <= 20**
# 
# * Each word has at most **20** letters and all letters are English lowercase letters
# 
# ### Output Format
# 
# The output is produced by the provided and locked code template. It calls function score_words with the list of words read from the input as the argument and prints the returned score to the output.
# 
# ### Sample Input 0
# 
# `2`
# 
# `hacker book`
# 
# ### Sample Output 0
# 
# `4`
# 
# ### Explanation 0
# 
# There are two words in the input: hacker and book. The score of the word hacker is **2** because it contains an even number of vowels, i.e. **2** vowels, and the score of book is **2** for the same reason. Thus the total score is **2+2=4**.
# 
# ### Sample Input 1
# 
# `3`
# 
# `programming is awesome`
# 
# ### Sample Output 1
# 
# `4`
# 
# ### Explanation 1
# 
# There are **3** words in the input: programming, is and awesome. The score of programming is **1** since it contains **3** vowels, an odd number of vowels. The score of is is also **1** because it has an odd number of vowels. The score of awesome is **2** since it contains **4** vowels, an even number of vowels. Thus, the total score is **1+1+2=4**.

# def is_vowel(letter):
# 
#     return letter in ['a', 'e', 'i', 'o', 'u', 'y']

# In[1]:


def score_words(N, words):
    
    vList = ['a', 'e', 'i', 'o', 'u', 'y']
    
    wList = list(words.split(' '))
    
    result = 0
    
    for n in range(0, N):
        nVowels = 0
        for w in wList[n]:
            if w in vList:
                nVowels += 1
        if nVowels % 2 == 0:
            result += 2
        else:
            result += 1
    
    return result


# In[2]:


N = 2
words = "hacker book"
score_words(N, words)


# 4

# In[3]:


N = 3
words = "programming is awesome"
score_words(N, words)


# 4

# In[4]:


N = 7
words = "motmjatlirwxbkqbhkh ujxxfuabn nsgvtsbiexrjww kpcnzkgukfiwwlcptyc rvkhqdudg hjanmpuacpghbbyvax jgavhhhj"
score_words(N, words)


# 8

# In[5]:


N = 5
words = "vuv tpikawrurtmtcrs ajhgby tbnvycfnc bdczzgqygrpvoploooab"
score_words(N, words)


# 7

# In[6]:


N = 5
words = "nawdqzszrlvnetjzlvvo yicpmhpdnneuujxck qvzzaohijlinv hed khya"
score_words(N, words)


# 7

# In[7]:


N = 7
words = "fbibepbwicbq vqpyywkbvkyjzsmhydvh gn axkzfhkyjcgyoaspzex mcrzwd cohtzztocconrmbzle znimrpssdsbkma"
score_words(N, words)


# 13

# In[8]:


N = 4
words = "lcfsnnhbiwjpyn bysdtsnrp llevkowqmkriztmgzl tbplwxh"
score_words(N, words)


# 6

# In[9]:


N = 10
words = "dkkbcyx eewlqcnujguugob w unjcwq xghkyiwkzcojcaj smsehtspdhmtbjiqoye o yhigvnueggo muuvktkgfmbfq evyusixxixbn"
score_words(N, words)


# 14

# In[10]:


N = 18
words = "ehopcjxxlblxcjz nkrvqnvjpg vwxtg fbjrjpjjhurihqjogbzv iocoyvctjox tpuyibwaby gb dawslcofcaz iowjrcncn siblrumdncwefeirftg fwgbjjcsvyihrkjfza pvek wfuqjvdzmpvq toaqnplkefvvhzzckj ucwmjxutkclh rizmiavejafewt wxfnotyzilyumnopfeyz hxdbxuytxmnbbddc"
score_words(N, words)


# 27

# In[11]:


N = 19
words = "lfaoklxt ny ofwkdpcagynwsxj oiw lzrqawiljymnso ksxjhmpojdnds wsgljmpmzibl mwsvqz kwjk bkdmwgidvypggzd st zryelpuzufmmtbhezych g tcavhcezcdxzf ybddabfmiqptksfd mffyqqm gro bwl iacrscoumh"
score_words(N, words)


# 31

# In[12]:


N = 9
words = "ckaxoakvbaeqfqs cifiu nijgmgrscnnxajdk kwfavkpjr bsn vqlxhroslsfeczhktr eofebgskvihpgosgtdsx cmi ikory"
score_words(N, words)


# 12

# In[13]:


N = 8
words = "xrihnnslrncdwq vdctdghmgkrjuhyjk urntsmnksblmau kzxmdiqba qygjktceqpz nfjlpfyiqb jwqdxajedhruuflkdz nuhokuvmxbhpak"
score_words(N, words)


# 14

# In[ ]:




