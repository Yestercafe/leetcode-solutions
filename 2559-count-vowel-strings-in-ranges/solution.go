func vowelStrings(words []string, queries [][]int) (ans []int) {
    n := len(words)
    pref := make([]int, n + 1)
    ans = make([]int, len(queries))

    for i, w := range words {
        pref[i + 1] = pref[i]
        if isVowel([]rune(w)[0]) && isVowel([]rune(w)[len(w) - 1]) {
            pref[i + 1]++
        }
    }

    for i, q := range queries {
        l, r := q[0], q[1]
        ans[i] = pref[r + 1] - pref[l]
    }
    
    return
}

func isVowel(c rune) bool {
    if c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' {
        return true
    } else {
        return false
    }
}

