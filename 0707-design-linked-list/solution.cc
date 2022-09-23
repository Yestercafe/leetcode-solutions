class MyLinkedList {
    struct Node {
        int n;
        Node* next;
        Node(int n = 0, Node* next = nullptr) : n(n), next(next) {}
    };
    
    Node* h;
    Node* tail;
    int len;
    
public:
    MyLinkedList() : h(new Node()), tail(h), len(0) {
    }
    
    int get(int index) {
        // cout << "get" << endl;
        if (index < 0 || index >= len) {
            return -1;
        }
        
        auto itr = h->next;
        while (index--) {
            itr = itr->next;
        }
        // output();
        return itr->n;
    }
    
    void addAtHead(int val) {
        // cout << "addAtHead" << endl;
        auto new_head = new Node(val, h->next);
        h->next = new_head;
        if (tail == h) tail = new_head;
        // output();
        ++len;
    }
    
    void addAtTail(int val) {
        // cout << "addAtTail" << endl;
        tail->next = new Node(val);
        tail = tail->next;
        ++len;
        // output();
    }
    
    void addAtIndex(int index, int val) {
        // cout << "addAtIndex" << endl;
        if (index > len) {
            return ;
        } else if (index == len) {
            addAtTail(val);
            return ;
        } else if (index < 0) {
            addAtHead(val);
            return ;
        }
        
        auto itr = h;
        while (index--) {
            itr = itr->next;
        }
        
        auto new_one = new Node(val, itr->next);
        itr->next = new_one;
        ++len;
        // output();
    }
    
    void deleteAtIndex(int index) {
        // cout << "deleteAtIndex" << endl;
        if (index < 0 || index >= len) {
            return ;
        }
        
        auto itr = h;
        while (index--) {
            itr = itr->next;
        }
        auto temp = itr->next;
        if (temp == tail) tail = itr;
        itr->next = temp->next;
        delete temp;
        --len;
        // output();
    }
    
    void output() {
        auto i = h->next;
        while (i != nullptr) {
            cout << i->n << "->";
            i = i->next;
        }
        cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

