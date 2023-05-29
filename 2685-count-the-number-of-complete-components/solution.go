func countCompleteComponents(n int, edges [][]int) (ans int) {
    g := make([][]int, n)
    vis := make([]bool, n)
    for _, e := range edges {
        g[e[0]] = append(g[e[0]], e[1])
        g[e[1]] = append(g[e[1]], e[0])
    }

    bfs := func (i int) {
        q := []int{}
        q = append(q, i)
        vis[i] = true
        cc := []int{}
        cc = append(cc, i)

        for ; len(q) > 0; {
            f := q[0]
            q = q[1:]
            for _, nxt := range g[f] {
                if vis[nxt] { continue }
                vis[nxt] = true
                q = append(q, nxt)
                cc = append(cc, nxt)
            }
        }

        for _, v := range cc {
            if len(g[v]) != len(cc) - 1 {
                return
            }
        }
        
        ans++
    }

    for i, v := range vis {
        if v { continue }
        bfs(i)
    }

    return
}

