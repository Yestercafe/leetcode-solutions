// 大概是对的，写得太乱了不好调
class Allocator {
public:
    Allocator(int n) {
        this->capacity = n;
        mem.assign(n, {});
        size_avail.assign(n + 1, {});
        size_avail[n].insert(0);
    }
    
    int allocate(int size, int mID) {
        for (int ava = size; ava <= capacity; ++ava) {
            if (size_avail[ava].empty()) continue;
            int addr = *size_avail[ava].begin();
            cout << ava << " " << addr << endl;
            size_avail[ava].erase(size_avail[ava].begin());
            if (ava - size > 0) {
                size_avail[ava - size].insert(addr + size);
            }
            mid_addr[mID].push_back(make_pair(addr, size));
            return addr;
        }
        return -1;
    }
    
    int free(int mID) {
        auto fnd = mid_addr.find(mID);
        if (fnd == mid_addr.end()) return 0;
        int ret = 0;
        for (auto& f : fnd->second) {
            int addr = f.first;
            int size = f.second;
            ret += size;
            for (int i = 1; i <= addr; ++i) {
                if (mid_addr.find(addr - i) != mid_addr.end()) break;
                auto fnd = size_avail[i].find(addr - i);
                if (fnd == size_avail[i].end()) continue;
                addr = addr - i;
                size += i;
                size_avail[i].erase(fnd);
                break;
            }
            for (int i = 1; addr + size + i - 1 <= capacity; ++i) {
                auto fnd = size_avail[i].find(addr + size);
                if (fnd == size_avail[i].end()) continue;
                size += i;
                size_avail[i].erase(fnd);
                break;
            }
            size_avail[size].insert(addr);
        }
        return ret;
    }

private:
    vector<int> mem;
    unordered_map<int, vector<pair<int, int>>> mid_addr;
    vector<set<int>> size_avail;
    int capacity;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
