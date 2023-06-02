type Substr struct {
    head int
    size int
}

func NewSubStr(head, size int) Substr {
    return Substr {
        head: head,
        size: size,
    }
}

func maxRepOpt1(text string) (ans int) {
    table := make([][]Substr, 26)
    for i := range table {
        table[i] = []Substr{}
    }

    head, cnt := -1, 0
    for i, b := range text {
        if head < 0 {
            head = i
            cnt = 1
        } else {
            if text[head] != byte(b) {
                idx := text[head] - 'a'
                table[idx] = append(table[idx], NewSubStr(head, cnt))
                head, cnt = i, 0
            }
            cnt++
        }
    }
    if head >= 0 {
        idx := text[head] - 'a'
        table[idx] = append(table[idx], NewSubStr(head, cnt))
    }

    for _, lst := range table {
        lenLst := len(lst)
        if lenLst == 0 {
            continue
        } else if lenLst == 1 {
            ans = max(ans, lst[0].size)
        } else if lenLst == 2 {
            ans = max(ans, lst[0].size + 1)
            ans = max(ans, lst[1].size + 1)
            if lst[0].head + lst[0].size + 1 == lst[1].head {
                ans = max(ans, lst[0].size + 1 + lst[1].size - 1)
            }
        } else {
            for i := range lst {
                if i + 1 < lenLst {
                    if lst[i].head + lst[i].size + 1 == lst[i + 1].head {
                        ans = max(ans, lst[i].size + 1 + lst[i + 1].size)
                    }
                }
                ans = max(ans, lst[i].size + 1)
            }
        }
    }

    return
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

