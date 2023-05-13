class FrequencyTracker {
public:
    FrequencyTracker() {}
    
    void add(int number) {
        auto c = ++cnts[number];
        --freq[c - 1];
        ++freq[c];
    }
    
    void deleteOne(int number) {
        auto c = cnts[number];
        if (c == 0) return;
        --freq[c];
        if (c != 1) ++freq[c - 1];
        --cnts[number];
    }
    
    bool hasFrequency(int frequency) {
        return freq[frequency];
    }

private:
    map<int, int> cnts;
    map<int, int> freq;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */

