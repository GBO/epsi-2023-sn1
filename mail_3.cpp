
#include <iostream>

using namespace std;

int main()
{
    int T[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    string ordre = "croissant";

    for(int i=0; i<9 && ordre=="croissant"; i++)
    {
        if(T[i] > T[i+1])
            ordre = "quelconque";
        else if(T[i] == T[i+1])
            continue;
    }

    if(ordre == "croissant")
    {
        cout << "Le tableau est trié par ordre croissant" << endl;
        return 0;
    }
    ordre = "décroissant";

    for(int i=0; i<9 && ordre=="décroissant"; i++)
    {
        if(T[i] < T[i+1])
            ordre = "quelconque";
        else if(T[i] == T[i+1])
            continue;
    }
    if(ordre == "décroissant")
    {
        cout << "Le tableau est trié par ordre décroissant" << endl;
        return 0;
    }
    ordre = "constant";

    for(int i=1; i<10 && ordre=="constant"; i++)
    {
        if(T[i] != T[0]) ordre = "quelconque";
    }

    if(ordre == "constant")
    {
        cout << "Le tableau est trié par ordre constant" << endl;
        return 0;
    }
    cout << "Le tableau est trié dans un ordre quelconque" << endl;


    return 0;
}

