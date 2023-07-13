#ifndef TREE_HPP
#define TREE_HPP

class Tree {
public:
    Tree(int wood);

    int cut();

    int getWood() const;

    void display() const;

private:
    int m_wood;
};

#endif // TREE_HPP
