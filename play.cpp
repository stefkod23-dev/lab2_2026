#include "Player.cpp"
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;
static vector<string> allItems = { "меч", "щит", "зелье", "ключ", "карта", "монеты", "драгоценный камень", "еда" };
static vector<string> randomNames = { "герой", "воин", "маг", "мошенник", "лучник", "рыцарь", "волшебник", "рейнджер" };
Player::Player() : name("Безыменный"), posX(0), posY(0), health(100) {}
Player::Player(const string& name, int x, int y, int hp, const vector<string>& inv) : name(name), posX(x), posY(y), health(hp), inventory(inv) {}
Player::Player(const Player& other) : name(other.name), posX(other.posX), posY(other.posY), health(other.health), inventory(other.inventory) {}
Player::~Player()
{
    cout << "Персонаж " << name << " уничтожен" << endl;
}

Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        name = other.name;
        posX = other.posX;
        posY = other.posY;
        health = other.health;
        inventory = other.inventory;
    }
    return *this;
}
Player Player::operator+(const Player& other) const
{
    Player result;
    result.name = generateRandomName();

    result.posX = (posX + other.posX) / 2;
    result.posY = (posY + other.posY) / 2;

    vector<string> combined = inventory;
    combined.insert(combined.end(), other.inventory.begin(), other.inventory.end());
    result.inventory = removeDuplicates(combined);

    result.health = (health + other.health) / 2;
    return result;
}

Player Player::operator-(const Player& other) const
{
    Player result;
    result.name = generateRandomName();
    result.posX = posX;
    result.posY = posY;
    result.health = health;
    result.inventory = inventory;
    for (const auto& item : other.inventory)
    {
        auto it = find(result.inventory.begin(), result.inventory.end(), item);
        if (it != result.inventory.end())
        {
            if (rand() % 2 == 0)
            {
                result.inventory.erase(it);
            }
        }
    }
    return result;
}
Player Player::operator/(const Player& other) const
{
    Player result;
    result.name = generateRandomName();
    result.posX = posX * 100 + other.posX;
    result.posY = posY + other.posY * 100;
    result.health = (health + other.health) / 2;
    result.inventory.clear();
    if (!inventory.empty())
    {
        size_t half1 = inventory.size() / 2;
        for (size_t i = 0; i < half1; i++)
        {
            result.inventory.push_back(inventory[i]);
        }
    }
    if (!other.inventory.empty())
    {
        size_t half2 = other.inventory.size() / 2;
        for (size_t i = half2; i < other.inventory.size(); i++)
        {
            result.inventory.push_back(other.inventory[i]);
        }
    }
    return result;
}
string Player::generateRandomName()
{
    static mt19937 rng(time(0));
    uniform_int_distribution<int> dist(0, randomNames.size() - 1);
    return randomNames[dist(rng)] + "_" + to_string(rand() % 1000);
}
string Player::getRandomItem()
{
    static mt19937 rng(time(0));
    uniform_int_distribution<int> dist(0, allItems.size() - 1);
    return allItems[dist(rng)];
}
vector<string> Player::removeDuplicates(const vector<string>& items)
{
    vector<string> result;
    for (const auto& item : items)
    {
        if (find(result.begin(), result.end(), item) == result.end())
        {
            result.push_back(item);
        }
    }
    return result;
}
string Player::getName() const { return name; }
int Player::getPosX() const { return posX; }
int Player::getPosY() const { return posY; }
int Player::getHealth() const { return health; }
vector<string> Player::getInventory() const { return inventory; }
void Player::setPosition(int x, int y)
{
    posX = x;
    posY = y;
    cout << name << " переместился в позицию (" << x << ", " << y << ")" << endl;
}
void Player::setHealth(int hp)
{
    health = hp;
    if (health > 100) health = 100;
    if (health < 0) health = 0;
}
void Player::setInventory(const vector<string>& inv)
{
    inventory = inv;
}
void Player::addItem(const string& item)
{
    inventory.push_back(item);
}
void Player::removeItem(const string& item)
{
    auto it = find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end())
    {
        inventory.erase(it);
    }
}
void Player::displayInfo() const
{
    cout << "Имя: " << name << endl;
    cout << "Позиция: (" << posX << ", " << posY << ")" << endl;
    cout << "ХП: " << health << endl;
    cout << "Инвентарь (" << inventory.size() << "): ";
    for (const auto& item : inventory)
    {
        cout << item << " ";
    }
    cout << "\n==============================\n" << endl;
}
void Player::takeDamage(int damage)
{
    if (damage < 0)
    {
        cout << "Урон не может быть отрицательным!" << endl;
        return;
    }
    health -= damage;
    cout << name << " получил " << damage << " урона" << endl;
    if (health <= 0)
    {
        health = 0;
        cout << name << " повержен!" << endl;
    }
}
void Player::heal(int amount)
{
    if (amount < 0)
    {
        cout << "Лечение не может быть отрицательным!" << endl;
        return;
    }
    health += amount;
    cout << name << " восстановил " << amount << " ХП" << endl;
    if (health > 100)
    {
        health = 100;
    }
}