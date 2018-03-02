#include <iostream>
#include <string.h>

#define max_length 50
using namespace std;

class BankAccount {

        int balance;
        char clinet_name[max_length];
        char bank_number[max_length];
    
    public:
    BankAccount(char _clinet_name[], char _bank_account[], int newBalance) {
        if (strlen(_clinet_name) < max_length ) {
            strcpy(clinet_name, _clinet_name);
        }
        
        if (strlen(_bank_account) < max_length) {
            strcpy(bank_number, _bank_account);
        }
        
        setBalance(newBalance);
    }
    
    void printBankInfo() {
        cout<<"\tBank number: "<<bank_number<<"\n\tclient name: "
            <<clinet_name<<"\n\tBalance:   "
            <<balance<<endl;
    }
    
    void depositMoney(int money) {
        if (validBalance(money)) {
            balance += money;
        }
        else {
            cout<<"invlaid input!\n";
        }
    }
    
    bool validBalance(int newBalance){
        return newBalance > 0;
    }
    
    void withdraw(int neededMoney) {
        if (balance >= neededMoney && validBalance(neededMoney)){
            balance -= neededMoney;
        }
    }
    
    bool operator==(const BankAccount& otherBankAccount) {
        return otherBankAccount.balance == this->balance;
    }
    
    
    
    
    int getBalance() {
        return balance;
    }
    
    void setBalance(int newBalace) {
        if (validBalance(newBalace)) {
            balance = newBalace;
        }
    }
    
    char* getBankAccount(){
        return bank_number;
    }
    
};


int main(int argc, const char * argv[]) {
    
    char my_bank_account[] = "BGPRBS12365AHJSD1GB";
    char my_client_name[] = "Emil Iliev";
    int balance = 1000000;
    
    
    BankAccount test_account(my_client_name, my_bank_account,balance);
    
    test_account.depositMoney(-10);
    
    
    test_account.printBankInfo();
    test_account.printBankInfo();
    
    
    BankAccount sava_account("askfbaskjgnabsjkfa", "Sava", balance);
    cout<<(test_account == sava_account)<<endl;
    
    int test_account_balance = test_account.getBalance();
    
//    test_account_balance = 10;
    
    cout<<test_account_balance<<" "<<test_account.getBalance()<<endl;
    
    
    cout<<test_account.bank_number<<endl;
    return 0;
}










