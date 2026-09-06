#oop-module 6

class User:
    def __init__(self, username, password, email):
        self.username = username
        self.password = password
        self.__email = email #protected variable

    @property #getter property for python
    def email(self) -> str: 
        print("email accessed via getter")
        return self.__email
    
    @email.setter
    def email(self, email: str):
        if '@' in email:
            self.__email = email


brandon = User("brandon", "12345", "bmarti32@nd.edu")
brandon.email = "nice@com"
print(brandon.email)

### these are all instance variables, private, instance, and protected variables 
### we also explored how to access them through getter and setter functions