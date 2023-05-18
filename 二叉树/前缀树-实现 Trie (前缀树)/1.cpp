struct Node
{
    vector<Node*> children;
    bool is_word;
    Node() : is_word(false), children(26, nullptr) {}
};

class Trie {
public:
    Trie() 
    {
        root = new Node();
    }
    
    /* 插入 */
    void insert(string word) 
    {
        Node *node = root;
        for(int idx=0; idx<word.size(); idx++)
        {   
            int offset = word[idx] - 'a';
            if(node->children.at(offset) == nullptr)      // 不存在
            {
                node->children[offset] = new Node();
            }

            node = node->children[offset];
        }

        node->is_word = true;
    }

    /* 搜索 */
    bool search(string word) 
    {
        Node *node = root;
        for(int idx=0; idx<word.size(); idx++)
        {   
            int offset = word[idx] - 'a';
            if(node->children.at(offset) == nullptr)      // 不存在
            {
                return false;
            }

            node = node->children[offset];
        }

        return node->is_word == true;
    }
    
    bool startsWith(string prefix) 
    {
        Node *node = root;
        for(int idx=0; idx<prefix.size(); idx++)
        {   
            int offset = prefix[idx] - 'a';
            if(node->children.at(offset) == nullptr)      // 不存在
            {
                return false;
            }

            node = node->children[offset];
        }
        return true;
    }
private:
    Node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */