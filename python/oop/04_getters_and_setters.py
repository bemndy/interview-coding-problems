#oop-module 4 getter and setter functions in java, naming conventions for private/protected variables

'''
class Person():
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def greet(self):
        print(f"hello my name is {self.name} and I am {self.age} years old")


brandon = Person('brandon', 20)
print(type(brandon))
brandon.greet()
print('\n')
'''

class User():
    def __init__(self, username, email, password):
        self.username = username
        self._email = email
        self.password = password
        self.__privateEmail = email
        self._protectedEmail = email
    
    def say_hi(self, user):
        print(
            f"sending message to {user.username}: hello it is {self.username}"
        )

    def get_email(self):
        return self._email
    
    def clean_email(self):
        return self._email.lower()
    
    def get_protectedEmail(self):
        print("accessing email")
        return self._protectedEmail
        
    
    def set_protectedEmail(self, email):
        if '@' not in email:
            return
        self._protectedEmail = email
        # biggest takeaway is we can change this in the future easily 
        print("changed email")


brandon = User('brandon', 'bmarti32@nd.edu', '12345')
user1 = User('user', 'user1@gmail.com', '12345')
brandon.say_hi(user1)
print(' ')


print(user1._email) #convention for not using variable outside of class
print(brandon.get_email())
caps = User('capital', 'CAPITAL@icloud.CoM', '12345')
print(caps.clean_email())
print(' ')

#print(brandon.__privateEmail) 
#double underscore means it is a private variable only used within a class
#throws an error, protected variables are readable and reflect internal use in the class
#private variables only used when absolutely necessary

print(brandon.get_protectedEmail())
brandon.set_protectedEmail("brandonprvbox@gmail.com")
print(brandon.get_protectedEmail())
print(' ')

