#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "LinkedList.hpp"
#include "Fish.hpp"
#include "Coin.hpp"
#include "Food.hpp"

using namespace std;

class Aquarium {
public:
    // CTOR
    Aquarium();

    // METHODS
    void AddFishFromFish(const Fish& _fish);
    void AddCoinFromCoins(const Coin& coin);
    void AddFoodfromFoods(const Food& food);

    void DeleteFishFromFish(const Fish& _fish);
    void DeleteCoinFromCoins(const Coin& coin);
    void DeleteFoodfromFoods(const Food& food);
    
private:
    LinkedList<Fish> fish;
    LinkedList<Coin> coins;
    LinkedList<Food> foods;
    Snail snail;
};

#endif