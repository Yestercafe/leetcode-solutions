class Allocator {
public:
    Allocator(int n) : capacity{n} {
        m.assign(n, {});
    }
    
    int allocate(int size, int mid) {
        int addr = 0, len, i;
        for (i = 0, len = 0; i < capacity && len < size; ++i) {
            if (m[i] != 0) {
                addr = i + 1;
                len = 0;
            } else {
                ++len;
            }
        }
        if (len >= size) {
            for (int i = 0; i < size; ++i) {
                m[addr + i] = mid;
            }
        } else return -1;
        return addr;
    }
    
    int free(int mid) {
        int size = 0;
        for (int i = 0; i < capacity; ++i) {
            if (m[i] == mid) {
                m[i] = 0;
                ++size;
            }
        }
        return size;
    }

    vector<int> m;
    int capacity;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

