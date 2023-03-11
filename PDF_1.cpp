

#include <iostream>
// Fonction qui vérifie si un nombre est premier
bool estPremier(int n)
{
  // Un nombre premier est un entier naturel qui admet exactement deux diviseurs distincts entiers et positifs
  if (n <= 1)
  {
    return false;
  }
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int n;
  std::cout << "Saisissez le nombre de nombres premiers a afficher : ";
  std::cin >> n; // saisire le nombre a afficher
  int nbPremiersTrouver = 0;
  int i = 2; // On commence à tester les nombres premiers à partir de 2
  while (nbPremiersTrouver < n)
  {
    if (estPremier(i))
    {
      std::cout << i << " ";
      nbPremiersTrouver++;
    }
    i++;
  }
  return 0;
}