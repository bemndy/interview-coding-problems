#oop-module 5 using properties instead, reinforcing static variables

class User():
    def __init__(self, username, password, email):
        self.username = username
        self.password = password
        self.email = email

user1 = User("boom", "boom@gmail.com", "12345")
user1.email = "this is not an email"
print(user1.email)
print(' ')













class User():
    def __init__(self, username, password, email):
        self.username = username
        self.password = password
        self._email = password #convention intended for internal use, not used by outside of the class




#consenting adults Philosophy


    @property #getter property in python
    def email(self):
        print("email accessed") #getter methods provides single point, where we can be modular with our programming
        return self._email
    
    @email.setter
    def email(self, new_email):
        if '@' in new_email:
            self._email = new_email

        
user1 = User("boom", "boom@gmail.com", "12345")
print(user1.email)
user1.email = 'nice'
print(user1.email)
user1.email = 'nice@dns.com' ##doesn't change unless @
                            ##using decorator for setter function
print(user1.email)
print(' ')

#Static attribute, class attribute, attribute belonging to the class that is not
#unique to each instance, but rather shared among all objects of a class, or
#more generally, not specific to any instance
class User():
    num_users = 0
    def __init__(self, username,  email):
        self.username = username
        self.__email = email #this is not protected variable, but rather it is a private variable
        User.num_users += 1
    
    def display(self):
        print(f"Username: {self.username}")
        print(f"Email: {self.__email}")

brandon = User("brandon", "bmarti32@nd.edu")
brandon.display()
print(f"number of users: {brandon.num_users}")
print(' ')
