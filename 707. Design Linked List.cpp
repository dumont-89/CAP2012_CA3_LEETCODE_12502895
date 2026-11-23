class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;

        Node(int x){
            val = x;
            next = nullptr;
        }
    };

    Node* head;
    int sz;
public:
    MyLinkedList() {
        head = nullptr;
        sz = 0;
    }

    int get(int index){
        if (index < 0 || index >= sz)
            return -1;

        Node* curr = head;
        for (int i = 0; i < index; i++)
            curr = curr->next;

        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        sz++;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);

        if (head == nullptr){
            head = node;
        } else {
            Node* curr = head;
            while (curr->next)
                curr= curr->next;

            curr->next = node;
        }
        sz++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > sz)
            return;

        if(index == 0){
            addAtHead(val);
            return;
        }

        Node*curr = head;
        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        Node* node = new Node(val);
        node->next = curr->next;
        curr->next = node;

        sz++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz)
            return;
        
        if (index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            sz--;
            return;
        }

        Node*curr = head;
        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        sz--;
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