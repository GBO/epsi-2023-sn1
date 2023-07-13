#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using namespace std;

class Item {
public:
    Item(const string& name, int quantity) : m_name(name), m_quantity(quantity) {}
    const string& getName() const { return m_name; }
    int getQuantity() const { return m_quantity; }
    void setQuantity(int quantity);


private:
    string m_name;
    int m_quantity;
};


#endif // ITEM_HPP
