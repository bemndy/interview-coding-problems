# Inheritance

# Inheritance is a fundamental concept in object-oriented programming (OOP) 
# that involves creating  new classes (subclasses or derived classes) 
# based on existing classes (superclasses or base classes)

# ex. a car is a vehicle
#   . a bike is a vehicle
# in this example a bike and care would both be subclasses of a superclass/base class

class Vehicle():

    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def start():
        print("vehicle is starting")

    def stop():
        print("vehicle is stopping")


class Car(Vehicle):
    def __init__(self, brand, model, year, doors, wheels): # must have brand model and year (unless set by default)
        super().__init__(brand, model, year) # use the super function to inherit from vehicle class
        self.doors = doors
        self.wheels = wheels


class Bike(Vehicle):
    def __init__(self, brand, model, year, wheels): # do not have to redo all the variables needed from vehicle class
        super().__init__(brand, model, year)
        self.wheels = wheels

car1 = Car("Ford", "Explorer", "2018", 4, 4)
bike1 = Bike("BMX", "Ultimate", "2018", 2)
print(car1.__dict__, bike1.__dict__)
