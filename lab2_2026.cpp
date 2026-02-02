#include "Player.cpp"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "RUS");
    cout << "1. СОЗДАНИЕ ПЕРСОНАЖЕЙ:" << endl;

    vector<string> inv1 = { "меч", "щит", "зелье" };
    vector<string> inv2 = { "зелье", "ключ", "карта", "монета", "драгоценный камень" };

    Player player1("Герой", 10, 10, 100, inv1);
    Player player2("Воин", 0, 0, 80, inv2);

    cout << "\nИгрок 1:" << endl;
    player1.displayInfo();

    cout << "Игрок 2:" << endl;
    player2.displayInfo();

    cout << "\n2. ТЕСТИРОВАНИЕ ОПЕРАТОРА + (объединение):" << endl;
    Player player3 = player1 + player2;
    player3.displayInfo();

    cout << "\n3. ТЕСТИРОВАНИЕ ОПЕРАТОРА - (вычитание):" << endl;
    Player player4 = player1 - player2;
    player4.displayInfo();

    cout << "\n4. ТЕСТИРОВАНИЕ ОПЕРАТОРА / (разделение):" << endl;
    Player player5 = player1 / player2;
    player5.displayInfo();

    cout << "\n5. ТЕСТИРОВАНИЕ ОПЕРАТОРА = (присваивание):" << endl;
    Player player6;
    cout << "\nДо" << endl;
    player6.displayInfo();
    player6 = player1;
    cout << "После" << endl;
    player6.displayInfo();

    cout << "\n6. ТЕСТИРОВАНИЕ КОНСТРУКТОРА КОПИРОВАНИЯ:" << endl;
    Player player7(player2);
    player7.displayInfo();

    cout << "\n7. ТЕСТИРОВАНИЕ МЕТОДОВ КЛАССА:" << endl;
    player1.setPosition(50, 75);
    cout << "\nб) Добавление предмета 'ключ' player1:" << endl;
    player1.addItem("ключ");
    cout << "\nв) Удаление предмета 'щит' player1:" << endl;
    player1.removeItem("щит");
    player1.displayInfo();
    cout << "\nг) player2 получает урон:" << endl;
    player2.takeDamage(30);
    player2.displayInfo();
    cout << "\nд) player2 лечится:" << endl;
    player2.heal(20);
    player2.displayInfo();
    cout << "\nе) player2 получает сильное лечение:" << endl;
    player2.heal(50);
    player2.displayInfo();
    cout << "\nж) player2 получает смертельный урон:" << endl;
    player2.takeDamage(200);
    player2.displayInfo();

    cout << "\n8. ТЕСТИРОВАНИЕ ГЕТТЕРОВ:" << endl;
    cout << "Имя: " << player1.getName() << endl;
    cout << "Позиция X: " << player1.getPosX() << endl;
    cout << "Позиция Y: " << player1.getPosY() << endl;
    cout << "Здоровье: " << player1.getHealth() << endl;
    vector<string> inv = player1.getInventory();
    cout << "Инвентарь (" << inv.size() << " ): ";
    for (const auto& item : inv)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "\n9. ЦЕПОЧКА ОПЕРАЦИЙ:" << endl;
    cout << "\nСоздаем нового игрока:" << endl;
    Player player8("Маг", 100, 100, 60, { "посох", "книга", "зелье" });
    player8.displayInfo();
    Player player9 = (player1 + player8) - player2;
    player9.displayInfo();

    cout << "\n10. ЗАВЕРШЕНИЕ ПРОГРАММЫ (деструкторы):" << endl;
    {
        Player temp("Временный", 1, 1, 10, { "предмет" });
    }
    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
}