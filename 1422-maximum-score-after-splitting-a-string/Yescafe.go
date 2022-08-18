func maxScore(s string) int {
    ss := []byte(s)
    var max int
    score := bytes.Count(ss, []byte("1"))
    for _, c := range ss[:len(ss)-1] {
        switch c {
        case '1':
            score--
        case '0':
            score++
        }
        if score > max {
            max = score
        }
    }
    return max
}

