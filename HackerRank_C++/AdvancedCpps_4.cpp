#include <iostream>
using namespace std;

//add class definitions below this line

class Player {
  public:
    Player() {
      health = 100;
      score = 0;
      level = 1;
    }
  
    static bool ComparePlayers(Player p1, Player p2) {
      if ((p1.health == p2.health) &&
          (p1.score == p2.score) &&
          (p1.level == p2.level)) {
        return true;
      }
      else {
        return false;
      }
    }
  
    void NextLevel() {
      level++;
    }
  
  private:
    int health;
    int score;
    int level;
};

//add class definitions above this line 

int main() {
  
  //add code below this line

  Player mario;
  Player luigi;
  cout << boolalpha;
  cout << (typeid(mario) == typeid(luigi)) << endl;
  mario.NextLevel();
  cout << Player::ComparePlayers(mario, luigi) << endl;
  
  //add code above this line
  
  return 0;
  
}
