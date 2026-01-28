#include <iostream>

class CourseMultiList
{
    private:
        struct StudentNode
        {
            std::string student_no;
            StudentNode* sNext;
        };
        
        struct CourseNode
        {
            std::string course_no;
            StudentNode* student_list;
            CourseNode* cNext;

        };
        
        CourseNode* head;
    public:
        CourseMultiList() {head = nullptr;}

        void addCourse(std::string course)
        {
            CourseNode* temp = new CourseNode(); 
            temp->course_no = course;
            temp->student_list = nullptr;
            temp->cNext = nullptr;
            if (head == nullptr)
            {
                head = temp;
            }
            else
            {
                CourseNode* curr = head;
                while (curr->cNext != nullptr)
                {
                    if (curr->course_no == course)
                    {
                        delete temp;
                        std::cout << "Course already exists" << std::endl;
                        return;
                    }
                    curr = curr->cNext;
                }
                if (curr->course_no == course)
                {
                    delete temp;
                    std::cout << "Course already exists" << std::endl;
                    return;
                }
                curr->cNext = temp;
            }
        }
        void addStudent(std::string student, std::string course)
        {
            CourseNode* currCourse = head;
            if (currCourse == nullptr)
            {
                std::cout << "Course Not Found" << std::endl;
                return;
            }
            while (currCourse != nullptr && currCourse->course_no != course)
            {
                currCourse = currCourse->cNext;
            }
            if (currCourse == nullptr || currCourse->course_no != course)
            {
                std::cout << "Course Not Found";
                return;
            }
            StudentNode* temp = new StudentNode();
            temp->student_no = student;
            temp->sNext = nullptr;
            if(currCourse->student_list == nullptr)
            {
                currCourse->student_list = temp;
            }
            else
            {
                StudentNode* currStudent = currCourse->student_list;
                while (currStudent->sNext != nullptr)
                {
                    if (currStudent->student_no == student)
                    {
                        delete temp;
                        std::cout << "Student already exists" << std::endl;
                        return;
                    }
                    currStudent = currStudent->sNext;
                }
                if (currStudent->student_no == student)
                {
                    delete temp;
                    std::cout << "Student already exists" << std::endl;
                    return;
                }
                currStudent->sNext = temp;
            }
            
            
        }
        void display_all()
        {
            CourseNode* currCourse = head;
            while (currCourse != nullptr)
            {
                std::cout << "Course: " << currCourse->course_no << std::endl;
                StudentNode* currStudent = currCourse->student_list;

                while (currStudent != nullptr)
                {
                    std::cout << "    Student: " << currStudent->student_no << std::endl;
                    currStudent = currStudent->sNext;
                }
                currCourse = currCourse->cNext;
                
            }
            
        }

        ~CourseMultiList()
        {
            CourseNode* currCourse = head;
            while(currCourse != nullptr)
            {
                CourseNode* tempCourse = currCourse;
                StudentNode* currStudent = tempCourse->student_list;
                while (currStudent != nullptr)
                {
                    StudentNode* tempStudent = currStudent;
                    currStudent = currStudent->sNext;
                    delete tempStudent;
                }
                
                currCourse = currCourse->cNext;
                delete tempCourse;
            }
        }
};

int main()
{
    CourseMultiList cml;

    int choice;
    std::string userInput;
    std::string userInput2;
    int t;
    std::cout << "Choose any one of the following: " << std::endl;
    std::cout << "1 to Insert Course\n" << "2 Insert Student\n" <<
                 "3 display\n" << "4 End\n" << std::endl;

    while (true)
    {    
        std::cout << "Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Input Course to insert: ";
            std::getline(std::cin >> std::ws,  userInput);
            cml.addCourse(userInput);
            break;
        case 2:
            std::cout << "Input Student to insert: ";
            std::getline(std::cin >> std::ws,  userInput);
            std::cout << "Input Course to insert in: ";
            std::getline(std::cin >> std::ws,  userInput2);
            cml.addStudent(userInput, userInput2);
            break;
        case 3:
            cml.display_all();
            break;
        case 4:
            return 0;
        default:
            std::cout << "Invalid Input" << std::endl;
            break;
        }
    }
    return 0;
}
