#include <iostream>
#include <string>

class Car {
  public: // these are variables outside class can access
    std::string model; 
    std::string color;
    std::string brand;
    std::string year;
    
   void start() {
        std::cout << "Brandon's car is a " << model << " " << year << " and it is starting \n";
        std::cout << "It has " << miles << " miles on it \n";
   } 

  Car(std::string m, std::string c, std::string b, std::string y) {
    model = m;
    color = c;
    brand = b;
    year = y;
    if (std::stoi(year) < 2000) {
        miles = 200000;
    } else {
        miles = 50000;
    }
  }

  private: // these are variables outside class cannot access
    int miles;
};

int main() {
    Car car1("nissan", "red", "altima", "2015");
    car1.start();

    return 0; 
}