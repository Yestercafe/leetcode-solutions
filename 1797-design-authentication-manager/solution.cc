class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) : lifetime{timeToLive} {}
    
    void generate(string tokenId, int currentTime) {
        doClean(currentTime);
        q.push_back({tokenId, currentTime});
    }
    
    void renew(string tokenId, int currentTime) {
        doClean(currentTime);
        auto it = q.begin();
        for (; it != q.end(); ++it) {
            if (it->first == tokenId) {
                q.erase(it);
                break;
            }
        }
        if (it != q.end()) q.push_back({tokenId, currentTime});
    }
    
    int countUnexpiredTokens(int currentTime) {
        doClean(currentTime);
        return q.size();
    }

private:
    int lifetime;
    string token;
    list<pair<string, int>> q;

    void doClean(int currentTime) {
        auto it = q.begin();
        while (it != q.end()) {
            if (it->second + lifetime > currentTime) break;
            auto erased = it++;
            q.erase(erased);
        }
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
