#include "player.hpp"
//#include "Inventory.hpp"
#include "Zone.hpp"
#include "Item.hpp"
#include "Inventory.hpp"
#include <random>

using namespace std;

#include <iostream>

Player::Player(const string& name, int maxLevel, int currentXp)
        : m_name(name), m_maxLevel(maxLevel), m_currentXp(currentXp), m_level(1),
          nbLogs(10), logPrice(5), axeCoefficient(1), nbTreesCut_(0),
          xpEarned_(0), axeLevel_(1), m_money(0), m_inventory()
{
    // Initialization of the array for required XP for each level
    m_xpRequired.resize(maxLevel);
    for (int i = 0; i < maxLevel; ++i) {
        m_xpRequired[i] = 100 * (i + 1);
    }
}

string Player::getName() const
{
    return m_name;
}

int Player::getLevel() const
{
    return m_level;
}

int Player::getXp() const
{
    return m_currentXp;
}

void Player::earnXp(int xp)
{
    m_currentXp += xp;
    if (m_currentXp >= m_xpRequired[m_level - 1]) {
        ++m_level;
        cout << "Congratulations! You are now level " << m_level << "." << std::endl;
    }
}

int Player::getRemainingXp() const {
    return m_xpRequired[m_level] - m_currentXp;
}

const int maxLevel = 50;
const vector<unsigned long long> requiredXp = {0, 100ull, 200ull, 400ull, 800ull, 1600ull, 3200ull, 6400ull,
                                               12800ull, 25600ull, 51200ull, 102400ull, 204800ull, 409600ull,
                                               819200ull, 1638400ull, 3276800ull, 6553600ull, 13107200ull,
                                               26214400ull, 52428800ull, 104857600ull, 209715200ull,
                                               419430400ull, 838860800ull, 1677721600ull, 3355443200ull,
                                               6710886400ull, 13421772800ull, 26843545600ull, 53687091200ull,
                                               107374182400ull, 214748364800ull, 429496729600ull,
                                               858993459200ull, 1717986918400ull, 3435973836800ull,
                                               6871947673600ull, 13743895347200ull, 27487790694400ull,
                                               54975581388800ull, 109951162777600ull, 219902325555200ull,
                                               439804651110400ull, 879609302220800ull, 1759218604441600ull,
                                               3518437208883200ull, 7036874417766400ull, 14073748835532800ull,
                                               28147497671065600ull, 56294995342131200ull, 112589990684262400ull,
                                               28147497671065600ull};


void Player::addMoney(int money) {
    m_money += money;
}

void Player::addItem(const Item& item)
{
    m_inventory.addItem(item.getName(), item.getQuantity());
}

void Player::displayInventory() const
{
    cout << "*** INVENTORY ***" << std::endl;
    m_inventory.display();
}

void displayInventory(const Player& player) {
    cout << "*** INVENTORY ***" << std::endl;
    player.getInventory().display();
}

void Player::addCutTree(int count)
{
    nbTreesCut_ += count;
}

void Player::addEarnedXp(int xp)
{
    xpEarned_ += xp;
}

void Player::increaseAxeLevel()
{
    ++axeLevel_;
}

void Player::displayStatistics() const
{
    cout << "*** STATISTICS ***" << endl;
    cout << "Statistics for player " << m_name << ":" << endl;
    cout << "  Number of trees cut: " << nbTreesCut_ << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "  Earned XP: " << xpEarned_ << endl;
    cout << "  Axe Level: " << axeLevel_ << endl;
    cout << "Money: " << getMoney() << endl;
}

int Player::getMoney() const {
    return m_money;
}

Inventory& Player::getInventory()
{
    return m_inventory;
}

void Player::sellWood() {
    int unitPrice = 5; // Unit price of each log
    int soldLogs = getInventory().getItemCount();
    int earnings = soldLogs * unitPrice;
    getInventory().removeItem("log", soldLogs);
    addMoney(earnings);
    cout << "You have sold " << soldLogs << " log(s) for " << earnings << " gold piece(s)." << endl;
}

void Player::cutWood(Player& player, Zone& zone) {
    cout << "You enter the game zone." << endl;
    zone.display();
    int cutTreesCount = 0;
    for (int i = 0; i < zone.getTreeCount(); i++) {
        Tree tree = zone.getTree(i);
        random_device rd;
        mt19937 gen(rd());
        int xp = tree.cut();
        player.earnXp(xp);
        cout << "You have cut a tree and earned " << xp
             << " experience points!" << endl;
        cout << "You need " << player.getRemainingXp() << " experience points to reach the next level." << endl;

        uniform_int_distribution<int> logDist(1, 3); // Random distribution to determine the number of logs obtained
        int logCount = logDist(gen);
        cout << "You obtained " << logCount << " log(s)." << endl;
        if (logCount > 0) {
            Item log("Log", logCount);
            player.addItem(log);
        }
        cutTreesCount++;
    }
    cout << "You have cut " << cutTreesCount << " trees." << endl;
}

const Inventory& Player::getInventory() const {
    return m_inventory;
}
