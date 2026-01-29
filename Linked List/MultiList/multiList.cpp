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
        int searchCourse(std::string course)
        {
            if (head == nullptr) return -1;
            int i = 0;
            CourseNode* curr = head;

            while (curr->cNext != nullptr && curr->course_no != course)
            {
                curr = curr->cNext;
                i++;
            }
            
            return (curr->course_no == course) ? i : -1; 
        }
        int searchStudent(std::string student, std::string course)
        {
            int t = searchCourse(course);
            if (t == -1)
            {
                std::cout << "Course not found\n";
                return -1;
            }

            CourseNode* currCourse = head;
            for (int i = 0; i < t; i++)
            {
                currCourse = currCourse->cNext;
            }
            
            if (currCourse->student_list ==  nullptr) return -1;

            StudentNode* currStudent = currCourse->student_list;

            int i = 0;
            while (currStudent->sNext != nullptr && currStudent->student_no != student)
            {
                currStudent = currStudent->sNext;
                i++;
            }
            
            return (currStudent->student_no == student) ? i : -1; 
            
        }
        void deleteCourse(std::string course) // !! Fix Delete course last node Deletion
        {
            int t = searchCourse(course);

            if (t == -1)
            {
                std::cout << "Course not found\n";
                return;
            }

            CourseNode* currCourse = head;
            if (head->cNext == nullptr)
            {
                StudentNode* currStudent = currCourse->student_list;
                while (currStudent != nullptr)
                {
                    StudentNode* temp = currStudent;
                    currStudent = currStudent->sNext;
                    delete temp;
                }
                head = nullptr;
                delete currCourse;
                return;
            }
            if (t == 0)
            {
                StudentNode* currStudent = currCourse->student_list;
                while (currStudent != nullptr)
                {
                    StudentNode* temp = currStudent;
                    currStudent = currStudent->sNext;
                    delete temp;
                }
                head = currCourse->cNext;
                delete currCourse;
                return;
            }

            CourseNode* prev = head;

            for (int i = 0; i < t - 1; i++)
            {
                currCourse = currCourse->cNext;
                prev = prev->cNext;
            }
            currCourse = currCourse->cNext;
            if (currCourse->cNext != nullptr)
            {
                StudentNode* currStudent = currCourse->student_list;
                while (currStudent != nullptr)
                {
                    StudentNode* temp = currStudent;
                    currStudent = currStudent->sNext;
                    delete temp;
                }
            }

            prev->cNext = currCourse->cNext;
            delete currCourse;
        }
        void deleteStudent(std::string student, std::string course)
        {
            int t = searchCourse(course);

            if (t == -1)
            {
                std::cout << "Course not found\n";
                return;
            }
            int u = searchStudent(student, course);

            if (u == -1)
            {
                std::cout << "Student not found\n";
                return;
            }
            CourseNode* currCourse = head;
            for (int i = 0; i < t; i++)
            {
                currCourse = currCourse->cNext;
            }
            StudentNode* currStudent = currCourse->student_list;
            if (u == 0)
            {
                currCourse->student_list = currStudent->sNext;
                delete currStudent;
                return;
            }
            StudentNode* prev = currCourse->student_list;
            for (int i = 0; i < u - 1; i++)
            {
                currStudent = currStudent->sNext;
                prev = prev->sNext;
            }
            currStudent = currStudent->sNext;
            prev->sNext = currStudent->sNext;
            delete currStudent;
        }
        void displayCourses()
        {
            CourseNode* curr = head;
            std::cout << "====List of Courses====\n";
            while (curr != nullptr)
            {
                std::cout << curr->course_no << std::endl;
                curr = curr->cNext; 
            }
            std::cout << "~~~~END OF LIST~~~~\n";
        }
        void display_all()
        {
            CourseNode* currCourse = head;
            std::cout << "====List of Courses and Students====\n";
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
            std::cout << "~~~~END OF LIST~~~~\n";
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
    std::cout << " 1  to Insert Course\n" << " 2  Insert Student to a Course\n" <<
                 " 3  Insert a Student to All Courses\n" << " 4  Search for a Course\n" <<
                 " 5  Search for a Student in A Course\n" << " 6  Search for a Student in All Courses\n" <<
                 " 7  Delete a Course\n" << " 8  Delete a Student in a Course\n" <<
                 " 9  Delete A Student in all Courses\n" << "10  Display list of Courses\n" <<
                 "11  Display Students of a Course\n" << "12  Display all\n" << "13  Exit\n\n";  
    // STARRED: Complete All Methods 
    while (true)
    {    
        std::cout << "Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Input Course No. to insert: ";
            std::getline(std::cin >> std::ws,  userInput);
            cml.addCourse(userInput);
            break;
        case 2:
            std::cout << "Input Student ID to insert: ";
            std::getline(std::cin >> std::ws,  userInput);
            std::cout << "Input Course No. to insert in: ";
            std::getline(std::cin >> std::ws,  userInput2);
            cml.addStudent(userInput, userInput2);
            break;
        case 4:
            std::cout << "Input Course No. to search: ";
            std::getline(std::cin >> std::ws, userInput);
            t = cml.searchCourse(userInput);
            if (t == -1) std::cout << "Course Not Found\n";
            else std::cout << "Course found at Index " << t << std::endl;
            break;
        case 5:
            std::cout << "Input Student ID to search: ";
            std::getline(std::cin >> std::ws, userInput);
            std::cout << "Input Course No. to search: ";
            std::getline(std::cin >> std::ws, userInput2);
            t = cml.searchStudent(userInput, userInput2);
            if (t == -1) std::cout << "Student Not Found\n";
            else std::cout << "Student found at Index " << t << std::endl;
            break;
        case 7:
            std::cout << "Input Course No. to Delete: ";
            std::getline(std::cin >> std::ws, userInput);
            cml.deleteCourse(userInput);
            break;
        case 8:
            std::cout << "Input Student ID to delete: ";
            std::getline(std::cin >> std::ws, userInput);
            std::cout << "Input Course No. to delete: ";
            std::getline(std::cin >> std::ws, userInput2);
            cml.deleteStudent(userInput, userInput2);
            break;
        case 10:
            cml.displayCourses();
            break;
        case 12:
            cml.display_all();
            break;
        case 13:
            return 0;
        default:
            std::cout << "Invalid Input" << std::endl;
            break;
        }
    }
    return 0;
}