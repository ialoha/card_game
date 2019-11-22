#include <iostream> //input/output library included in the main program
#include <string> //string library included in the main program
#include "Card.h" //The class Card is included in the main program
#include "Player.h" //The class Player is included in the main program

using namespace std; //declarative region that provides a scope for the identifiers used in the program

int main() { //main function of the program
	int dealer_rank; //variable used to store the rank of the card the delaer will have
	int player_rank; //varible used to store the rank of the card the player will have
	float bet; //variable that stores the amount of bet money the user wants to make 
	int choice; //variable to store the choice of the user at the main menu (1-3)
	char betchoice; //variable to store the choice the user makes if a card is higher or lower ("h" or "l")
	char cashout; //variable to store the choice if the user wants to cashout
	int moneycashout; //variable to store the amount of the money the user wants to cashout at any stage
	Card card;
	Player player = Player();

	//the whole program is implemented in a do-while loop
	do
	{
		//4 choices shown on the main screen for the user to choose
		cout << endl
			<< "*********************************************************************************** \n "
			<< "1. Start the game. \n"
			<< " 2. Help/Instructions of the game. \n"
			<< " 3. Exit. \n"
			<< " Please enter you number of choice (1, 2 or 3) and press enter \n"; //user must select the coresponding number to the choices availabe
		cin >> choice; //number of the choice is stored in the choice variable
		
		//selected and executed using the switch statement
		switch (choice)
		{
		case 1: //first case is the (1. Start the game) choice

			cout << "Player, what is your name?:"; //game asks the user to write his name
			cin >> player.name; //variable is now stored with the help of the Player Class

			cout << "How much money would you like to start with? "; //game asks the user to state his starting balance
			cin >> player.starting_balance; //variable is now stored with the help of the Player Class
			bet = 0;
			player.balance = player.starting_balance;

			while (player.balance > 0 && (player.balance < player.starting_balance * 5))
			{
				cout << player.name << ", you have $" << player.balance << ". "; //output of the players name and availabe balance

				while (bet == 0 || bet > player.balance)
				{
					cout << "How much money do you want to bet? "; //game asks the user how much money he wants to bet
					cin >> bet; //number is stored in the bet variable

					if (bet > player.balance) { //if statement to check that his bet is lower or equal with his availabe player balance
						cout << "Sorry, you don't have enough money to make that bet. Please enter you bet again \n"; //output if balance is higher
					}
				}

				card = Card();
				dealer_rank = card.get_rank();

				cout << "You draw a " << card.get_rank_string() 
					<< " of " << card.get_suit_string() << ".\n";
				
				cout << "Will the next card be higher or lower? " //asks the player if the next card will be higher or lower
					<< "Enter \"h\" for higher or \"l\" for lower: ";
				cin >> betchoice; //"h" or "l" is stored in the betchoice variable

				card = Card();
				player_rank = card.get_rank();

				cout << "You draw a " << card.get_rank_string()
					<< " of " << card.get_suit_string() << ".\n";

				if ((betchoice == 'h' && dealer_rank > player_rank) ||
					(betchoice == 'l' && dealer_rank < player_rank)) {
					player.balance -= bet;

					cout << "LOSE!!! Too bad " + player.name //output if the player loses the bet
						<< ". You lose $" << bet << ".\n"; //outputs the number of money the player lost
					cout << "Your availabe balance is:$" << player.balance << endl; //output of the new player balance

					cout << "Would you like to cash out; \n"; //game asks if the player wants to cash out
					cout << "Please select 'y' for yes or 'n' for no ";
					cin >> cashout; //choice is stored in the cashout variable

					//if statement if the player wants to cashout or not after losing
					if (cashout == 'y') { //if yes

						cout << "How much money would you like to Cash out;"; //game asks the user how much money to cash out
						cin >> moneycashout; //the amount of money the user wants to cashout is stored in the moneycashout variable

						while (moneycashout > player.balance) //while loop to chech if the player tries to cash out more than his availabe balance
						{
							cout << "Please enter amount again: \n"; //message if the money the user wants to cashout is greater than the number he has available
							cin >> moneycashout; 
						}
						player.balance = player.balance - moneycashout; //total player balance is now his previous total balance minus his cashout

					}
					else if (cashout == 'n') 
					{


					}


				}
				else {
					player.balance += bet;

					cout << "WIN!!! Congratulations " + player.name //output if the player wins
						<< ". You win $" << bet << "!\n"; //output of the money that he won during the bet
					cout << "Your availabe balance is: $" << player.balance << endl; //output if his new balance


					cout << "Would you like to cash out; \n";
					cout << "Please select 'y' for yes or 'n' for no ";
					cin >> cashout;

					//if statement if the player wants to cashout or not after winning
					if (cashout == 'y') { //if the cashout variable is 'y'

						cout << "How much money would you like to Cash out;";
						cin >> moneycashout;

						while (moneycashout > player.balance) //while loop to chech if the player tries to cash out more than his availabe balance
						{
							cout << "Please enter amount again: \n"; //message if the money the user wants to cashout is greater than the number he has available
							cin >> moneycashout;
						}
						player.balance = player.balance - moneycashout; //total player balance is now his previous total balance minus his cashout

					}
					else {

						(cashout == 'n'); //if the cashout variable is 'n'


					}
				}

				bet = 0;
			}

			//if statement if the players balance is equal to zero
			if (player.balance <= 0) {
				//message outputed
				cout << "Too bad " + player.name << ". "
					<< "You are out of money! \n";
			}
			else {
				cout << "You win the game " + player.name << "!";
			}

			break;

		case 2: //second case is the (2. Help/Instructions of the game.) choice

			//the instructions of the game are outputed on the screen

			cout << endl
				<< "*********************************************************************************** \n "
				<< "This is a Higher or Lower Card game.\n"
				<< " The objective is to decide if the card you will draw will be higher or lower than the one the computer will draw.\n"
				<< " You must bet any amount of money in order to start playing the game. \n"
				<< " and then you press 'h' if you beleive the card will be higher or 'l' for lower. \n"
				<< " You win double double the money that you betted if you guess right and none if not. \n"
				<< " Good luck and happy betting!";
			
			break;

		case 3: //third case is the (3. Exit.) choice

			//user can exit out of the game

			return 0;

			break;

		default: //else if any other number for the case is selected etc 4,6,9

			cout << "Not a Valid Choice. \n"; //output that it is not a valid choice
			cout << "Choose again. \n"; //prompts the user to enter from 1-3
			cin >> choice;
			break;
		}

	} while (choice <=100); //termination function of the do-while loop

	return 0;

}


