#oop-module 8

#Static methods are methods contained only within a class

class BankAccount:
    MIN_BALANCE = 100 #global variable kind of


    def __init__(self, owner, balance=0):
        self.owner = owner
        self._balance = balance #protected variable, only internal use

    def deposit(self, amount): 
        if self._amount:
            self._balance += amount
            print(f"success, new balance is {self._balance}")
            self.__log_transaction("deposit", amount)
        else:
            print("error, deposit amount must be positive number")


    def _amount(self, amount): #protected methods, same characteristics of protected variable
                               #protected method, that is used by deposit pubic method, will not throw error
        return amount > 0
    
    
    def __log_transaction(self, transaction_type, transaction): # private method that is used internally by deposit method
        print(f"Logging... {transaction_type}, of {transaction}") # will throw attribute error 

    @staticmethod
    def is_valid_interest_rate(rate): # checks interests rate if it is corrected
                                      # stored in class itself, memory efficient
                                      # not every instance
                                      # help process data
        return 0 <= rate <= 5

brandon = BankAccount("brandon", 0)
brandon.deposit(300)
print(BankAccount.is_valid_interest_rate(6))
brandon.deposit(500)

