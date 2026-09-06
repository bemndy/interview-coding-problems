#oop-module1 basic class and objects, class variables, instance variables

class Employee:
    pass #if class is empty 

emp1 = Employee()
emp2 = Employee()

print(emp1, emp2)

emp1.first = "Brandon"
emp1.last = "Martinez"
emp1.wallet = 50

emp2.first = "Test"
emp2.last = "User"
emp2.wallet = 60

print(emp1.wallet, emp2.wallet)

class Employee2:

    num_of_employees = 0
    raise_amount = 1.04
    def __init__(self, first, last, wallet):
        self.first = first
        self.last = last
        self.wallet = wallet * 2
        Employee2.num_of_employees += 1

    def fullname(self):
        print(f"{self.first}, {self.last}")

    def apply_raise(self):
        self.wallet = (int(self.wallet) * self.raise_amount) #using class variables


emp1 = Employee2("brandon", "martinez", 10)
emp2 = Employee2("user", "test", 20)

emp1.fullname()
emp2.fullname()
Employee2.fullname(emp2) #why we use self

print(emp1.wallet)
emp1.apply_raise()
print(emp1.wallet)
print(Employee2.num_of_employees)



