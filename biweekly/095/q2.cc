class DataStream {
public:
    DataStream(int value, int k) : value{value}, k{k}, c{0} {

    }
    
    bool consec(int num) {
        if (num == value) ++c;
        else c = 0;
        if (c >= k) return true;
        return false;
    }
    
    int value;
    int k;
    
    int c;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

