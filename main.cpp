#include <iostream>
#include <string>

using namespace std;

class EmpM
{
private:
    int id;
    string name;
    string email;
    
public:
    EmpM(int id = 0, string name = "", string email = "") : id(id), name(name), email(email) {}

    void setName(string n) { name = n; }
    void setEmail(string e) { email = e; }
    void setId(int i) { id = i; }

    string getName() { return name; }
    string getEmail() { return email; }
    int getId() { return id; }
};

class EmpV
{
public:
    void printEmployeeDetails(EmpM employee)
    {
        cout << "--- Employee Details ---" << endl;
        cout << "ID: " << employee.getId() << endl;
        cout << "Name: " << employee.getName() << endl;
        cout << "Email: " << employee.getEmail() << endl;
        cout << "------------------------" << endl;
    }
};

class EmpC
{
private:
    EmpM e;
    EmpV ev;

public: 
    EmpC(EmpM model, EmpV view) : e(model), ev(view) {}

    void setEmployeeName(string name) { e.setName(name); }
    void setEmployeeEmail(string email) { e.setEmail(email); }
    void setEmployeeId(int id) { e.setId(id); }

    string getEmployeeName() { return e.getName(); }
    string getEmployeeEmail() { return e.getEmail(); }
    int getEmployeeId() { return e.getId(); }

    void view()
    {
        ev.printEmployeeDetails(e);
    }
};

int main()
{
    EmpM model(1, "Alice", "alice@company.com");
    EmpV view;
    EmpC controller(model, view);
    
    controller.view();
    controller.setEmployeeName("Alice Smith");
    controller.setEmployeeEmail("asmith@company.com");
    
    cout << "\n>> Updating Employee Data...\n\n";
    controller.view();

    return 0;
}