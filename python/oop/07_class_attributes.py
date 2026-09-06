#oop-module 7

#static attributes

#a static attribute (sometimes called a class attribute) belongs to the
#class itself and not any specific instance of that class. global almost. 

class User:
    number_users = 0
    #outside init, static variables
    #used for data is common for all instances
    #counters and totals, values constant to all instances

    def __init__(self, username, email):
        self.username = username
        self.email = email
        User.number_users += 1 #have to reference User
        #regular instance variables

    def display(self):
        print(f"{self.username}'s email is {self.email}")

    #Static methods in python are methods that belong to class
    #Does not need self, will only be available within class

brandon = User("brandon", "brandonprvbox@gmail.com")
brandon.display()
print(User.number_users, brandon.number_users)