# Encapsulation
# bad examples of it to get idea/concept behind it

class BadBankAccount():

    def __init__(self, balance):
        self.balance = balance

account1 = BadBankAccount(0)
account1.balance = -1
print(account1.balance)
print("new better account class after this \n\n")

#good example of it 

class BetterBankAccount():

    def __init__(self):
        self._balance = 0.0

    @property
    def balance(self):
        return self._balance
    
    '''@balance.setter
    def balance(self, balance):
        self._balance = balance'''

    def deposit(self, amount):
        if amount < 0: 
            raise ValueError("Deposit amount must be positive")
        else:
            self._balance += amount

    def withdraw(self, amount):
        if amount < 0: 
            raise ValueError("Withdraw amount must be positive")
        elif amount >= self.balance:
            raise ValueError("Insufficient amount of funds")
        else:
            self._balance -= amount

account1 = BetterBankAccount()
account1.deposit(200.00)
account1.withdraw(199)
print(account1.balance)

## this is a perfect example of encapsulation
## it hides the internal implementation of the 
## setter functions for the user, abstracting it
## cannot directly access balance field aka set it
## it is controlled through our setter methods

## abstracts logic, allowing users to focus on high level
## function and uses of the functions within their needs

## it does so by restricted access to instance variables that are internal
## or even functions that should be internal, and also if not internal, 
## how we get and set these variables so our logic can still work, and we 
## can scale it