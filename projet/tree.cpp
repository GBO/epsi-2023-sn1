#include "tree.hpp"

#include <iostream>

Tree::Tree(int wood /* = 0 */) :
        m_wood(wood) {}

int Tree::cut() {
    int xp = m_wood;
    m_wood = 0;
    return xp;
}

int Tree::getWood() const {
    return m_wood;
}

void Tree::display() const {
    std::cout << "Wood: " << m_wood << std::endl;
}