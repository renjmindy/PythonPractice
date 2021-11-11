#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Information {
  public:
    virtual void DisplayInfo() = 0;
    virtual void AddInfo() = 0;
};

class Contacts : public Information {
  public:
    Contacts() {
      view = "quit";
      names = {};
      titles = {};
      workPhoneNumbers = {};
      workEmails = {};
      personalPhoneNumbers = {};
      personalEmails = {};
      choice = "";
      index = 0;
      length = 0;
    }
    void DisplayInfo() {
      
    }
  
    void AddInfo() {
      
    }
  
    void ShowList() {
      
    }
  
    void Display() {
      while (true) {
        if (view == "list") {}
        else if (view == "info") {
          DisplayInfo();
        }
        else if (view == "add") {
          cout << " " << endl;
          AddInfo();
        }
        else if (view == "quit") {
          cout << "\nClosing the contact list...\n";
          break;
        }
      }
    }
  
  private:
    string view;
    vector<string> names;
    vector<string> titles;
    vector<string> workPhoneNumbers;
    vector<string> workEmails;
    vector<string> personalPhoneNumbers;
    vector<string> personalEmails;
    string choice;
    int index;
    int length;
};

//add class definitions above this line

int main() {
  
  //add code below this line
  
  Contacts contacts;
  contacts.Display();
  
  //add code above this line
  
  return 0;
  
}
