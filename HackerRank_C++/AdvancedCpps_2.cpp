#include <iostream>
using namespace std;

//add class definitions below this line

class Player {
  public:
    Player() {
      health = 100;
      score = 0;
    }
    void PrintLevel() {
      cout << level << endl;
    }
    static int ChangeLevel(int change) { //define static function
      level = change;
      return level;
    }
    static string ChangeColor(string change_color) {
      color = change_color;
      return color;
    }
  
  private:
    int health;
    int score;
    static int level; //declare static variable
    static string color;
};

//add class definitions above this line

int Player::level = 5; //initalize static variable globally
string Player::color;

int main() {
  
  //add code below this line

  Player mario;
  mario.PrintLevel(); //calling class function, object required
  cout << Player::ChangeLevel(6) << endl; //calling static function, object not needed
  Player luigi;
  luigi.PrintLevel();
  
  //add code above this line
  
  return 0;
  
}

//add class definitions above this line
