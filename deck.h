#include <algorithm>
#include <random>
#include <vector>

enum class Suite {
  UNDEFINED = 0,
  HEARTS = 1,
  SPADES = 2,
  DIAMONDS = 3,
  CLUBS = 4
};

enum class Power {
  UNDEFINED = 0,
  ACE = 1,
  TWO = 2,
  THREE = 3,
  FOUR = 4,
  FIVE = 5,
  SIX = 6,
  SEVEN = 7,
  EIGHT = 8,
  NINE = 9,
  TEN = 10,
  JACK = 11,
  QUEEN = 12,
  KING = 13
};

class Card {
public:
  //! @brief Default constructor of the Card class.
  //! @param [in]
  Card(Suite suite, Power power);

  void display();

private:
  Suite suite_ = Suite::UNDEFINED;
  Power power_ = Power::UNDEFINED;
};

class Deck {
public:
  //! @brief Default constructor of the class.
  Deck();

  //! @brief Default destructor of the class.
  ~Deck() = default;

  //! @brief Method to add single card from cards_buffer_ to the deck.
  void add();

  //! @brief Method to fill deck with regular 52 cards. Also possible to fill
  //! deck with remaining cards from cards_buffer_. Uses add() method.
  void fill();

  //! @brief Method to draw card from deck to another deck, most commonly to
  //! "hand".
  //! @param [in] deck Deck variable where card is drawn to.
  //! @retval If card drawn succesfullly returns 1. If action failed returns 0;
  int draw(Deck &deck);

  //! @brief Method to take multiple cards from deck to deck (hand).
  //! @param [in] amount Amount of cards to draw from deck.
  //! @param [in] deck Deck variable where cards are drawn to.
  //! @retval Amount of cards drawn from the deck. If action failed returns 0;
  int take(const int &amount, Deck &deck);

  //! @brief Method to suffle cards in the deck to a random order.
  void shuffle();

  //! @brief Method to reveal all cards in the deck. Cards are printed to
  //! console.
  void reveal();

  //! @brief Method to reveal card from top of the deck. Card is printed to
  //! console.
  void reveal_top();

  //! @brief Method to get amount of cards in the deck.
  //! @retval Amount of card in the deck as unsigned integer. If any problems
  //! occur returns 0.
  unsigned size();

private:
  std::vector<Card> cards_;
  std::vector<Card> cards_buffer_;
  std::random_device random_device_ = std::random_device{};
  std::default_random_engine random_number_generator_ =
      std::default_random_engine{random_device_()};
};