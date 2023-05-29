func doesValidArrayExist(derived []int) bool {
    xor_sum := 0
    for i := 0; i < len(derived); i++ {
        xor_sum ^= derived[i]
    }
    return xor_sum != 1
}

