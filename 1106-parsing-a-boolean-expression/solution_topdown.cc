class Solution {
    string expr;
public:
    pair<bool, int> apply(char function_name, int l) {
        cout << function_name << endl;
        int i;
        bool base;
        switch (function_name) {
            case '!':
                switch (expr[l + 2]) {
                    case 't':
                        return {false, l + 4};
                    case 'f':
                        return {true, l + 4};
                    default: {
                        const auto& [val, new_cursor] = apply(expr[l + 2], l + 2);
                        return {!val, new_cursor + 1};
                    }
                }
                return {expr[l + 2] == 'f', l + 4};   // !(t)
            case '&': {
                base = true;
                for (i = l + 2; expr[i] != ')'; ++i) {
                    cout << expr[i] << ' ';
                    switch (expr[i]) {
                        case 't':
                            base &= true;
                            break;
                        case 'f':
                            base &= false;
                            break;
                        case ',':
                            break;
                        default: {
                            const auto& [val, new_cursor] = apply(expr[i], i);
                            base &= val;
                            i = new_cursor - 1;  // then ++i
                            break;
                        }
                    }
                }
                break;
            }
            case '|': {
                base = false;
                for (i = l + 2; expr[i] != ')'; ++i) {
                    switch (expr[i]) {
                        case 't':
                            base |= true;
                            break;
                        case 'f':
                            base |= false;
                            break;
                        case ',':
                            break;
                        default: {
                            const auto& [val, new_cursor] = apply(expr[i], i);
                            base |= val;
                            i = new_cursor - 1;  // then ++i
                            break;
                        }
                    }
                }
                break;
            }
        }
        return {base, i + 1};
    }

    bool parseBoolExpr(string expression) {
        expr = expression;
        switch (expression[0]) {
            case 't': return true;
            case 'f': return false;
        }
        return apply(expression[0], 0).first;
    }
};

