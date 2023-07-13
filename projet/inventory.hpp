#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <string>
#include "item.hpp"

class Inventory {
public:
    Inventory(): m_items() {}
    void addItem(const Item& item);
    void display() const;
    int getItemCount() const;
    void addItem(const std::string& itemName, int quantity);
    void removeItem(const std::string& itemName, int quantity);

private:
    std::vector<Item> m_items;
};

#endif // INVENTORY_HPP
