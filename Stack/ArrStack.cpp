#include <iostream>

template <typename T>
class ArrayStack
{
    public:
        static const int CAPACITY = 1000;

    private:
        T data[CAPACITY];
        int t = 0;

    public:
        ArrayStack() {}
    
        void push(T element)
        {
            if (t == CAPACITY)
            {
                std::cout << "Stack Overflow\n";
                return;
            }
            data[t] = element;
            t++;
        }
        T pop()
        {
            if (t == 0)
            {
                std::cout << "Stack Underflow\n";
                return T();
            }
            t--;
            T temp = data[t];
            return temp;
        }
};

int main()
{
    ArrayStack<int> container;

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