#include<iostream>
using namespace std;
class student
{
    private:
    int rollNo;
    string name;
    public:
    student(int r,string n)
    {
        rollNo=r;
        name=n;
        cout<<"student object created"<<endl;
    }
    void display()
    {
        cout<<"Roll Number:"<<rollNo<<endl;
        cout<<"Name:"<<name<<endl;
    }
    ~ student()
    {
        cout<<"student object destroyed"<<endl;
    }
};
int main()
{
    student s1(101,"Arun");
    s1.display();
    return 0;
}

