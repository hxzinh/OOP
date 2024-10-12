#include <bits/stdc++.h>

using namespace std;
float rates[] = {0, 0.02, 0.5, 1.25};

struct Date {
    int day, month, year;
} today;

struct SavingsAccount {
    string accountID;
    int accountType;
    string customerName;
    int idNumber;
    Date openDate;
    double Money;
    double interest;
};

/**
 * @brief Checks if the account ID is valid. The ID must be at most 5 characters
 *        long and contain only alphanumeric characters.
 * 
 * @param id The account ID to check.
 * @return true if the account ID is valid, false otherwise.
 */
bool checkAccountID(const string& id) {
    if(id.length() > 5) return false;
    for(int u : id) {
        if((u < '0' || u > '9')
        && (u < 'a' || u > 'z')
        && (u < 'A' || u > 'Z')) return false;
    }
    return true;
}

/**
 * @brief Checks if the customer name is valid. The name must contain only letters and spaces.
 * 
 * @param name The customer name to check.
 * @return true if the customer name is valid, false otherwise.
 */
bool checkCustomerName(const string& name) {
    for(int u : name) {
        if(((u < 'a' || u > 'z')
        && (u < 'A' || u > 'Z'))
        && u != ' ') return false;
    }
    return true;
}

/**
 * @brief Checks if the ID number is valid. The ID number must be either 9 or 12 digits long.
 * 
 * @param id The ID number to check.
 * @return true if the ID number is valid, false otherwise.
 */
bool checkIDNumber(int id) {
    if(id < 0) return false;
    string idStr = to_string(id);
    return idStr.length() == 9 || idStr.length() == 12;
}

/**
 * @brief Checks if the given date is valid.
 * 
 * @param date The date to check.
 * @return true if the date is valid, false otherwise.
 */
bool checkDate(const Date& date) {
    if (date.year < 1000 || date.year > 2100) return false;
    if (date.month < 1 || date.month > 12) return false;
    if (date.day < 1 || date.day > 31) return false;
    if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30) return false;
    if (date.month == 2) {
        bool isLeap = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);
        if (date.day > (isLeap ? 29 : 28)) return false;
    }
    return true;
}

/**
 * @brief Calculates the interest for a given savings account.
 * 
 * @param account The savings account for which to calculate interest.
 * @param rate The interest rate to use.
 * @param curDate The current date.
 * @return The calculated interest.
 */
double calculateInterest(const SavingsAccount& account, double rate, const Date& curDate) {
    int daysInYear = 365;
    int daysElapsed = (curDate.year - account.openDate.year) * daysInYear +
                      (curDate.month - account.openDate.month) * 30 +
                      (curDate.day - account.openDate.day);

    double interest = account.Money * (rate / 100) * (daysElapsed / double(daysInYear));
    return interest;
}

/**
 * @brief Handles money withdrawal from the given savings account.
 * 
 * @param account The savings account from which to withdraw money.
 * @param amount The amount of money to withdraw.
 * @param rate The interest rate to use.
 * @param currentDate The current date.
 */
void withdrawMoney(SavingsAccount& account, double amount, double rate, const Date& currentDate) {
    if (amount > account.Money) {
        cout << "Not enough money to withdraw.\n";
        return;
    }

    double withdrawMoney = 0;

    int daysInYear = 365;
    int daysElapsed = (currentDate.year - account.openDate.year) * daysInYear +
                      (currentDate.month - account.openDate.month) * 30 +
                      (currentDate.day - account.openDate.day);

    if (daysElapsed < 180) { // Early withdrawal
        double interest = account.Money * (rates[1] / 100) * (daysElapsed / double(daysInYear));
        withdrawMoney += interest;
    } else {
        withdrawMoney = account.Money * (rate / 100) * (daysElapsed / double(daysInYear));
    }

    withdrawMoney += amount;
    account.Money -= amount;
    cout << "Withdrawal " << withdrawMoney << "successful. Remaining balance: " << account.Money << '\n';

    return;
}

/**
 * @brief Collects input data to create a new savings account.
 * 
 * @param account The savings account to fill with input data.
 */
void inputSavingsAccount(SavingsAccount& account) {
    while(true) {
        cout << "[+] Enter account ID: ";
        cin >> account.accountID;

        if(!checkAccountID(account.accountID)) {
            cout << "Invalid account ID\n";
            cout << "Please enter again\n";
        }
        else break;
    }

    while(true) {
        cout << "[+] Enter account type:\n";
        cout << "[1] No-term saving\n";
        cout << "[2] Short-term saving\n";
        cout << "[3] Long-term saving\n";
        cin.ignore();
        cin >> account.accountType;

        if(account.accountType > 3 || account.accountType < 0) {
            cout << "Invalid input\n";
            cout << "Please try again.\n";
        }
        else break;
    }

    while(true) {
        cout << "[+] Enter customer name: ";
        cin.ignore();
        getline(cin, account.customerName);

        if(!checkCustomerName(account.customerName)) {
            cout << "Invalid customer name\n";
            cout << "Please enter again\n";
        }
        else break;
    }

    while(true) {
        cout << "[+] Enter ID number: ";
        cin.ignore();
        cin >> account.idNumber;

        if(!checkIDNumber(account.idNumber)) {
            cout << "Invalid ID number\n";
            cout << "Please enter again\n";
        }
        else break;
    }
    
    while(true) {
        cout << "[+] Enter open date (DD MM YYYY): ";
        cin >> account.openDate.day >> account.openDate.month >> account.openDate.year;

        if(!checkDate(account.openDate)) {
            cout << "Invalid date\n";
            cout << "Please enter again\n";
        }
        else break;
    } 

    while(true) {
        cout << "[+] Enter deposit amount: ";
        cin >> account.Money;

        if(account.Money < 0) {
            cout << "Invalid deposit amount\n";
            cout << "Please enter again\n";
        }
        else break;
    }
}

