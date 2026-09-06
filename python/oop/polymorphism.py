# Polymorphism

# The word polymorphism is derived from Greek, and means "having multiple forms"
# poly = many
# morphs = forms

# type scoping when Python dynamically suggests new methods, inferring it 
# has recognized the existence of a object or class that is created 

# Parent class ("Superclass")
class Vehicle:
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def start(self):
        print("Vehicle is starting.")

    def stop(self):
        print("Vehicle is stopping.")

# Child class ("Subclass") of Vehicle superclass
class Car(Vehicle):
    def __init__(self, brand, model, year, number_of_doors):
        super().__init__(brand, model, year)
        self.number_of_doors = number_of_doors

    # Below, we "override" the start and stop methods, inherited from Vehicle, to provide car-specific behavior

    def start(self):
        print("Car is starting.")

    def stop(self):
        print("Car is stopping.")

# Child class ("Subclass") of Vehicle superclass
class Motorcycle(Vehicle):
    def __init__(self, brand, model, year):
        super().__init__(brand, model, year)

    # Below, we "override" the start and stop methods, inherited from Vehicle, to provide bike-specific behavior

    def start(self):
        print("Motorcycle is starting.")

    def stop(self):
        print("Motorcycle is stopping.")

# To demonstrate adding a new vehicle type no longer requires client code business logic modification -- we EXTEND by adding new plane class
class Plane(Vehicle):
    def __init__(self, brand, model, year, number_of_doors):
        super().__init__(brand, model, year)
        self.number_of_doors = number_of_doors

    def start(self):
        print("Plane is starting.")

    def stop(self):
        print("Plane is stopping.")

# This class will be used to test that we deal with non-vehicles correctly
class RandomClass:
    someAttribute = "Hello there"

# Client code (in other words, inside some other class or script)
# Create list of vehicles to inspect
vehicles = [
    Car("Ford", "Focus", 2008, 5),
    Motorcycle("Honda", "Scoopy", 2018),
    ########## ADD A PLANE TO THE LIST: #########
    Plane("Boeing", "747", 2015, 16),
    ############################################
    RandomClass(),
]

# Loop through list of vehicles and inspect them
for vehicle in vehicles:
    if isinstance(vehicle, Vehicle):
        print(f"Inspecting {vehicle.brand} {vehicle.model} ({type(vehicle).__name__})")
        vehicle.start()
        vehicle.stop()
    else:
        raise Exception("Object is not a valid vehicle")
