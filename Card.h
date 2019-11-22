#include <iostream>
#include <ctime>

using namespace std;

class Card { //the Card class of the program
  private:
    int rank; //variable to store the rank of each card
    int suit; //variable used to store thr suit of each card

  public: 
	//this rand function is used to randomly generate one card of the 52 that are availabe on a single deck of cards
    Card() {
      srand(time(NULL));
      rank = (1 + (std::rand() % (int)(13))); //random rank (13 different from Ace to King)
      suit = (1 + (std::rand() % (int)(4))); //random suit (Hearts,Clubs,Diamonds,Spades)
    }

    int get_rank() {
      return rank; //reterns a random rank
    }

    string get_rank_string() { //initialization of the card ranks
      if (rank == 1) return "Ace";
      if (rank == 2) return "Two";
      if (rank == 3) return "Three";
      if (rank == 4) return "Four";
      if (rank == 5) return "Five";
      if (rank == 6) return "Six";
      if (rank == 7) return "Seven";
      if (rank == 8) return "Eight";
      if (rank == 9) return "Nine";
      if (rank == 10) return "Ten";
      if (rank == 11) return "Jack";
      if (rank == 12) return "Queen";
      if (rank == 13) return "King";
      else return "Uknown rank";
    }

    int get_suit() {
      return suit; //reterns a random suit
    }

    string get_suit_string() { //initialization of the card suits
      if (suit == 1) return "Diamonds";
      if (suit == 2) return "Hearts";
      if (suit == 3) return "Spades";
      if (suit == 4) return "Clubs";
      else return "Unknown suit";
    }
};
