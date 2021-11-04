#include <iostream>
using namespace std;

//add class definitions below this line

class CardBinder {
  public:
    CardBinder() {
      gold_card = 0;
      silver_card = 0;
    }
  
    int GetGold() {
      return gold_card;
    }
  
    int GetSilver() {
      return silver_card;
    }
  
    int GetTotal() {
      return gold_card+silver_card;
    }
  
    void AddGold(int gc) {
      if (gc > 0) {
        if (gc + GetTotal() < 20) {
          gold_card += gc;
        }
        else {
          cout << "You do not have enough binder room." << endl;
        }
      }
      else {
        cout << "You cannot add a negative or 0 amount of cards." << endl;
      }
    }
  
    void AddSilver(int sc) {
      if (sc > 0) {
        if (sc + GetTotal() < 20) {
          silver_card += sc;
        }
        else {
          cout << "You do not have enough binder room." << endl;
        }
      }
      else {
        cout << "You cannot add a negative or 0 amount of cards." << endl;
      }
    }
  
    void RemoveGold(int gc) {
      if (gc > 0) {
        if (gold_card >= gc) {
          gold_card -= gc;
        }
        else {
          cout << "You do not have enough gold cards to remove." << endl;
        }
      }
      else {
        cout << "You cannot remove a negative or 0 amount of cards." << endl;
      }
    }
  
    void RemoveSilver(int sc) {
      if (sc > 0) {
        if (silver_card >= sc) {
          silver_card -= sc;
        }
        else {
          cout << "You do not have enough silver cards to remove." << endl;
        }
      }
      else {
        cout << "You cannot remove a negative or 0 amount of cards." << endl;
      }
    }
  
  private:
    int gold_card;
    int silver_card;
};

//add class definitions above this line


int main() {
  
  //DO NOT EDIT CODE BELOW THIS LINE

  CardBinder cb;
  cb.AddGold(21);
  cb.AddGold(11);
  cb.AddSilver(-4);
  cb.AddSilver(8);
  cb.RemoveGold(12);
  cb.RemoveGold(4);
  cb.RemoveSilver(-2);
  cb.RemoveSilver(6);
  cout << cb.GetGold() << endl;
  cout << cb.GetSilver() << endl;
  cout << cb.GetTotal() << endl;
  

  //DO NOT EDIT CODE ABOVE THIS LINE
  
  return 0;
  
}
