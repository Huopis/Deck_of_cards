#include <iostream>
#include <string>

#include "deck.h"

int main() { //This is simple commandline runnable visualization of the Deck class usage.
  Deck deck;
  deck.fill();

  std::cout << "Welcome!\n";

  bool play_on = true;

  int hand_count = 0;
  while (hand_count == 0) {
    std::cout << "Select how many hands you need to play (1-8): ";
    std::string input;
    std::cin >> input;
    if (stoi(input) < 9 && stoi(input) > 0) {
      hand_count = stoi(input);
    }
  }

  Deck hands[hand_count];
  int player_x_turn = 1;

  std::cout << "Remember to shuffle your deck :)\n";
  while (play_on) {
    if (player_x_turn > hand_count) {
      player_x_turn = 1;
    }
    std::string action = "0";
    while (stoi(action) < 1 || stoi(action) > 9) {
      std::cout << "Player " << player_x_turn << " turn. Select action (1-9)\n\
                    1: Draw a card from deck\n\
                    2: Draw x amount of cards\n\
                    3: Reveal hand\n\
                    4: Reveal the deck\n\
                    5: Reveal top card of the deck\n\
                    6: Show deck size\n\
                    7: Suffle deck\n\
                    8: Skip turn\n\
                    9: Stop the game\n";
      std::cin >> action;
    }
    switch (stoi(action)) {
    case 1:
      if (deck.size() <= 0) {
        std::cout << "No cards in deck!\n";
        break;
      }
      deck.draw(hands[player_x_turn - 1]);
      player_x_turn++;
      break;
    case 2: {
      if (deck.size() <= 0) {
        std::cout << "No cards in deck!\n";
        break;
      }
      std::string amount = "0";
      while (deck.take(stoi(amount), hands[player_x_turn - 1]) < 1) {
        std::cout << "Select amount of cards to take 1 - " << deck.size()
                  << ": ";
        std::cin >> amount;
      }
      player_x_turn++;
      break;
    }
    case 3:
      hands[player_x_turn - 1].reveal();
      break;
    case 4:
      deck.reveal();
      break;
    case 5:
      deck.reveal_top();
      break;
    case 6:
      std::cout << "Cards in deck: " << deck.size() << "\n";
      break;
    case 7:
      deck.shuffle();
      break;
    case 8:
      player_x_turn++;
      break;
    case 9:
      play_on = false;
      break;
    default:
      break;
    }
  }
}