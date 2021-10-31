#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Meal {
  public:
    void AddDrink(string drink) {
      drinks.push_back(drink);
    }
    void PrintDrinks() {
      if (drinks.size() == 0) {
        cout << "Drink(s): None" << endl;
      }
      else if (drinks.size() == 1) {
        cout << "Drink(s): " << drinks.at(0) << endl;
      }
      else if (drinks.size() == 2) {
        cout << "Drink(s): " << drinks.at(0) << " and " << drinks.at(1) << endl;
      }
      else {
        cout << "Drink(s): ";
        for (int i = 0; i < drinks.size() - 1; i++) {
          cout << drinks.at(i) << ", ";
        }
        cout << "and " << drinks.at(drinks.size()-1) << endl;
      }
    }
    void AddAppetizer(string app) {
      appetizers.push_back(app);
    }
    void PrintAppetizers() {
      if (appetizers.size() == 0) {
        cout << "Appetizer(s): None" << endl;
      }
      else if (appetizers.size() == 1) {
        cout << "Appetizer(s): " << appetizers.at(0) << endl;
      }
      else if (appetizers.size() == 2) {
        cout << "Appetizer(s): " << appetizers.at(0) << " and " << appetizers.at(1) << endl;
      }
      else {
        cout << "Appetizer(s): ";
        for (int i = 0; i < appetizers.size() - 1; i++) {
          cout << appetizers.at(i) << ", ";
        }
        cout << "and " << appetizers.at(appetizers.size()-1) << endl;
      }
    }
    void AddMainCourse(string mc) {
      main_courses.push_back(mc);
    }
    void PrintMainCourses() {
      if (main_courses.size() == 0) {
        cout << "Main Course(s): None" << endl;
      }
      else if (main_courses.size() == 1) {
        cout << "Main Course(s): " << main_courses.at(0) << endl;
      }
      else if (main_courses.size() == 2) {
        cout << "Main Course(s): " << main_courses.at(0) << " and " << main_courses.at(1) << endl;
      }
      else {
        cout << "Main Course(s): ";
        for (int i = 0; i < main_courses.size() - 1; i++) {
          cout << main_courses.at(i) << ", ";
        }
        cout << "and " << main_courses.at(main_courses.size()-1) << endl;
      }
    }
    void AddDessert(string dessert) {
      desserts.push_back(dessert);
    }
    void PrintDesserts() {
      if (desserts.size() == 0) {
        cout << "Dessert(s): None" << endl;
      }
      else if (desserts.size() == 1) {
        cout << "Dessert(s): " << desserts.at(0) << endl;
      }
      else if (desserts.size() == 2) {
        cout << "Dessert(s): " << desserts.at(0) << " and " << desserts.at(1) << endl;
      }
      else {
        cout << "Dessert(s): ";
        for (int i = 0; i < desserts.size() - 1; i++) {
          cout << desserts.at(i) << ", ";
        }
        cout << "and " << desserts.at(desserts.size()-1) << endl;
      }
    }
    void PrintMeal() {
      PrintDrinks();
      PrintAppetizers();
      PrintMainCourses();
      PrintDesserts();
    }
  
  private:
    vector<string> drinks;
    vector<string> appetizers;
    vector<string> main_courses;
    vector<string> desserts;
};

//add class definitions above this line     

int main() {
  
  //add code below this line

  Meal dinner;
  //dinner.AddDrink("water");
  //dinner.PrintDrinks();
  //dinner.AddAppetizer("bruschetta");
  //dinner.PrintAppetizers();
  //dinner.AddMainCourse("roast chicken");
  //dinner.PrintMainCourses();
  //dinner.AddDessert("chocolate cake");
  //dinner.PrintDesserts();
  dinner.AddDrink("Pepsi");
  dinner.AddDrink("Sprite");
  dinner.AddAppetizer("egg rolls");
  dinner.AddAppetizer("pot stickers");
  dinner.AddAppetizer("buffalo wings");
  dinner.AddMainCourse("smoked salmon");
  dinner.PrintMeal();

  //add code above this line
  
  return 0;
  
}
