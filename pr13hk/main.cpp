#include <iostream>
#include <string>

using namespace std;

class BankovniUcet {
protected:
  string cisloUctu;
  int hotovost;

public:
  BankovniUcet(string cislo, int suma);
  virtual void vypisUdaje();
  void vklad(int suma);
  virtual void vyber(int suma);
  virtual void prevod(int suma, BankovniUcet *ucet);
};

class UcetsPoplatkem : public BankovniUcet {
protected:
  int poplatek;

public:
  UcetsPoplatkem(string cislo, int suma, int vypalne);
  virtual void vypisUdaje();
  void vyber(int suma);
  void prevod(int suma, BankovniUcet *ucet);
};

BankovniUcet::BankovniUcet(string cislo, int suma)
//: cisloUctu(cislo), hotovost(suma)
{
  this->cisloUctu = cislo;
  this->hotovost = suma;
  // cisloUctu = cislo;
  // hotovost = suma;
  cout << "Zalozen ucet " << this->cisloUctu << ". Stav " << this->hotovost
       << " Kc." << endl;
}
void BankovniUcet::vypisUdaje() {
  cout << "Ucet " << this->cisloUctu << ". Stav " << this->hotovost << " Kc."
       << endl;
}
void BankovniUcet::vklad(int suma) {
  hotovost += suma;
  cout << "Vlozeno " << suma << " na ucet " << this->cisloUctu << ". Stav "
       << this->hotovost << " Kc." << endl;
}
void BankovniUcet::vyber(int suma) {
  if (this->hotovost < suma) {
    cout << "Nedostatecna hotovost " << this->hotovost << " Kc." << endl;
  } else {
    this->hotovost -= suma;
    cout << "Vybrano " << suma << " z uctu " << this->cisloUctu << ". Stav "
         << this->hotovost << " Kc." << endl;
  }
}
void BankovniUcet::prevod(int suma, BankovniUcet *ucet) {
  if (this->hotovost < suma) {
    cout << "Nedostatecna hotovost " << this->hotovost << " Kc." << endl;
  } else {
    this->hotovost -= suma;
    ucet->vklad(suma);
    cout << "Prevedeno " << suma << " z uctu " << this->cisloUctu
         << " na cizy ucet. Stav " << this->hotovost << " Kc." << endl;
  }
}

UcetsPoplatkem::UcetsPoplatkem(string cislo, int suma, int vypalne)
    : BankovniUcet(cislo, suma) {
  this->poplatek = vypalne;
  cout << "Zalozen ucet " << this->cisloUctu << " s poplatkem "
       << this->poplatek << " Kc. Stav " << this->hotovost << " Kc." << endl;
}
void UcetsPoplatkem::vypisUdaje() {
  cout << "Ucet " << this->cisloUctu << " s poplatkem " << this->poplatek
       << " Kc. Stav " << this->hotovost << " Kc." << endl;
}
void UcetsPoplatkem::vyber(int suma) {
  if (this->hotovost < suma + this->poplatek) {
    cout << "Nedostatecna hotovost " << this->hotovost << " Kc." << endl;
  } else {
    this->hotovost -= suma + this->poplatek;
    cout << "Vybrano " << suma << " z uctu " << this->cisloUctu
         << " s poplatkem " << this->poplatek << " Kc . Stav " << this->hotovost
         << " Kc." << endl;
  }
}
void UcetsPoplatkem::prevod(int suma, BankovniUcet *ucet) {
  if (this->hotovost < suma + this->poplatek) {
    cout << "Nedostatecna hotovost " << this->hotovost << " Kc." << endl;
  } else {
    this->hotovost -= suma + this->poplatek;
    ucet->vklad(suma);
    cout << "Prevedeno " << suma << " z uctu " << this->cisloUctu
         << " s poplatkem " << this->poplatek << " Kc na cizy ucet. Stav "
         << this->hotovost << " Kc." << endl;
  }
}

int main() {
  // int pp;
  BankovniUcet *ucet1, *ucet2;
  ucet1 = new UcetsPoplatkem("123456789", 10000, 3);
  ucet2 = new BankovniUcet("55555555", 10000);
  // volani metody VypisUdaje u obou uctu
  ucet1->vypisUdaje();
  ucet2->vypisUdaje();

  ucet1->vklad(775);
  ucet2->vklad(50000);

  ucet1->vypisUdaje();
  ucet2->vypisUdaje();
  // volani metody Vyber z uctu1
  ucet1->vyber(50);
  // volani metody Vyber z uctu2
  ucet2->vyber(75);
  // volani metody VypisUdaje u obou uctu
  ucet1->vypisUdaje();
  ucet2->vypisUdaje();
  // volani metody Prevod z uctu1 na ucet2
  ucet1->prevod(820, ucet2);
  // volani metody VypisUdaje u obou uctu
  ucet1->vypisUdaje();
  ucet2->vypisUdaje();

  ucet2->prevod(440, ucet1);

  ucet1->vypisUdaje();
  ucet2->vypisUdaje();
  // delete ucet1;
  // delete ucet2;
  return 0;
}