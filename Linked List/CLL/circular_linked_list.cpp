#include <iostream>
template <typename T>

class CircularLinkedList
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
        CircularLinkedList() {};

        int getSize() {return size;}

        void insert(T data)
        {
            Node* temp = new Node();
            temp->element = data;
            if (size == 0)
            {
                head = temp;
                head->next = head;
            }
            else
            {
                Node* curr = head;
                while (curr->next != head)
                {
                    curr = curr->next;
                }
                curr->next = temp;
                temp->next = head;
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
            while (curr->next != head)
            {
                std::cout << curr->element << std::endl;
                curr = curr->next;
            }
            std::cout << curr->element << std::endl;
        }
        int search(T data)
        {
            if (size == 0) return -1;
            if (size == 1)
            {
                return (head->element == data) ? 0 : -1; 
            }
            else
            {
                Node* curr = head;
                int i = 0;
                while (curr->next != head)
                {
                    if (curr->element == data) return i;
                    curr = curr->next;
                    i++;
                }
                if (curr->element == data) return i;
            }
            return -1;
        }
        void del(T data)
        {
            if (size == 0) return;

            int targetIndex = search(data);
            if (targetIndex == -1) return;

            if (size == 1)
            {
                delete head;
                head = nullptr;
                size--;
                return;
            }
            if (targetIndex == 0)
            {
                Node* temp = head;
                head = head->next;
                
                Node* curr = head;
                while (curr->next != temp)
                {
                    curr = curr->next;
                }
                curr->next = head;
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

        ~CircularLinkedList()
        {
            if (head == nullptr) return;

            Node* current = head->next;
            while (current != head)
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            delete head;
        }
};


int main()
{

    CircularLinkedList<int> cll;

    int choice;
    int userInput;
    int t;
    std::cout << "Choose any one of the following: " << std::endl;
    std::cout << "1 to Insert \n" << "2 to Display \n" << "3 to Search\n" <<
                 "4 to Delete\n" << "5 to Exit\n";

    while (true)
    {    
        std::cout << "Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Input integer to insert: ";
            std::cin >> userInput;
            cll.insert(userInput);
            break;
        case 2:
            std::cout << "Size: " << cll.getSize() << std::endl;
            cll.display();
            break;
        case 3:
            std::cout << "Input integer to search: ";
            std::cin >> userInput;
            t = cll.search(userInput);
            if (t != -1){
                std::cout << "Found at index: " << t << std::endl;
            }
            else {std::cout << "Element Not Found" << std::endl;}
            break;
        case 4:
            std::cout << "Input integer to delete: ";
            std::cin >> userInput;
            cll.del(userInput);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid Input" << std::endl;
        }
    }

    return 0;
}