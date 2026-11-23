#include <iostream>
#include <string>
using namespace std;

// User-defined exception class
class BankException
{
public:
    string message;

    BankException(string msg)
    {
        message = msg;
    }
};

// Derived exception class
class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException()
        : BankException("Error: Insufficient balance for withdrawal.")
    {
    }
};

// Derived exception class
class InvalidAmountException : public BankException
{
public:
    InvalidAmountException()
        : BankException("Error: Amount must be greater than zero.")
    {
    }
};

// Bank Account class
class BankAccount
{
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b)
    {
        name = n;
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        if (amount > balance)
            throw InsufficientFundsException();

        balance -= amount;
    }

    void display()
    {
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    BankAccount account("Arun", 5000);

    cout << "Initial Account Details:" << endl;
    account.display();

    try
    {
        cout << "\nDepositing Rs. 1000..." << endl;
        account.deposit(1000);

        cout << "Withdrawing Rs. 2000..." << endl;
        account.withdraw(2000);

        cout << "Withdrawing Rs. 10000..." << endl;
        account.withdraw(10000);
    }

    catch (InsufficientFundsException e)
    {
        cout << e.message << endl;
    }

    catch (InvalidAmountException e)
    {
        cout << e.message << endl;
    }

    catch (BankException e)
    {
        cout << e.message << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    account.display();

    return 0;
}
