type OrderedStream struct {
    stream []string
    ptr int
    n int
}


func Constructor(n int) OrderedStream {
    os := OrderedStream{}
    os.stream = make([]string, n)
    os.ptr, os.n = 0, n
    return os
}


func (this *OrderedStream) Insert(idKey int, value string) []string {
    idKey--
    this.stream[idKey] = value
    endpoint := this.ptr
    for endpoint < this.n && this.stream[endpoint] != "" {
        endpoint++
    }
    defer func() {
        this.ptr = endpoint
    }()
    return this.stream[this.ptr:endpoint]
}


/**
 * Your OrderedStream object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Insert(idKey,value);
 */

