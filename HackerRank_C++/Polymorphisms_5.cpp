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
      view = "list";
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
      cout << endl;
      string sc2;
      
      cout << "Enter their name: ";
      getline(cin >> ws, sc2);
      string name = sc2;
      names.push_back(name);
      
      cout << "Enter their personal phone number: ";
      getline(cin >> ws, sc2);
      string personalPhone = sc2;
      personalPhoneNumbers.push_back(personalPhone);
      
      cout << "Enter their personal email: ";
      getline(cin >> ws, sc2);
      string personalEmail = sc2;
      personalEmails.push_back(personalEmail);

      cout << ("Enter their work title: ");
      getline(cin >> ws, sc2);
      string title = sc2;
      titles.push_back(title);

      cout << ("Enter their work phone number: ");
      getline(cin >> ws, sc2);
      string workPhone = sc2;
      workPhoneNumbers.push_back(workPhone);

      cout << ("Enter their work email: ");
      getline(cin >> ws, sc2);
      string workEmail = sc2;
      workEmails.push_back(workEmail);
      
      length++;
      view = "list";
    }
  
    int GetLength() {
      return length;
    }
  
    bool IsNumeric(string s) {
      int value;
      
      if (s == "") {
        return false;
      }
      
      try {
        value = stoi(s);
        return true;
      }
      catch (runtime_error& e) {
        return false;
      }
    }
  
    void HandleChoice() {
      if (choice == "q") {
        view = "quit";
      }
      else if (choice == "a" && view == "list") {
        view = "add";
      }
      else if (IsNumeric(choice) && view == "list") {
        int num = stoi(choice) - 1;
        if (num >= 0 and num < length) {
          index = num;
          view = "info";
        }
      }
    }
  
    void ShowList() {
      cout << endl;
      string sc;
      if (length == 0) {
        cout << "(A)dd a new contact \n(Q)uit \n> ";
        cin >> sc;
        for (char c : sc) {
          choice += tolower(c);
        }
      }
      else {
        for (int i = 0; i < length; i++) {
          cout << (i + 1) << ") " << names.at(i) << endl;
        }
        cout << "\n(#) Select a name\n(A)dd a new contact\n(Q)uit \n> ";
        cin >> sc;
        for (char c : sc) {
          choice += tolower(c);
        }
      }
      HandleChoice();
      choice = "";
    }
  
    void Display() {
      while (true) {
        if (view == "list") {
          ShowList();
        }
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
  cout << contacts.GetLength() << endl;
  
  //add code above this line
  
  return 0;
  
}
