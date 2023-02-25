class MyLinkedList {
public:
    struct node
    {
       int data;
       struct node *next;
       node(int val)
       {
           data = val;
           next = NULL;
       }
    };
    node *head;
    int size;
    MyLinkedList() 
    {
        size = 0;
        head = NULL;
    }
    
    int get(int index) 
    {   
        if(index<0 or index>=size)return -1;
        node *temp = head;
        while(temp and index)
        {
            temp = temp->next;
            index--;
        }
        return temp->data;
    }
    
    void addAtHead(int val) 
    {
        node *newnode = new node(val);
        newnode->next = head;
        head = newnode;
        size+=1;
    }
    
    void addAtTail(int val) 
    {   
        if(head==NULL)
        {
            head = new node(val);
            size+=1;
            return;
        }
        node *temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = new node(val);
        temp = temp->next;
        size+=1;
        return;
    }
    
    void addAtIndex(int index, int val)
    {
        if(index>size or index<0)return;
        if(index==0)
        {
            node *newnode = new node(val);
            newnode->next = head;
            head = newnode;
            size+=1;
            return;
        }
        node *temp = head,*prev = temp;
        while(index and temp)
        {
            prev = temp;
            temp = temp->next;
            index--;
        }
        prev->next = new node(val);
        prev = prev->next;
        prev->next = temp;
        size+=1;
        return;
    }
    
    void deleteAtIndex(int index) 
    {   
        if(index<0 or index>=size)return;
        if(index==0)
        {   
            head = head->next;
            size-=1;
            return;
        }
        node *temp = head,*prev=NULL;
        while(index and temp)
        {
            prev = temp;
            temp = temp->next;
            index--;
        }
        prev->next = temp->next;
        delete temp;
        size -= 1;
        return;
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