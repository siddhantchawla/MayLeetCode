class TrieNode {
    public:
        bool isEnd = false;
        TrieNode *children[26];
        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = NULL;

            isEnd = false;
        }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *node = root;
        for (char cur : word)
        {
            int index = cur - 97;
            if (node->children[index] == NULL)
            {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* node = root;
        for (char cur : word)
        {
            int index = cur - 97;
            if (node->children[index] != NULL)
            {
                node = node->children[index];
                continue;
            }
            return 0;
         }
         if (node->isEnd == true)
            return 1;
        return 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word)
    {
        TrieNode* node = root;
        for (char cur : word)
        {
            int index = cur - 97;
            if (node->children[index] != NULL)
            {
                node = node->children[index];
                continue;
            }
            return 0;
         }
        if(node == NULL)
            return false;

        if(node->isEnd == true)
            return true;

        for(int i=0;i<26;i++)
        {
            if(node->children[i]!=NULL)
                return true;
        }
        return false;
    }

private:
    TrieNode* root;


};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */