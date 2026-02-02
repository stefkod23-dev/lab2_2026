#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;
class Player
{
private:
    string name;
    int posX;
    int posY;
    int health;
    vector<string> inventory;
public:
    Player();
    Player(const string& name, int x, int y, int hp, const vector<string>& inv);
    Player(const Player& other);
    ~Player();
    Player& operator=(const Player& other);
    Player operator+(const Player& other) const;
    Player operator-(const Player& other) const;
    Player operator/(const Player& other) const;

    string getName() const;
    int getPosX() const;
    int getPosY() const;
    int getHealth() const;
    vector<string> getInventory() const;

    void setPosition(int x, int y);
    void setHealth(int hp);
    void setInventory(const vector<string>& inv);
    void addItem(const string& item);
    void removeItem(const string& item);

    void displayInfo() const;
    void takeDamage(int damage);
    void heal(int amount);

    static string generateRandomName();
    static string getRandomItem();
private:
    static vector<string> removeDuplicates(const vector<string>& items);
};
