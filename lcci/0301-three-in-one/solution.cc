class TripleInOne {
    array<vector<int>, 3> inner;
    int max_size;
    array<int, 3> len;

public:
    TripleInOne(int stackSize): max_size(stackSize), len{} {
        for (auto& v : inner) {
            v = vector<int>(max_size);
        }
    }
    
    void push(int i, int val) {
        if (len[i] == max_size) {
            return;
        }
        auto& p = len[i];
        inner[i][p] = val;
        ++p;
    }
    
    int pop(int i) {
        if (len[i] == 0) {
            return -1;
        }

        auto& p = len[i];
        --p;
        return inner[i][p];
    }
    
    int peek(int i) {
        if (len[i] == 0) {
            return -1;
        }

        auto p = len[i] - 1;
        return inner[i][p];
    }
    
    bool isEmpty(int i) {
        return len[i] == 0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */

