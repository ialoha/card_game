#include <iostream>

using namespace std;

class Player { //the Player class of the program. 
  public:
    string name; //name variable used to store the name of the player
    int balance; //balance variable used to store the total balance of the player
    int starting_balance; //variable used to store the staring balance of the player

  public:
    Player() {
      name = "";
      balance = 0; 
      starting_balance = 0;

    }
};
