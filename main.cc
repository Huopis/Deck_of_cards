#include <iostream>
#include <string>

#include "deck.h"

int main(int argc, char **argv){
    Deck deck;
    if (argc > 1 && 0 < atoi(argv[1]) && atoi(argv[1]) < 53){
        for(int i = 0; i < atoi(argv[1]); i++){
            deck.add();
        }
    } else {
        deck.fill();
    }
    std::cout << "Deck before shuffle:\n";
    deck.reveal();
    deck.shuffle();
    std::cout << "Deck after shuffle:\n";
    deck.reveal();
    std::cout << "Top card:\n";
    deck.reveal_top();
    std::cout << "There is " << deck.size() << " cards in the deck.\n";
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
        std::string action; 
        std::cout << "Player " << player_x_turn << " turn. Select action (1-4): \n1: Draw a card from deck\n2: Draw x amount of cards\n3: Reveal hand\n4: Stop game\n";
        std::cin >> action;
        switch (stoi(action))
        {
        case 1:
            deck.draw(hands[player_x_turn-1]);
            player_x_turn++;
            break;
        case 2: {
            std::string amount = "";
            std::cout << "Select amount of cards to take 1 - " << deck.size() << ": ";
            std::cin >> amount;
            if(stoi(amount) > 0 && stoi(amount) <= deck.size()){
                deck.take(stoi(amount), hands[player_x_turn-1]);
            }
            player_x_turn++;
            break;
        }
        case 3:
            hands[player_x_turn-1].reveal();
            player_x_turn++;
            break;
        case 4:
            play_on = false;
            break;
        default:
            break;
        }
    }
}