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


int main()
{
    SinglyLinkedList<int> sll;
    std::cout << sll.getSize() << std::endl;
    sll.insert(1); sll.insert(3); sll.insert(5);
    std::cout << sll.getSize() << std::endl;
}