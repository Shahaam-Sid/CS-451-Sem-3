#include <iostream>
template <typename T>

class DoublyLinkedList
{
    private:
        struct Node
        {
            Node* prev;
            T element;
            Node* next;
        };
        Node* head;
        int size = 0;

    public:
        DoublyLinkedList() {}

        int getSize() {return size;}

        void insert(T data)
        {
            Node* temp = new Node();
            temp->element = data;
            if (size == 0)
            {
                head = temp;
                head->prev = nullptr;
                head->prev = nullptr;
            }
            else
            {
                Node* curr = head;
                while (curr->next != nullptr)
                {
                    curr = curr->next;
                }
                curr->next = temp;
                temp->prev = curr;
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

        ~DoublyLinkedList()
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
    DoublyLinkedList<int> dll;

    dll.insert(10); dll.insert(20); dll.insert(30);
}