/*
 * File:
 * Description:
 * Author :
 * Version :
 * USAGE : #include "Fish.hpp"
*/

#ifndef FISH_HPP
#define FISH_HPP

#include <bits/stdc++.h>
#include "Point.hpp"
#include <iostream>

using namespace std;

class Fish {
public:
    // CTOR CCTOR DTOR OPERATOR=
    Fish();
    Fish(const Fish& fish);
    ~Fish();
    Fish& operator=(const Fish& fish);

    // GETTER SETTER
    static int getFishCount() const;
    string getName() const;
    int getFullPeriod() const;
    bool getIsHungry() const;
    int getHungerPeriod() const;
    int getCoinPeriod() const;
    int getMovementSpeed() const;
    Point getPosition() const;

    static void setFishCount();
    void setName(string _name);
    void setFullPeriod(int _full_period);
    void setIsHungry(bool _is_hungry);
    void setHungerPeriod(int _hunger_period);
    void setCoinPeriod(int _coin_period);
    void setMovementSpeed(int movement_speed);
    void setPosition(Point _position);

    // METHODS
    void Move();
    virtual void DropCoin() = 0;
    virtual void Eat() = 0;

private:
    static int fish_count;
    string name;
    int full_period; // periode kenyang
    bool is_hungry;
    int hunger_period; // periode butuh makan
    int coin_period;
    int movement_speed;
    Point position;
};

class Guppy:public Fish {
public:
    // CTOR CCTOR DTOR
    Guppy();
    Guppy(const Guppy& guppy);
    ~Guppy();
    Guppy& operator=(const Guppy& guppy);

    // GETTER SETTER
    static int getGuppyCount() const;
    int getGrowthLevel() const;

    static void setGuppyCount();
    void setGrowthLevel(int _growth_level);

    // METHODS
    void DropCoin();
    void Eat();

private:
    static int guppy_count;
    int growth_level;
};

class Piranha:public Fish {
public:
    // CTOR CCTOR DTOR
    Piranha();
    Piranha(const Piranha& piranha);
    ~Piranha();
    Piranha& operator=(const Piranha& piranha);

    // GETTER SETTER
    static int getPiranhaCount() const;

    static void setPiranhaCount();

    // METHODS
    void DropCoin();
    void Eat();

private:
    static int piranha_count;
};

class Food {
public:
    // CTOR CCTOR DTOR
    Food();
    Food(const Food& food);
    ~Food();
    Food& operator=(const Food& food);

    // GETTER SETTER
    string getName() const;
    int getMovementSpeed() const;
    Point getPosition() const;

    void setName(string _name);
    void setMovementSpeed(int _movement_speed);
    void setPosition(Point _position);

    // METHODS


private:
    string name;
    int movement_speed;
    Point position;
};

class Coin {
public:
    // CTOR CCTOR DTOR
    Coin();
    Coin(const Coin& coin);
    ~Coin();
    Coin& operator=(const Coin& coin);

    // GETTER SETTER
    int getValue() const;
    Point getPosition() const;

    void setValue(int value);
    void setPosition(Point position);

    // METHODS


private:
    int value;
    Point position;
};

class Siput {
public:
// CTOR CCTOR DTOR
    Siput();
    Siput(const Siput& siput);
    ~Siput();
    Siput& operator= (const Siput& siput);

// GETTER SETTER
    int getMovementSpeed() const;
    Point getPoint() const;

    void setMovementSpeed(int _movement_speed);
    void setPosition(int _position);

// METHODS
    void Move();
    void takeCoin();

private:
    int movement_speed;
    Point position;
};

#endif