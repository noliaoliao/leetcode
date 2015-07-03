class TrieNode {
public:
    TrieNode() {
        bWord = false;
        val = 0;
        memset(child,0,sizeof(TrieNode*)*26);
    }
public:
    bool bWord;
    char val;
    TrieNode* child[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *pCur = root;
        for(int i = 0; i < word.length(); i++){
            if(pCur->child[word[i]-'a'] == NULL){
                pCur->child[word[i]-'a'] = new TrieNode();
            }
            pCur->val = word[i];
            pCur = pCur->child[word[i]-'a'];
        }
        pCur->bWord = true;
    }
    
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //构造trie树
        for(int i = 0; i < words.size(); i++){
            trie.insert(words[i]);
        }
        vector<vector<bool>> visted(board.size(), vector<bool>(board[0].size(), false));
        vector<string> allWords;
        string eachWord;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(trie.root->child[board[i][j]-'a']){
                    search(board,trie.root->child[board[i][j]-'a'],visted,i,j,eachWord+board[i][j],allWords);
                }
            }
        }

        return allWords;
    }

    void search(vector<vector<char>>& board, TrieNode* pCur, vector<vector<bool>>& visted, \
                int row, int col, string eachWord,vector<string>& allWords){
        if(pCur->bWord){
            allWords.push_back(eachWord);
            pCur->bWord = false;  //单词标记为false,以免重复记录单词
        }
        int directX[] = {-1,1,0,0};
        int directY[] = {0,0,-1,1};
        visted[row][col] = true;
        for(int i = 0; i < 4; i++){
            int nRow = row+directX[i];
            int nCol = col+directY[i];
            if(nRow < board.size() && nCol < board[0].size() && nRow >= 0 && nCol >= 0 \
                && visted[nRow][nCol] == false \
                &&pCur->child[board[nRow][nCol]-'a']){
                search(board,pCur->child[board[nRow][nCol]-'a'],visted,nRow,nCol,eachWord+board[nRow][nCol],allWords);
            }
        }
        visted[row][col] = false;
    }

private:
    Trie trie;
};