/**
 * @brief Displays information about the given savings account.
 * 
 * @param account The savings account to display.
 */
void displaySavingsAccount(const SavingsAccount& account) {
    cout << "[+] Account ID: " << account.accountID << '\n';
    cout << "[+] Account Type: " << account.accountType << '\n';
    cout << "[+] Customer Name: " << account.customerName << '\n';
    cout << "[+] ID Number: " << account.idNumber << '\n';
    cout << "[+] Open Date: " << account.openDate.day << "/" << account.openDate.month << "/" << account.openDate.year << '\n';
    cout << "[+] Deposit Amount: " << fixed << setprecision(4) << account.Money << '\n';
}

/**
 * @brief Displays the menu options for managing savings accounts.
 */
void menu() { 
    cout << "1. Add new savings account\n";
    cout << "2. Display all savings accounts\n";
    cout << "3. Withdraw money\n";
    cout << "4. Search by account ID\n";
    cout << "5. Search by id number\n";
    cout << "6. List by open day\n";
    cout << "7. Sort by decrease balance\n";
    cout << "8. Sort by increase open day\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";

    return;
}

/**
 * @brief Gets the current date and stores it in the global 'today' variable.
 */
void getToday() {
    time_t t = time(0);
    tm* now = localtime(&t);
    today.day = now->tm_mday;
    today.month = now->tm_mon + 1;
    today.year = now->tm_year + 1900;
}

/**
 * @brief The main function that runs the savings account management system.
 */
int main() {
    getToday();

    vector<SavingsAccount> accounts;

    int choice;
    while(true) {
        menu();
        cin >> choice;
        switch(choice) {
            case 1: {
                SavingsAccount account;
                inputSavingsAccount(account);
                accounts.push_back(account);
                break;
            }

            case 2: {
                if(accounts.empty()) {
                    cout << "No accounts available!\n";
                    break;
                }
                for (const auto& account : accounts) {
                    displaySavingsAccount(account);
                    cout << "----------------------\n";
                }
                break;
            }
            
            case 3: {
                bool checkValid = false;
                int index = 0, cnt = 0;
                while(!checkValid || ++cnt <= 3) {
                    string curId;
                    cout << "Enter your account ID: ";
                    cin >> curId;

                    index = 0;
                    for(SavingsAccount account : accounts) {
                        if(account.accountID == curId) {
                            checkValid = true;
                            break;
                        }
                        index++;
                    }

                    if(checkValid) {
                        cout << "[*] Found your account ID at index " << index << '\n';
                    }
                    else {
                        cout << "[*] Not found ID! Please enter another account ID.";
                    }
                }

                double money;
                cout << "Enter amount of money to withdraw: ";
                cin >> money;

                withdrawMoney(accounts[index], money, rates[accounts[index].accountType], today);

                break;
            }

            case 4: {
                string id;
                cout << "Enter account ID: ";
                cin >> id;
                for (const auto& account : accounts) {
                    if (account.accountID == id) {
                        displaySavingsAccount(account);
                        break;
                    }
                }

                cout << "Account doesnt't exist!!\n";
                break;
            }

            case 5: {
                int id;
                cout << "Enter ID number: ";
                cin >> id;
                for (const auto& account : accounts) {
                    if (account.idNumber == id) {
                        displaySavingsAccount(account);
                        break;
                    }
                }

                cout << "Account doesnt't exist!!\n";
                break;
            }
            
            case 6: {
                cout << "Enter open date (DD MM YYYY): ";
                Date date;
                cin >> date.day >> date.month >> date.year;
                for (const auto& account : accounts) {
                    if (account.openDate.day == date.day && account.openDate.month == date.month && account.openDate.year == date.year) {
                        displaySavingsAccount(account);
                        cout << "----------------------\n";}
                }

                cout << "Account doesnt't exist!!\n";
                break;
            }
            
            case 7: {
                if(accounts.empty()) {
                    cout << "No accounts available!\n";
                    break;
                }

                sort(accounts.begin(), accounts.end(), [](const SavingsAccount& a, const SavingsAccount& b) {
                    return a.Money > b.Money;
                });
                for (const auto& account : accounts) {
                    displaySavingsAccount(account);
                    cout << "----------------------\n";
                }
                break;
            }

            case 8: {
                if(accounts.empty()) {
                    cout << "No accounts available!\n";
                    break;
                }

                sort(accounts.begin(), accounts.end(), [](const SavingsAccount& a, const SavingsAccount& b) {
                    return (a.openDate.year == b.openDate.year) ? 
                        ((a.openDate.month == b.openDate.month) ? 
                            (a.openDate.day < b.openDate.day) : (a.openDate.month < b.openDate.month)) : (a.openDate.year < b.openDate.year);
                });
                for (const auto& account : accounts) {
                    displaySavingsAccount(account);
                    cout << "----------------------\n";
                }
                break;
            }
            
            default: {
                break;
            }
        }
    }

    return 0;
}
