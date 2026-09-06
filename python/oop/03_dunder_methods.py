#oop- module 3 magic/dunder functions


class Employee:
    num_of_employees = 0
    raise_amount = 1.04

    def __init__(self, first, last, wallet): #dunder function
        self.first = first
        self.last = last
        self.wallet = wallet * 2
        Employee.num_of_employees += 1

    def __repr__(self): 
        return f"Employee({self.first}, {self.last}, {self.wallet})"
    
    def __str__(self): 
        return "{} {}".format(self.fullname(), self.wallet)
    
    def __add__(self, other):
        self.wallet += other.wallet

    def __len__(self):
        return len(self.fullname())-1

    def fullname(self):
        return f"{self.first} {self.last}"

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



emp1 = Employee("brandon", "martinez", 500)
emp2 = Employee("ethan", "martinez", 90)


print(emp1) #printing what the constructor includes and the str method
print(repr(emp1))

# this is what is used for adding magic function
print(emp1.wallet + emp2.wallet)
print(emp1.wallet, emp2.wallet)

# using the fullname method to calculate length, so we actually subtract len by 1 to be accurate
# intended use to be length of first and last name, just their name
print(len(emp1))



#getters, setters, and deletes using property decorations
class Employee2:
    def __init__(self, first, last):
        self.first = first
        self.last = last

    @property 
    def email(self):
        return f"{self.first}.{self.last}@nd.edu"

    @property
    def fullName(self):
        return f"{self.first} {self.last}"
    
    @fullName.setter
    def fullName(self, name):
        first, last = name.split(" ")
        self.first = first
        self.last = last
    

emp2 = Employee2("jeremiah", "love")

print('\n')
emp2.first = "julian"
print(emp2.first)
print(emp2.email) #email doesn't get changed to julian.love@nd.edu, we fix this using property decorations
print(emp2.fullName)

emp2.fullName = "brandon martinez"
print(emp2.first)
print(emp2.email) #changes name attributes just based off of fullname property we implemented
print(emp2.fullName)
