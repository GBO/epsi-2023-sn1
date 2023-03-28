#include <iostream>
#include <string>

std::string getZombieName(std::string humanName) {
    std::string zombieName = "";

    for (char c : humanName) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                zombieName += 'm';
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                zombieName += 'M';
                break;
            default:
                zombieName += c;
                break;
        }
    }

    zombieName += zombieName[0];
    zombieName += zombieName[0];

    return zombieName;
}

int main() {
    std::string humanName = "Maurice";
    std::string zombieName = getZombieName(humanName);

    std::cout << humanName << " devient " << zombieName << std::endl;

    return 0;
}