type MyCircularDeque struct {
    storage []int
    front, rear int
    size, cap int
}


func Constructor(k int) MyCircularDeque {
    mcd := MyCircularDeque{}
    mcd.storage = make([]int, k)
    mcd.front, mcd.rear, mcd.size = 0, 0, 0
    mcd.cap = k
    return mcd
}


func (this *MyCircularDeque) InsertFront(value int) bool {
    if this.IsFull() {
        return false
    }
    this.front = (this.front + this.cap - 1) % this.cap
    this.storage[this.front] = value
    this.size++
    return true
}


func (this *MyCircularDeque) InsertLast(value int) bool {
    if this.IsFull() {
        return false
    }
    this.storage[this.rear] = value
    this.rear = (this.rear + 1) % this.cap
    this.size++
    return true
}


func (this *MyCircularDeque) DeleteFront() bool {
    if this.IsEmpty() {
        return false
    }
    this.front = (this.front + 1) % this.cap
    this.size--
    return true
}


func (this *MyCircularDeque) DeleteLast() bool {
    if this.IsEmpty() {
        return false
    }
    this.rear = (this.rear + this.cap - 1) % this.cap
    this.size--
    return true
}


func (this *MyCircularDeque) GetFront() int {
    if this.IsEmpty() {
        return -1
    }
    return this.storage[this.front]
}


func (this *MyCircularDeque) GetRear() int {
    if this.IsEmpty() {
        return -1
    }
    return this.storage[(this.rear + this.cap - 1) % this.cap]
}


func (this *MyCircularDeque) IsEmpty() bool {
    return this.size == 0
}


func (this *MyCircularDeque) IsFull() bool {
    return this.size == this.cap
}


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.InsertFront(value);
 * param_2 := obj.InsertLast(value);
 * param_3 := obj.DeleteFront();
 * param_4 := obj.DeleteLast();
 * param_5 := obj.GetFront();
 * param_6 := obj.GetRear();
 * param_7 := obj.IsEmpty();
 * param_8 := obj.IsFull();
 */

