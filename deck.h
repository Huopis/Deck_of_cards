#include <vector>
#include <algorithm>
#include <random>

enum class Suite  {
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
        Card(Suite suite, Power power);

        void display();

    private:
        Suite suite_ = Suite::UNDEFINED;
        Power power_ = Power::UNDEFINED;
};

class Deck {
    public:
        Deck();
        ~Deck() = default;
        void fill();
        void add();
        void draw(Deck &hand);
        void take(const int &amount, Deck &deck);
        void shuffle();
        void reveal();
        void reveal_top();
        int size();
    private:
        std::vector<Card> cards_;
        std::vector<Card> cards_buffer_;
        std::random_device random_device_ = std::random_device {};
        std::default_random_engine random_number_generator_ = std::default_random_engine {random_device_()};
};