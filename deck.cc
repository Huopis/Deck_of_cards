#include "deck.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <utility>

uint8_t MAX_CARDS = 52;

std::map<Suite, std::string> suite_to_string{{Suite::UNDEFINED, "Undefined"},
                                             {Suite::HEARTS, "Hearts"},
                                             {Suite::SPADES, "Spades"},
                                             {Suite::DIAMONDS, "Diamonds"},
                                             {Suite::CLUBS, "Clubs"}};

std::map<Power, std::string> power_to_string{{Power::UNDEFINED, "Undefined"},
                                             {Power::ACE, "Ace"},
                                             {Power::TWO, "Two"},
                                             {Power::THREE, "Three"},
                                             {Power::FOUR, "Four"},
                                             {Power::FIVE, "Five"},
                                             {Power::SIX, "Six"},
                                             {Power::SEVEN, "Seven"},
                                             {Power::EIGHT, "Eight"},
                                             {Power::NINE, "Nine"},
                                             {Power::TEN, "Ten"},
                                             {Power::JACK, "Jack"},
                                             {Power::QUEEN, "Queen"},
                                             {Power::KING, "King"}};

Card::Card(Suite suite, Power power) { //Initial construction of card.
  suite_ = std::move(suite);
  power_ = std::move(power);
}

void Card::display() { //Display card method to print easily readable info. Using suite and power mapping to convert enum to string.
  std::cout << "Card: " << power_to_string.find(power_)->second << " of "
            << suite_to_string.find(suite_)->second << "\n";
}

Deck::Deck() {
  cards_.reserve(MAX_CARDS); //Reserve regular card deck amount of size from card holder vectors.
  cards_buffer_.reserve(MAX_CARDS);

  for (int i = 1; i < 5; i++) { //Loop 4 suites for 13 cards.
    for (int j = 1; j < 14; j++) {
      cards_buffer_.emplace_back(static_cast<Suite>(i), static_cast<Power>(j)); //Generate cards to buffer where they can be drawn from to the deck.
    } //This initialization is a bit questionable even for me but without it add() method would be useless. Maybe i'm missing some point in the instructions..
  }
}

bool Deck::add() {
  if (!cards_buffer_.empty()) { //Check if buffer contains cards.
    cards_.push_back(cards_buffer_.back()); //Copy card from buffer to cards vector
    cards_buffer_.pop_back(); //Remove card from buffer
    return true;
  } else {
    return false;
  }
}

void Deck::fill() {
  for (Card card : cards_buffer_) { //Move full deck or remaining cards from buffer to usable deck. 
    add(); //This method could also be just creating the initial deck but to respect given instructions this uses the add() method.
  }
}


bool Deck::draw(Deck &deck) {
  if (size() > 0) { // Making sure deck contauns atleast 1 card.
    deck.cards_.push_back(cards_.back()); //Card is copied from cards vector to given decks cards vector
    cards_.pop_back(); // and removed from original source.
    return true;
  } else { //Warn user for empty deck
    std::cout << "Deck is empty of cards!\n";
    return false;
  }
}

int Deck::take(const int &amount, Deck &deck) {
  int drawn = 0; //Using this variable to make sure correct amount of cards are drawn. Eventhough errors are very unlikely.
  if (size() >= amount) { //Making sure deck has atleast wanted amount of cards in it
    for (int i = 0; i < amount; i++) {
      if (draw(deck)) { //Using draw() here and based on it's return incrementing drawn cards variable.
        drawn++; 
      }
    }
  } else { //Giving information about amount of card in the deck when too many has been tried to draw.
    std::cout << "Amount for cards to take is greater than cards in the deck. "
                 "Deck has "
              << size() << " cards.\n";
  }
  return drawn;
}

void Deck::shuffle() {
  std::shuffle(std::begin(cards_), std::end(cards_), random_number_generator_); //Shuffle deck with randomizer so every run it's different.
}


void Deck::reveal() {
  for (Card card : cards_) { //Loop through the cards vector and display cards.
    card.display();
  }
}

void Deck::reveal_top() { cards_.back().display(); }

unsigned Deck::size() {
  if (cards_.size() >= 0) { // I wanted to remove the -1 possibility from std::vector::size() since deck can't physically contain less 0 cards.
    return cards_.size();
  } else {
    return 0;
  }
}