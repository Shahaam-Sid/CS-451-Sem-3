#include <iostream>
template <typename T>
// OO Method

class SinglyLinkedList
{
    private:
        struct Node
        {
            T element;
            Node* next;
        };
        Node* head;
        int size = 0;
    public:
        SinglyLinkedList() {}

        int getSize() {return size;}

        void insert(T data)
        {
            Node* temp = new Node();
            temp->element = data;
            if (size == 0)
            {
                head = temp;
                head->next = nullptr;
            }
            else
            {
                Node* curr = head;
                while (curr->next != nullptr)
                {
                    curr = curr->next;
                }
                curr->next = temp;
            }
            size++;
        }
        void display()
        {
            if (size == 0)
            {
                std::cout << "No Element Found" << std::endl;
                return;
            }
            Node* curr = head;
            while (curr->next != nullptr)
            {
                std::cout << curr->element << std::endl;
                curr = curr->next;
            }
            std::cout << curr->element << std::endl;        
        }
        int search(T data)
        {
            if (size == 0) {return -1;}
            if (size == 1)
            {
                return (head->element == data) ? 0 : -1;
            }
            else
            {
                Node* curr = head;
                int i = 0;
                while (curr->next != nullptr)
                {
                    if (curr->element == data) {return i;}
                    curr = curr->next;
                    i++;
                }
                if (curr->element == data) {return i;}    
            }
            return -1;
        }
        void del(T data)
        {
            if (size == 0) {return;}
            
            int targetIndex = search(data);
            if (targetIndex == -1) {return;}
            if (targetIndex == 0)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
                size--;
                return;
            }
            
            Node* curr = head;
            for (int i = 0; i < targetIndex - 1; i++)
            {
                curr = curr->next;
            }
            
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            size--;
        }

        ~SinglyLinkedList()
        {
            Node* current = head;
            while (current != nullptr)
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }   
        } 
};