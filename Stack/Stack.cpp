#include <iostream>

template <typename T>
class Stack
{
    private:
        struct Node
        {
            T element;
            Node* next;
        };
        Node* top;

    public:
        Stack() {top = nullptr;}

        void push(T data)
        {
            Node* temp = new Node();
            temp->element = data;
            if (top == nullptr)
            {
                top = temp;
                top->next = nullptr;
            }
            else
            {
                temp->next = top;
                top = temp;
            }
        }
        T pop()
        {
            if (top == nullptr)
            {
                std::cout << "Stack Underflow" << std::endl;
            }
            Node* temp = top;
            top = top->next;
            T temp2 = temp->element;
            delete temp;
            return temp2;
        }

        ~Stack()
        {
            Node* current = top;
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
    Stack<int> container;

    int choice;
    int userInput;
    int t;
    std::cout << "Choose any one of the following: " << std::endl;
    std::cout << "1 to push\n" << "2 to pop\n" << "3 to exit" << std::endl;
    
    while (true)
    {    
        std::cout << "Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Input integer to insert: ";
            std::cin >> userInput;
            container.push(userInput);
            break;
        case 2:
            t = container.pop();
            std::cout << t << std::endl;
            break;
        case 3:
            return 0;
        default:
            std::cout << "Invalid Input" << std::endl;
            break;
        }
    }
    return 0;
}