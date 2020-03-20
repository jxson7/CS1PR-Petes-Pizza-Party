#include <iostream>

using namespace std;

class Account{
public:
  Account( float balance = 0 ){
    this->balance = balance;
  }

  float getBalance(){
    return balance;
  }


  void deposit (float money){
    this->balance += money;
  }

  void withdraw (float money){
    this->balance -= money;
  }

  int getAccountNo (){
    return accountNo;
  }

  bool transfer(Account & to, float amount){
    if(balance < amount){
      return false;
    }
    to.balance += amount;
    balance -= amount;
    return true;
  }

private:
  int accountNo;
  float balance;
};

int main(){
  Account a(100);
  Account b;

  cout << "a: " << a.getBalance() << " b: " << b.getBalance() << endl;
  a.transfer(b, 10);
  cout << "a: " << a.getBalance() << " b: " << b.getBalance() << endl;

  return 0;
}
