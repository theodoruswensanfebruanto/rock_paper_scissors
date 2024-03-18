#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> a = {"Rock", "Paper", "Scissor"};
  int n = a.size();

  int win_number = 0;
  int draw_number = 0;
  int lose_number = 0;

  ifstream infile("data.enc");
  if (infile) {
    infile >> win_number >> draw_number >> lose_number;
    infile.close();
  }

  while (true) {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    cout << "ROCK PAPER SCISSOR";
    cout << "\n";
    cout << "WIN: " << win_number;
    cout << "\n";
    cout << "DRAW: " << draw_number;
    cout << "\n";
    cout << "LOSE: " << lose_number;
    cout << "\n";
    cout << "\n";
    
    cout << "Let's play a game! Rock, paper, or scissor?";
    cout << "\n";
    cout << "1) " << a[0];
    cout << "\n";
    cout << "2) " << a[1];
    cout << "\n";
    cout << "3) " << a[2];
    cout << "\n";

    int player_answer = 0;
    while (player_answer != 1 && player_answer != 2 && player_answer != 3) {
      cout << "Choose between 1, 2, and 3: ";
      cin >> player_answer;
    }
    cout << "\n";

    cout << "YOU      : " << a[player_answer - 1];
    cout << "\n";

    srand(time(nullptr));
    int randomized_index = rand() % n;
    cout << "COMPUTER : " << a[randomized_index];
    cout << "\n";
    cout << "\n";

    if (player_answer - 1 == randomized_index) {
      cout << "DRAW!";
      draw_number++;
    } else if (player_answer - 1 == (randomized_index + 1) % n) {
      cout << "YOU WIN!";
      win_number++;
    } else {
      cout << "YOU LOSE!";
      lose_number++;
    }

    cout << "\n";
    cout << "\n";

    ofstream outfile("data.enc");
    if (outfile) {
      outfile << win_number << " " << draw_number << " " << lose_number;
      outfile.close();
    }

    cout << "Wanna play again?";
    cout << "\n";
    cout << "1) Yes";
    cout << "\n";
    cout << "2) No";
    cout << "\n";
    
    int yes_or_no = 0;
    while (yes_or_no != 1 && yes_or_no != 2) {
      cout << "Choose between 1 and 2: ";
      cin >> yes_or_no;
    }
    cout << "\n";
    
    if (yes_or_no == 2) {
      cout << "Thanks for playing!";
      break;
    }
  }

  return 0;
}