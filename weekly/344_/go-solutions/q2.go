type FrequencyTracker struct {
    freq map[int]int
    cnt map[int]int
}


func Constructor() FrequencyTracker {
    return FrequencyTracker {
        freq: map[int]int{},
        cnt: map[int]int{},
    }
}


func (this *FrequencyTracker) Add(number int)  {
    if this.cnt[number] > 0 {
        this.freq[this.cnt[number]]--
    }
    this.cnt[number]++
    this.freq[this.cnt[number]]++
}


func (this *FrequencyTracker) DeleteOne(number int)  {
    if this.cnt[number] == 0 {
        return
    }
    this.freq[this.cnt[number]]--
    this.cnt[number]--
    if this.cnt[number] > 0 {
        this.freq[this.cnt[number]]++
    }
}


func (this *FrequencyTracker) HasFrequency(frequency int) bool {
    return this.freq[frequency] > 0
}


/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(number);
 * obj.DeleteOne(number);
 * param_3 := obj.HasFrequency(frequency);
 */

