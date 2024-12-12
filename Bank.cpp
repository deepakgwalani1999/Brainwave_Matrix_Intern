#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Class to represent a bank account
class Account {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    Account(string name, int number, double initialBalance = 0.0)
        : accountHolder(name), accountNumber(number), balance(initialBalance) {}

    // Display account details
    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << accountHolder << "\n";
        cout << fixed << setprecision(2) << "Balance: $" << balance << "\n\n";
    }

    // Deposit funds
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw funds
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully.\n";
            return true;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance.\n";
            return false;
        }
    }

    // Transfer funds
    bool transfer(Account &toAccount, double amount) {
        if (withdraw(amount)) {
            toAccount.deposit(amount);
            cout << "Transferred $" << amount << " to account " << toAccount.getAccountNumber() << ".\n";
            return true;
        }
        return false;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolder() const {
        return accountHolder;
    }

    double getBalance() const {
        return balance;
    }
};

// Bank class to manage multiple accounts
class Bank {
private:
    vector<Account> accounts;
    int nextAccountNumber = 1000;

public:
    // Create a new account
    void createAccount(string name, double initialDeposit) {
        Account newAccount(name, nextAccountNumber++, initialDeposit);
        accounts.push_back(newAccount);
        cout << "Account created successfully. Account Number: " << newAccount.getAccountNumber() << "\n\n";
    }

    // Find an account by account number
    Account* findAccount(int accountNumber) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

    // Display all accounts
    void displayAllAccounts() const {
        if (accounts.empty()) {
            cout << "No accounts found.\n";
        } else {
            for (const auto &account : accounts) {
                account.displayAccountDetails();
            }
        }
    }
};

// Main function
int main() {
    Bank bank;
    int choice;
    do {
        cout << "Online Banking System\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Money\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            double initialDeposit;
            cout << "Enter account holder name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter initial deposit amount: ";
            cin >> initialDeposit;
            bank.createAccount(name, initialDeposit);
            break;
        }
        case 2: {
            int accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter deposit amount: ";
            cin >> amount;
            Account* account = bank.findAccount(accountNumber);
            if (account) {
                account->deposit(amount);
            } else {
                cout << "Account not found.\n";
            }
            break;
        }
        case 3: {
            int accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            Account* account = bank.findAccount(accountNumber);
            if (account) {
                account->withdraw(amount);
            } else {
                cout << "Account not found.\n";
            }
            break;
        }
        case 4: {
            int fromAccountNumber, toAccountNumber;
            double amount;
            cout << "Enter source account number: ";
            cin >> fromAccountNumber;
            cout << "Enter destination account number: ";
            cin >> toAccountNumber;
            cout << "Enter transfer amount: ";
            cin >> amount;
            Account* fromAccount = bank.findAccount(fromAccountNumber);
            Account* toAccount = bank.findAccount(toAccountNumber);
            if (fromAccount && toAccount) {
                fromAccount->transfer(*toAccount, amount);
            } else {
                cout << "One or both accounts not found.\n";
            }
            break;
        }
        case 5: {
            bank.displayAllAccounts();
            break;
        }
        case 6:
            cout << "Exiting system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
        cout << "\n";
    } while (choice != 6);

    return 0;
}
