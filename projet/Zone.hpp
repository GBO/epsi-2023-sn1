#ifndef ZONE_HPP
#define ZONE_HPP

#include "inventory.hpp"
#include "tree.hpp"
#include <vector>
using namespace std;

class Zone {
public:
    Zone(int level, int requiredXp, int logCount, int logPrice);
    ~Zone();
    int getLevel() const;
    int getRequiredXp() const;
    int getLogCount() const;
    void collectLogs(Inventory* inventory);
    int getTreeCount() const;
    Tree getTree(int i) const;
    void display() const;

    Zone(); // Déclaration du constructeur par défaut

private:
    int m_level;
    int m_requiredXp;
    int m_logCount;
    int m_logPrice;
    vector<Tree> m_trees;
};

#endif // ZONE_HPP
