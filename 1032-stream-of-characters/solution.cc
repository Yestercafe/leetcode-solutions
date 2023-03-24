struct TrieNode {
    bool terminated;
    array<TrieNode*, 26> nxt;
    TrieNode() : terminated{false}, nxt{} {}

    bool contains(const deque<char>& s) {
        auto curr = this;
        for (char c : s) {
            int ord = c - 'a';
            if (!curr->nxt[ord]) {
                return false;
            } else {
                curr = curr->nxt[ord];
            }
            if (curr->terminated) return true;
        }
        return curr->terminated;
    }

    void insert(const string& s) {
        auto curr = this;
        for (auto ri = s.crbegin(); ri != s.crend(); ++ri) {
            char c = *ri;
            int ord = c - 'a';
            if (curr->nxt[ord]) {
                curr = curr->nxt[ord];
            } else {
                curr = curr->nxt[ord] = new TrieNode;
            }
        }
        curr->terminated = true;
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for (const string& s : words) {
            trie.insert(s);
        }
    }
    
    bool query(char letter) {
        d.push_front(letter);
        return trie.contains(d);
    }
private:
    TrieNode trie;
    deque<char> d;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

