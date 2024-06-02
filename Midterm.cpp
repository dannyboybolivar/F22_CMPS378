#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, double initialBalance) : name(name), balance(initialBalance) {
        srand(time(0));
        accountNumber = rand() % 100000;  // Generate a random account number
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << "\n"
             << "Name: " << name << "\n"
             << "Balance: $" << balance << "\n";
    }
};

class BankSystem {
private:
    vector<BankAccount> accounts;

    BankAccount* findAccount(int accountNumber) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

public:
    void createAccount() {
        string name;
        double initialBalance;

        cout << "Enter your name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
        getline(cin, name);

        while (true) {
            cout << "Enter your initial balance: ";
            cin >> initialBalance;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid balance.\n";
            } else {
                break;
            }
        }

        BankAccount newAccount(name, initialBalance);
        accounts.push_back(newAccount);

        cout << "Congratulations " << name << "! You have successfully opened your new bank account with an initial balance of $" 
             << initialBalance << ". Your account number is " << newAccount.getAccountNumber() << ".\n";
    }

    void depositMoney() {
        int accountNumber;
        double amount;
        
        cout << "Enter the account number: ";
        cin >> accountNumber;

        BankAccount* account = findAccount(accountNumber);
        if (account) {
            while (true) {
                cout << "Enter the amount that you would like to deposit: ";
                cin >> amount;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid amount.\n";
                } else {
                    break;
                }
            }
            account->deposit(amount);
            cout << "Congratulations " << account->getName() << "! You have successfully deposited the amount of $"
                 << amount << " in your account #" << account->getAccountNumber() << ". Your current balance is $"
                 << account->getBalance() << ".\n";
        } else {
            cout << "No account number exists!\n";
        }
    }

    void withdrawMoney() {
        int accountNumber;
        double amount;

        cout << "Enter the account number: ";
        cin >> accountNumber;

        BankAccount* account = findAccount(accountNumber);
        if (account) {
            while (true) {
                cout << "Enter the amount that you would like to withdraw: ";
                cin >> amount;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid amount.\n";
                } else {
                    break;
                }
            }
            if (account->withdraw(amount)) {
                cout << "Congratulations " << account->getName() << "! You have successfully withdrawn the amount of $"
                     << amount << " from your account #" << account->getAccountNumber() << ". Your current balance is $"
                     << account->getBalance() << ".\n";
            }
        } else {
            cout << "No account number exists!\n";
        }
    }

    void displayBalance() {
        int accountNumber;

        cout << "Enter the account number: ";
        cin >> accountNumber;

        BankAccount* account = findAccount(accountNumber);
        if (account) {
            cout << "Your current balance is $" << account->getBalance() << ".\n";
        } else {
            cout << "No account number exists!\n";
        }
    }
};

void showMenu() {
    cout << "*************** Welcome to Chase ***************\n"
         << "Please choose one of the following operations:\n"
         << "1- Create a new bank account with an initial balance\n"
         << "2- Deposit Money to an Account\n"
         << "3- Withdraw Money from an Account\n"
         << "4- Display Current Balance of an Account\n"
         << "5- Exit\n"
         << "Enter your choice: ";
}

int main() {
    BankSystem bankSystem;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice.\n";
            continue;
        }

        switch (choice) {
            case 1:
                bankSystem.createAccount();
                break;
            case 2:
                bankSystem.depositMoney();
                break;
            case 3:
                bankSystem.withdrawMoney();
                break;
            case 4:
                bankSystem.displayBalance();
                break;
            case 5:
                cout << "Thank you for using Chase. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

        cout << "Press any key to return to Main Menu...\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Wait for user input
        cin.get();
    }

    return 0;
}
