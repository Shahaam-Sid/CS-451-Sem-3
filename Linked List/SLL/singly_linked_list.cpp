#include <iostream>
// Struct Method
struct LLNode
{
    int data = 0;
    LLNode* next = nullptr;
};

LLNode* list = nullptr;

void insert(int value)
{
    LLNode* temp;
    // allocating Memory
    temp = (LLNode*) malloc(sizeof(LLNode));

    temp->data = value;
    temp->next = nullptr;
    if (list == nullptr)
    {
        list = temp;
    } else {
        LLNode* curr = list;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void display(LLNode* lln)
{
    if (lln->next == nullptr)
    {
        std::cout << lln->data << std::endl;
        return;
    }

    while (lln->next != nullptr)
    {
        std::cout << lln->data << std::endl;
        lln = lln->next;
    }
    std::cout << lln->data << std::endl;
}
int search(int i, LLNode* lln)
{
    int index = 0;
    while (lln->next != nullptr)
    {
        if (lln->data == i)
        {
            return index;
        }
        index++;
        lln = lln->next;
    }
    if (lln->data == i)
    {
        return index;
    }
    else 
    {
        std::cout << "Element Not Found";
    }
    return -1;

}

int main()
{
    int choice;
    int userInput;
    int t;
    std::cout << "Choose any one of the following: " << std::endl;
    std::cout << "1 to Insert \n" << "2 to Display \n" << "3 to Search\n" << "4 to Delete\n" << "5 to Exit\n";

    while (true)
    {    
        std::cout << "Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Input integer to insert: ";
            std::cin >> userInput;
            insert(userInput);
            break;
        case 2:
            display(list);
            break;
        case 3:
            std::cout << "Input integer to search: ";
            std::cin >> userInput;
            t = search(userInput, list);
            if (t != -1){
                std::cout << t << std::endl;
            }
            break;
        case 4:
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid Input";
        }
    }
}