#include <iostream>
#include <string>

#include "deck.h"

int main(){

    Deck deck;
    deck.fill();

    bool play_on = true;

    int hand_count = 0;
    while(hand_count == 0){
        std::cout << "Select how many hands you need to play (1-8): ";
        std::string input;
        std::cin >> input;
        if(stoi(input) < 9 && stoi(input) > 0){
            hand_count = stoi(input);
        }
    }

    Deck hands[hand_count];
    int player_x_turn = 1;

    while (play_on){
        if(player_x_turn > hand_count){player_x_turn = 1;}
        std::string action = "0";
        while (stoi(action) < 1 || stoi(action) > 7){
            std::cout << "Player " << player_x_turn << " turn. Select action (1-7)\n\
                    1: Draw a card from deck\n\
                    2: Draw x amount of cards\n\
                    3: Reveal hand\n\
                    4: Reveal the deck\n\
                    5: Reveal top card of the deck\n\
                    6: Skip turn\n\
                    7: Stop the game\n";
            std::cin >> action;
        }
        switch (stoi(action))
        {
        case 1:
            if (deck.size() <= 0){
                std::cout << "No cards in deck!\n";
                break;
            }
            deck.draw(hands[player_x_turn-1]);
            player_x_turn++;
            break;
        case 2: {
            if (deck.size() <= 0){
                std::cout << "No cards in deck!\n";
                break;
            }
            std::string amount = "0";
            while(deck.take(stoi(amount), hands[player_x_turn-1]) < 1) {
                std::cout << "Select amount of cards to take 1 - " << deck.size() << ": ";
                std::cin >> amount;
            }
            player_x_turn++;
            break;
        }
        case 3:
            hands[player_x_turn-1].reveal();
            break;
        case 4:
            deck.reveal();
            break;
        case 5:
            deck.reveal_top();
            break;
        case 6:
            player_x_turn++;
            break;
        case 7:
            play_on = false;
            break;
        default:
            break;
        }
    }
}