#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  
  char playGame;
  int cScore = 0, pScore = 0;
  
  cout << "Welcome to Rock, Paper, Scissors!\n";
  cout << "Would you like to play? (y/n)\n";
  do {
    cin >> playGame;
    if (playGame == 'y' || playGame == 'Y') {
      cout << "\n";
      cout << "Rock beats scissors, scissors beats paper, and paper beats rock. The first to win three rounds, wins the game. Good luck!\n";
      break;
    }
    else if (playGame == 'n' || playGame == 'N') {
      cout << "Alright, goodbye!\n";
      return 0;
    }
    else {
      cout << endl;
      cout << "Please enter a valid input.\n";
    }
  } while (playGame != 'y' && playGame != 'Y'
    && playGame!= 'n' && playGame != 'N');

  srand(static_cast<unsigned int>(time(0)));
  
  for (int i =0; i < 3; i++) {
    int playerChoice, computerChoice;
  
    do {
      cout << "\n";
      cout << "Ready? Go! Rock(0), Paper(1), or Scissors(2)?\n";
      cin >> playerChoice;
        if (playerChoice != 0 && playerChoice != 1 && playerChoice != 2) {
          cout << "Please enter a valid option.\n";
        }
      } while (playerChoice != 0 && playerChoice != 1 && playerChoice != 2);
    
      computerChoice = rand() % 3;
      cout << "\n";
      cout << "You chose " << (playerChoice == 0 ? "Rock" : playerChoice == 1 ?           "Paper" : "Scissors") << ".\n";
      cout << "The computer chose " << (computerChoice == 0 ? "Rock" :                   computerChoice == 1 ? "Paper" : "Scissors") << ".\n";
      if (playerChoice == computerChoice) {
        cout << "No one gets a point!\n";
      }
      else if (playerChoice == 0 && computerChoice == 2 ||
              playerChoice == 1 && computerChoice == 0 ||
              playerChoice == 2 && computerChoice == 1) {
        cout << "You got a point!\n";
        pScore++;
      } 
      else {
        cout << "The computer got a point!\n";
        cScore++;
      }
    
  }

  if (pScore > cScore) {
    cout << "\n";
    cout << "You won the game! :)\n";
  }
  else if (pScore == cScore) {
    cout << "\n";
    cout << "It's a draw!\n";
  }
  else {
    cout << "\n";
    cout << "The computer won the game!\n";
    cout << "Game Over :(\n";
  }
}