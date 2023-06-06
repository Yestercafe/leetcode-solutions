type trie struct {
    nxt map[int]*trie
    cnt int
}

func newTrie() *trie {
    return &trie {
        nxt: map[int]*trie{},
        cnt: 0,
    }
}

func equalPairs(grid [][]int) (ans int) {
    t := newTrie()
    for i := range grid {
        curr := t
        for _, v := range grid[i] {
            if _, exists := curr.nxt[v]; !exists {
                curr.nxt[v] = newTrie()
            }
            curr = curr.nxt[v]
        }
        curr.cnt++
    }

    n := len(grid)
    for j := 0; j < n; j++ {
        curr := t
        for i := 0; i < n; i++ {
            if _, exists := curr.nxt[grid[i][j]]; !exists {
                break
            }
            curr = curr.nxt[grid[i][j]]
        }
        ans += curr.cnt
    }

    return ans
}

