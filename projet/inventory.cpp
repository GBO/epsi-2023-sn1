#include "inventory.hpp"
#include <iostream>
using namespace std;


void Inventory::addItem(const string& itemName, int quantity) {
    Item item(itemName, quantity);
    m_items.push_back(item);
}

void Inventory::removeItem(const string& itemName, int quantity) {
    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        if (it->getName() == itemName) {
            it->setQuantity(it->getQuantity() - quantity);
            if (it->getQuantity() <= 0) {
                m_items.erase(it);
            }
            break;
        }
    }
}

void Inventory::display() const {
    if (m_items.empty()) {
        cout << "The inventory is empty." << endl;
    } else {
        cout << "Inventory contents:" << endl;
        for (const Item& item : m_items) {
            cout << "- " << item.getName() << ": " << item.getQuantity() << endl;
        }
    }
}

int Inventory::getItemCount() const {
    return m_items.size();
}