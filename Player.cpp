#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class Player
{
private:
    std::string name;
    int posX;
    int posY;
    int health;
    std::vector<std::string> inventory;

public:
    // Конструкторы
    Player();
    Player(const std::string& name, int x, int y, int hp, const std::vector<std::string>& inv);
    Player(const Player& other); // Копирующий конструктор

    // Деструктор
    ~Player();

    // Оператор присваивания
    Player& operator=(const Player& other);

    // Арифметические операторы
    Player operator+(const Player& other) const;
    Player operator-(const Player& other) const;
    Player operator/(const Player& other) const;

    // Геттеры
    std::string getName() const;
    int getPosX() const;
    int getPosY() const;
    int getHealth() const;
    std::vector<std::string> getInventory() const;

    // Сеттеры
    void setPosition(int x, int y);
    void setHealth(int hp);
    void setInventory(const std::vector<std::string>& inv);
    void addItem(const std::string& item);
    void removeItem(const std::string& item);

    // Вспомогательные методы
    void displayInfo() const;
    void takeDamage(int damage);
    void heal(int amount);

    // Генерация случайного имени
    static std::string generateRandomName();

    // Генерация случайного предмета из списка
    static std::string getRandomItem();

private:
    // Вспомогательный метод для удаления дубликатов
    static std::vector<std::string> removeDuplicates(const std::vector<std::string>& items);
};

#endif