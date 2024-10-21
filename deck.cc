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

Card::Card(Suite suite, Power power) {
  suite_ = std::move(suite);
  power_ = std::move(power);
}

void Card::display() {
  std::cout << "Card: " << power_to_string.find(power_)->second << " of "
            << suite_to_string.find(suite_)->second << "\n";
}

void Deck::fill() {
  for (Card card : cards_buffer_) {
    add();
  }
}

void Deck::add() {
  cards_.push_back(std::move(cards_buffer_.back()));
  cards_buffer_.pop_back();
}

int Deck::draw(Deck &deck) {
  if (size() > 0) {
    deck.cards_.push_back(cards_.back());
    cards_.pop_back();
    return 1;
  } else {
    std::cout << "Deck is empty of cards!\n";
    return 0;
  }
}

int Deck::take(const int &amount, Deck &deck) {
  int drawn = 0;
  if (size() >= amount) {
    for (int i = 0; i < amount; i++) {
      draw(deck);
      drawn++;
    }
  } else {
    std::cout << "Amount for cards to take is greater than cards in the deck. "
                 "Deck has "
              << size() << " cards.\n";
  }
  return drawn;
}

void Deck::shuffle() {
  std::shuffle(std::begin(cards_), std::end(cards_), random_number_generator_);
}

Deck::Deck() {
  cards_.reserve(MAX_CARDS);
  cards_buffer_.reserve(MAX_CARDS);

  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 14; j++) {
      cards_buffer_.emplace_back(static_cast<Suite>(i), static_cast<Power>(j));
    }
  }
}

void Deck::reveal() {
  for (Card card : cards_) {
    card.display();
  }
}

void Deck::reveal_top() { cards_.back().display(); }

unsigned Deck::size() {
  if (cards_.size() >= 0) {
    return cards_.size();
  } else {
    return 0;
  }
}