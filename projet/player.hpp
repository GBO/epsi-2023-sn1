#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "inventory.hpp"
#include "item.hpp"
#include "zone.hpp"

using namespace std;

class Player
{
public:
    Player(const string& nom, int niveauMax, int xpActuelle);

    string getName() const;
    int getLevel() const;
    int getCurrentXp() const;
    void gainXp(int xp);
    int getRemainingXp() const;
    void addMoney(int money);
    int getMoney() const;
    void addItem(const Item& item);
    void displayInventory() const;
    void addChoppedTree(int count);
    void addEarnedXp(int xp);
    void increaseAxeLevel();
    void displayStatistics() const;
    void sellWood();
    void chopWood(Player& player, Zone& zone);

    Inventory& getInventory();
    const Inventory& getInventory() const; // Adding a const version of the getInventory() function


private:
    string m_name;
    int m_maxLevel;
    int m_currentXp;
    int m_level;
    vector<int> m_requiredXp;
    int m_logCount;
    int m_pricePerLog;
    float m_axeCoefficient;
    int m_choppedTreeCount;
    int m_earnedXp;
    int m_axeLevel;
    int m_money;
    Inventory m_inventory;
};

#endif // PLAYER_HPP
