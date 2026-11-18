
#include <iostream>
#include <memory>
using namespace std;

// Resource class
class Resource
{
public:
    Resource()
    {
        cout << "Resource acquired" << endl;
    }

    ~Resource()
    {
        cout << "Resource released" << endl;
    }

    void use()
    {
        cout << "Resource is being used" << endl;
    }
};

// Manual smart pointer using RAII
class MySmartPointer
{
private:
    Resource* ptr;

public:
    MySmartPointer(Resource* p) : ptr(p) {}

    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual smart pointer destroyed" << endl;
    }

    Resource* operator->()
    {
        return ptr;
    }

    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;
};

int main()
{
    int choice;

    cout << "Choose a smart pointer example to run:\n";
    cout << "1. Manual RAII Smart Pointer\n";
    cout << "2. unique_ptr\n";
    cout << "3. shared_ptr\n";
    cout << "4. Run all examples\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice < 1 || choice > 4)
    {
        cout << "Invalid choice." << endl;
        return 1;
    }

    if (choice == 1 || choice == 4)
    {
        cout << "\n----- Manual RAII Smart Pointer -----" << endl;
        {
            MySmartPointer smartPtr(new Resource());
            smartPtr->use();
        }
    }

    if (choice == 2 || choice == 4)
    {
        cout << "\n----- unique_ptr -----" << endl;
        {
            unique_ptr<Resource> uniquePtr = make_unique<Resource>();
            uniquePtr->use();
        }
    }

    if (choice == 3 || choice == 4)
    {
        cout << "\n----- shared_ptr -----" << endl;
        {
            shared_ptr<Resource> sharedPtr1 = make_shared<Resource>();
            shared_ptr<Resource> sharedPtr2 = sharedPtr1;

            sharedPtr1->use();
            cout << "Shared Pointer Count: "
                 << sharedPtr1.use_count() << endl;
        }
    }

    cout << "\nProgram completed successfully." << endl;
    return 0;
}