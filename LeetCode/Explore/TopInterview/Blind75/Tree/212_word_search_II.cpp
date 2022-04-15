// ...
class Solution {
    
public:
    struct node
    {
        char c;
        int ending;
        string word;
        node *childrens[26];
    };
    
    node* getNode(char c)
    {
        node* newNode=new node;
        newNode->c=c;
        newNode->ending=0;
        newNode->word="";
        for(int i=0;i<26;i++)
            newNode->childrens[i]=NULL;
        return newNode;
    }
    
    node* root= getNode('/');
    
    void insert(string s)
    {
        node* curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->childrens[s[i]-'a']==NULL)
            {
                curr->childrens[s[i]-'a']=getNode(s[i]);
            }
            curr=curr->childrens[s[i]-'a'];
        }
        curr->ending++;
        curr->word=s;
    }
    
    void dfs(vector<vector<char>>&board,int i,int j,vector<string> &res,node* curr)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='#')
            return;
        if(curr->childrens[board[i][j]-'a']==NULL)
            return;
        curr=curr->childrens[board[i][j]-'a'];
        if(curr->ending>0)
        {
            res.push_back(curr->word);
            curr->ending--;
        }
        
        char ch=board[i][j];
        board[i][j]='#';
        dfs(board,i+1,j,res,curr);
        dfs(board,i-1,j,res,curr);
        dfs(board,i,j+1,res,curr);
        dfs(board,i,j-1,res,curr);
        board[i][j]=ch;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word:words)
            insert(word);
        vector<string> res;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                dfs(board,i,j,res,root);
            }
        }
        return res;
        
    }
};
