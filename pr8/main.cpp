#include <fstream>
#include <iostream>

using namespace std;

struct TCLOVEK {
  char jmeno[30], prijmeni[30];
  char rodneCislo[11];
};
char name[30] = "pr8/data.bin";

void createFile(char *name);
void loadHuman();
void print(TCLOVEK human);
void printAll();
void saveHuman(TCLOVEK human);

void createFile(char *name) {
  ofstream soubor;
  soubor.open(name, ios::binary);
  soubor.close();
}

void loadHuman() {
  TCLOVEK human;
  cout << "Jmeno: ";
  cin >> human.jmeno;
  cout << "Prijmeni: ";
  cin >> human.prijmeni;
  cout << "RC: ";
  cin >> human.rodneCislo;
  saveHuman(human);
  print(human);
}

void saveHuman(TCLOVEK human) {
  ofstream file;
  file.open(name, ios::app | ios::binary);
  file.write((char *)&human, sizeof(human));
}

void print(TCLOVEK human) {
  cout << "Jmeno :" << human.jmeno << endl;
  cout << "Prijmeni: " << human.prijmeni << endl;
  cout << "Rodne cislo: " << human.rodneCislo << endl;
  cout << "Datum narozeni: " << human.rodneCislo[4] << human.rodneCislo[5]
       << ". "
       << ((human.rodneCislo[2] >= 53) ? (char)(human.rodneCislo[2] - 5)
                                       : human.rodneCislo[2])
       << human.rodneCislo[3] << ". ";
  cout << ((human.rodneCislo[9] == 0)
               ? ((((human.rodneCislo[0]) - 48) * 10 +
                       ((human.rodneCislo[1]) - 48) >
                   53)
                      ? "18"
                      : "19")
               : ((((human.rodneCislo[0]) - 48) * 10 +
                       ((human.rodneCislo[1]) - 48) <
                   54)
                      ? "20"
                      : "19"));
  cout << human.rodneCislo[0] << human.rodneCislo[1] << endl;
}

void printAll() {
  ifstream file;
  file.open(name, ios::binary);
  TCLOVEK human;
  while (file.read((char *)&human, sizeof(human))) {
    print(human);
  }
}

int main() {
  // createFile(name);

  // loadHuman();
  printAll();
  return 0;
  /*
  cloveck * ukNa;
  ukNa = new cloveck();

  (*ukNa).plat = 111;

  cout << ukNa->plat;
  // other code
  return 0;
  */
}
