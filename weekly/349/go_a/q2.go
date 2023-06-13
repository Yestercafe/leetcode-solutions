func smallestString(s string) string {
    rs := []rune(s)
    pos := 0
    n := len(rs)
    for pos < n {
        if rs[pos] != 'a' {
            break;
        }
        pos++
    }
    if pos == n {
        rs[n - 1] = 'z'
        return string(rs)
    }

    for pos < n && rs[pos] != 'a' {
        rs[pos]--
        pos++
    }

    return string(rs)
}

