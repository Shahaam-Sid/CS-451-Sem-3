#include <iostream>

// OO Method
template <typename T>
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
        void insertSorted(T data)
        {
            Node* temp = new Node();
            temp->element = data;
            if (size == 0)
            {
                head = temp;
                head->next = nullptr;
            }
            else if (head->element >= data)
            {   
                temp->next = head;
                head = temp;
            }
            else
            {
                Node* curr = head;
                Node* frwd = head->next;
                while (frwd != nullptr && frwd->element < data)
                {
                    curr = curr->next;
                    frwd = frwd->next;
                }
                curr->next = temp;
                temp->next = frwd;

            }
            size++;
        }
        void insertUnique(T data)
        {
            int index = search(data);
            if (index != -1)
            {
                std::cout << "Value exists at index " << index << std::endl;
                return;
            }

            insert(data);
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
        int* searchMultiple(T data)
        {
            if (size == 0) {return nullptr;}

            int* indexes = new int[size];
            Node* curr = head;

            int index = 0;
            while (curr->next != nullptr)
            {
                if (curr->element == data)
                {
                    indexes[index] = index;
                }
                else
                {
                    indexes[index] = -1;
                }
                curr = curr->next;
                index++;

            }
            if (curr->element == data)
            {
                indexes[index] = index;
            }
            else
            {
                indexes[index] = -1;
            }
            
            return indexes;
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





int main()
{

    SinglyLinkedList<int> sll;

    int choice;
    int userInput;
    int t;
    std::cout << "Choose any one of the following: " << std::endl;
    std::cout << "1 to Insert\n" << "2 to Insert Unique\n" <<
                 "3 to Insert with Sort\n" << "4 to Display\n" <<
                 "5 to Search\n" << "6 to Search Multiple Occurences\n" <<
                 "7 to Delete\n" << "8 to Exit\n";

    while (true)
    {    
        std::cout << "Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Input integer to insert: ";
            std::cin >> userInput;
            sll.insert(userInput);
            break;
        case 2:
            std::cout << "Input integer to insert: ";
            std::cin >> userInput;
            sll.insertUnique(userInput);
            break;
        case 3:
            std::cout << "Input integer to insert: ";
            std::cin >> userInput;
            sll.insertSorted(userInput);
            break;
        case 4:
            std::cout << "Size: " << sll.getSize() << std::endl;
            sll.display();
            break;
        case 5:
            std::cout << "Input integer to search: ";
            std::cin >> userInput;
            t = sll.search(userInput);
            if (t != -1){
                std::cout << "Found at index: " << t << std::endl;
            }
            else {std::cout << "Element Not Found" << std::endl;}
            break;
        case 6:
        {
            std::cout << "Input integer to search: ";
            std::cin >> userInput;
            int* indexes = sll.searchMultiple(userInput);
            std::cout << "Indexes: ";
            for (int i = 0; i < sll.getSize(); i++)
            {
                if (indexes[i] != -1) {std::cout << indexes[i] << " ";}
            }
            std::cout << std::endl;
            delete[] indexes;
            
            break;
        }
        case 7:
            std::cout << "Input integer to delete: ";
            std::cin >> userInput;
            sll.del(userInput);
            break;
        case 8:
            return 0;
        default:
            std::cout << "Invalid Input" << std::endl;
            break;
        }
    }
    return 0;
}