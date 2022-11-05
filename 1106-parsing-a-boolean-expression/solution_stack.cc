class Solution {
    stack<char> ops;
    stack<bool> vals;
    
    void push(bool val) {
        if (ops.empty()) {
            vals.push(val);
            return ;
        }
        switch (ops.top()) {
            case '&':
                val &= vals.top();
                vals.pop();
                vals.push(val);
                break;
            case '|':
                val |= vals.top();
                vals.pop();
                vals.push(val);
                break;
            case '!':
                vals.push(!val);
                break;
        }
    }
    
public:
    bool parseBoolExpr(string expression) {
        for (auto& c : expression) {
            switch (c) {
                case 't': push(true); break;
                case 'f': push(false); break;
                case ')': ops.pop(); { bool val = vals.top(); vals.pop(); push(val); } break;
                case '&': ops.push('&'); vals.push(true); break;
                case '|': ops.push('|'); vals.push(false); break;
                case '!': ops.push('!');
                default:  break;
            }
        }

        return vals.top();
    }
};
