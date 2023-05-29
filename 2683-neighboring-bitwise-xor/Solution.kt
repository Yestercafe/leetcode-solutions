class Solution {
    fun doesValidArrayExist(derived: IntArray): Boolean {
        return derived.fold(0, fun (s, a) = s xor a) != 1
    }
}

