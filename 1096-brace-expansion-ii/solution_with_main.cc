#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// LL(1) language:
/*
    expr  = muli expr'
    expr' = NIL | expr
    muli  = Word | '{' addi '}'
    addi  = expr addi'
    addi' = NIl | ',' addi

    first(expr)  = { Alphabets, '{' }
    first(expr') = { NIL, Alphabets, '{' }
    first(muli)  = { Alphabets, '{' }
    first(addi)  = { Alphabets, '{' }
    first(addi') = { NIL, ',' }
    
    follow(expr)  = first(addi') + follow(expr) + follow(expr') = { NIL, ',' }
    follow(expr') = follow(expr) = { NIL, ',' }
    follow(muli)  = first(expr') = { NIL, Alphabets, '{' }
    follow(addi)  = { '}' } + follow(addi) + follow(addi') = { '}' }
    follow(addi') = follow(addi) = { '}' }
*/
namespace helper {
template<typename T>
T cartesian_product(const T& lhs, const T& rhs) {
    T ret;
    for (const auto& l : lhs) {
        for (const auto& r : rhs) {
            // this `plus` for string means concatenate, and it should be *not* commutative
            // since cartesian product is not commutative
            ret.insert(l + r);
        }
    }
    return ret;
};
}

class Parser {
    string expr;
    size_t ptr;
    size_t n;
    using ret_t = unordered_set<string>;
public:
    explicit Parser(string expr) : expr{std::move(expr)}, ptr{0}, n{this->expr.length()} {}

    ret_t parse_expr() {
        cout << "parse_expr " << ptr << endl;
        ret_t ret;
        // expr  = muli expr'
        ret.merge(parse_muli());
        // expr' = NIL | expr
        //follow(muli)  = first(expr') = { NIL, Alphabets, '{' }
        while (ptr < n && (isalpha(expr[ptr]) || expr[ptr] == '{')) {
            ret_t prod = helper::cartesian_product(ret, parse_expr());
            ret = std::move(prod);
        }
        return ret;
    }

    ret_t parse_muli() {
        cout << "parse_muli " << ptr << endl;
        // muli = Word | '{' addi '}'
        auto cc = expr[ptr];
        ret_t ret;
        // first(muli)  = { Alphabets, '{' }
        if (isalpha(cc)) {
            ret.insert(trigger_word());
        } else if (cc == '{') {
            ++ptr;
            ret.merge(parse_addi());
        }
        return ret;
    }
    
    ret_t parse_addi() {
        cout << "parse_addi " << ptr << endl;
        ret_t ret;
        // addi  = expr addi'
        ret.merge(parse_expr());
        // addi' = NIl | ',' addi
        while (ptr < n && expr[ptr++] == ',') {
            ret.merge(parse_expr());   // merge means add
        }
        return ret;
    }

    // Word = Char | Char Word
    string trigger_word() {
        cout << "trigger_word " << ptr << endl;
        if (!isalpha(expr[ptr])) return {};
        string pref(1, expr[ptr++]);
        return pref + trigger_word();
    }
};

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        Parser parser(std::move(expression));
        auto ans = parser.parse_expr();
        vector<string> ansv(ans.begin(), ans.end());
        sort(ansv.begin(), ansv.end());
        return ansv;
    }
};

int main() {
    string expr {"{{a,z},a{b,c},{ab,z}}"};
    auto ans = Solution().braceExpansionII(expr);
    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, ", "));
    endl(cout);
    return 0;
}

