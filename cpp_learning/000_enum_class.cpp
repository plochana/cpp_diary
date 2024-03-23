// Let's try to explore the consequency of using plain enums and enum classes
#include<iostream>

using namespace std;

enum gender {male, female, others}; // Plain Enumeration
enum color {red, pink, green} ;
enum class animal {lion, whale, seahorse}; // Enumeration class
enum class carnivore {lion, tiger, shark}

int main () {
    gender g = gender:: male;
    color c = color::red;
    animal a = animal::lion;
    carnivore ca = carnivore::lion;
    // Typecasting 

    // Following code runs as we are matching an enumeration object g to values of same type
    if (g == gender::male) {
        cout << "Gender is male"<< endl;
    } else {
        cout << "Gender is not male" << endl;
    }

    // Let's try to match the object of enumeration g to values of other enumeration type
    if (g == color::red) {
        cout << "color is red" << endl;
    } else {
        cout << "color is not red" << endl;
    }
    // Above code compiles to give result -> "color is red"
    // Which is not correct as the g is an obect of type gender and is matched with color enum
    // There is an implicit conversion of enum to int, so g gets compiled as 0 because g = gender::male = 0 and color::red is also compiled to 0
    // To prevent sut security issues enum classes are created as they don't lead to implicit type conversion to int.

    // Let's try to match the animal enum class to m
    if (ca == animal::lion){ // This leads to error as there is no typecasting and animal type is getting matched with carnivore type
        cout << "Carniviore is lion" << endl;
    } else {
        cout << "Carnivore is not lion"<< endl;
    }

    return 0;
}