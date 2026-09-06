#oop-module1 subclasses, static methods, class methods, inheritance
class Employee:

    num_of_employees = 0
    raise_amount = 1.04

    def __init__(self, first, last, wallet):
        self.first = first
        self.last = last
        self.wallet = wallet * 2
        Employee.num_of_employees += 1

    def fullname(self):
        print(f"{self.first}, {self.last}")

    def apply_raise(self):
        self.wallet = (int(self.wallet) * self.raise_amount) #using class variables
    
    @classmethod
    def set_raise_amount(cls, amount):
        cls.raise_amount = amount

    @classmethod # alternative constructor
    def from_string(cls, emp_string):
        first, last, wallet = emp_string.split('-')
        return cls(first, last, int(wallet))
    
    @staticmethod
    def is_workday(day):
        if day.weekday() == 5 or day.weekday() == 6:
            return False
        return True

emp1 = Employee("brandon", "martinez", 50)
emp2 = Employee("test", "user", 60)

emp1.fullname()
emp2.fullname()
print(f"{emp1.first} and {emp2.first} are our two objects")

print(Employee.raise_amount)
Employee.set_raise_amount(1.05)
print(emp1.raise_amount)

emp3_string = "ethan-martinez-150" #string has different format we just want to pass it so we can construct object
emp3 = Employee.from_string(emp3_string) #using alternative constructor instead of __init__

emp3.fullname()


class Developer(Employee): 
    def __init__(self, first, last, wallet, prog_lang):
        super().__init__(first, last, wallet)
        self.prog_lang = prog_lang

class Manager(Employee):
    def __init__(self, first, last, wallet, employees=None):
        super().__init__(first, last, wallet)
        if not employees: 
            self.num_employees = []
        else: 
            self.num_employees = employees

    def add_employee(self, new_employee):
        if new_employee not in self.num_employees:
            self.num_employees.append(new_employee)
    def remove_employee(self, new_employee):
        if new_employee in self.num_employees:
            self.num_employees.remove(new_employee)
    def print_employees(self):
        for emp in self.num_employees:
            print(emp)

dev1 = Developer("new", "developer", 1200, "swift")
dev2 = Developer("new", "developer2", 5000, "python")
dev1.fullname()
dev2.fullname()

dev1.set_raise_amount(1.04)
#dev1.set_raise_amount(1.05) changes the previous raise amount
dev1.apply_raise()
print(dev1.wallet)

dev3 = Developer("new", "developer3", 300, "c")
print(f"this is the first name: {dev3.first}, this is the last name: {dev3.last}, and they like to program in {dev3.prog_lang}")
#basic inheritance at the top above this line
#print(dev1.set_raise_amount(1.05))

man1 = Manager("the", "boss", 500, ["brandon", "user"])
print(f"{man1.first}, manages these employees: " + " ".join(man1.num_employees))

man1.add_employee("joshua")
man1.remove_employee("brandon")
man1.print_employees()

print(issubclass(Developer, Employee), issubclass(Developer, Manager)) 
#both subclasses of the Employee class
# but no subclasses of each other
#inheritance used for obtaining json web request, 440 
