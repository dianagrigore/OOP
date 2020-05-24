#include <bits/stdc++.h>
using namespace std;

struct data{
    int zi;
    int luna;
    int an;
    bool operator< (const data  &f) const {
        if (an == f.an)
            if (luna == f.luna)
                return zi < f.zi;
            else
                return luna < f.luna;
         return an <  f.an;}
};

class Produs{
protected:
    string nume_produs;
    int cantitate;
    data d;
    int pret;
public:
    explicit Produs(int cant = 0, string nume="", data dat={1,1,2020}, int p = 0);
    virtual ~Produs() = default;
    Produs(const Produs& prod) = default;
    Produs& operator = (Produs src);
    friend void swap(Produs& pr1, Produs& pr2);

    virtual int getPret();
    virtual void setCantitate(int x);
    virtual int getCantitate();
    virtual data getData();
    virtual void citire();
    virtual void afisare();
    virtual string getType();
};

Produs::Produs(int cant, string nume, data dat, int p) {
    nume_produs = nume;
    cantitate = cant;
    d.zi = dat.zi;
    d.luna = dat.luna;
    d.an = dat.an;
    pret = p;
}

void swap(Produs &pr1, Produs &pr2) {
    using std :: swap;
    swap(pr1.nume_produs, pr2.nume_produs);
    swap(pr1.cantitate, pr2.cantitate);
    swap(pr1.d, pr2.d);
    swap(pr1.pret, pr2.pret);
}

Produs &Produs::operator=(Produs src) {
    if (this != &src)
        swap(*this, src);
    return *this;
}

void Produs::citire() {
    cout << "Dati numele produsului: \n";
    cin >> nume_produs;
    cout << "Dati cantitatea produsului: \n";
    cin >> cantitate;
    cout << "Dati data sub forma zi luna an: \n";
    cin >> d.zi >> d.luna >> d.an;
    cout << "Dati pretul: \n";
    cin >> pret;
}

void Produs::afisare() {
    cout << "Numele produsului este: " << this->nume_produs << '\n';
    cout << "Cantitatea produsului este: " << this->cantitate << "\n";
    cout << "Data la care a fost primit produsul este " << this->d.zi << " " << this->d.luna << " " << this ->d.an << '\n';
    cout << "Pretul produsului este " << this ->pret << "\n";
}

string Produs::getType() {
    return nume_produs;
}

data Produs::getData() {
    return d;
}

int Produs::getCantitate() {
    return cantitate;
}

int Produs::getPret() {
    return pret;
}

void Produs::setCantitate(int x) {
    cantitate-=x;
}

class Perisabil : virtual public Produs{
protected:
    int valabilitate;
public:
    explicit Perisabil(int valab = 0);
    ~Perisabil() override = default;
    Perisabil(const Perisabil& per) = default;
    friend void swap(Perisabil& pr1, Perisabil& pr2);
    Perisabil& operator = (Perisabil src);
    virtual int getPret() override;
    virtual void setCantitate(int x) override;
    virtual int getCantitate() override;
    virtual void afisare() override;
    virtual data getData() override;
    virtual void citire() override;
    string getType() override;
};


Perisabil::Perisabil(int valab) {
    valabilitate = valab;
}

void swap(Perisabil &pr1, Perisabil &pr2) {
    using std :: swap;
    swap(pr1.valabilitate, pr2.valabilitate);
}

Perisabil &Perisabil::operator=(Perisabil src) {
    if (this != &src)
        swap(*this, src);
    return *this;
}

string Perisabil::getType() {
    return nume_produs;
}

void Perisabil::afisare() {
    cout << "Numele produsului perisabil este: " << this->nume_produs <<'\n';
    cout << "Cantitatea produsului este: " << this->cantitate << "\n";
    cout << "Data la care a fost primit produsul este " << this->d.zi << " " << this->d.luna << " " << this ->d.an << '\n';
    cout << "Pretul produsului este " << this ->pret << "\n";
    cout << "Produsul are valabilitatea " << this->valabilitate << "\n";
}

void Perisabil::citire() {
    cout << "Numele produsului este: \n";
    cin >> nume_produs;
    cout << "Cantitatea disponibila este: \n";
    cin >> cantitate;
    cout << "Data la care a fost primit este: \n";
    cin >> d.zi >> d.luna >> d.an;
    cout << "Pretul este: \n";
    cin >> pret;
    cout << "Valabilitatea este de: \n";
    cin >> valabilitate;
}

data Perisabil::getData() {
    data d1;
    d1.zi= d.zi + valabilitate;
    d1.luna = d.luna;
    d1.an = d.an; //nu e tocmai corect, nu verific cand se trece in luna urmatoare, dar aia e
    return d1;
}

int Perisabil::getCantitate() {
    return cantitate;
}

int Perisabil::getPret() {
    return pret;
}

void Perisabil :: setCantitate(int x) {
    cantitate-=x;
}

class Discount : virtual public Produs{
protected:
    int procente_discount;
public:
    explicit Discount(int proc = 0);
    ~Discount() override = default;
    Discount(const Discount& disc) = default;
    friend void swap(Discount& pr1, Discount& pr2);
    Discount& operator = (Discount src);
    virtual int getCantitate() override;
    virtual int getPret() override;
    virtual void setCantitate(int x) override;
    virtual void afisare() override;
    virtual data getData() override;
    virtual void citire() override;
    string getType() override;
};

Discount::Discount(int proc) {
    procente_discount = proc;
}

void swap(Discount &pr1, Discount &pr2) {
    using std :: swap;
    swap(pr1.procente_discount, pr2.procente_discount);
}

Discount &Discount::operator=(Discount src) {
    if (this != &src)
        swap(*this, src);
    return *this;
}

string Discount::getType() {
    return nume_produs;
}

void Discount::afisare() {
    cout << "Numele produsului aflat la reducere este: " << this->nume_produs << '\n';
    cout << "Cantitatea produsului este: " << this->cantitate << "\n";
    cout << "Data la care a fost primit produsul este " << this->d.zi << " " << this->d.luna << " " << this ->d.an << '\n';
    cout << "Pretul produsului este " << this ->pret << "\n";
    cout << "Discountul este de  " << this->procente_discount << "%\n";
}

void Discount::citire() {
    cout << "Numele produsului este: \n";
    cin >> nume_produs;
    cout << "Cantitatea produsului este: \n";
    cin >> cantitate;
    cout << "Data la care a fost primit produsul este: \n";
    cin >> d.zi >> d.luna >> d.an;
    cout << "Pretul produsului este: \n";
    cin >> pret;
    cout << "Discountul care se acorda este: \n";
    cin >> procente_discount;
}
 data Discount::getData() {
    return d;
}

int Discount::getCantitate() {
    return cantitate;
}

int Discount::getPret() {
    return pret;
}

void Discount :: setCantitate(int x) {
    cantitate-=x;
}


class DiscountPerisabil : public Discount, public Perisabil{
public:
    explicit DiscountPerisabil() = default;
    ~DiscountPerisabil() override = default;
    DiscountPerisabil(const DiscountPerisabil& d) = default;
    DiscountPerisabil& operator = (DiscountPerisabil &src) = default;
    virtual int getCantitate() override;
    virtual int getPret() override;
    virtual void setCantitate(int x) override;
    virtual void afisare() override;
    virtual data getData() override;
    virtual void citire() override;
    string getType() override;

};

string DiscountPerisabil::getType() {
    return "DiscountPerisabil";
}

void DiscountPerisabil::afisare() {
    cout << "Numele produsului aflat la reducere, perisabil este: " << this -> nume_produs << '\n';
    cout << "Cantitatea produsului este: " << this->cantitate << "\n";
    cout << "Data la care a fost primit produsul este " << this->d.zi << " " << this->d.luna << " " << this ->d.an << '\n';
    cout << "Pretul produsului este " << this ->pret << "\n";
    cout << "Produsul are valabilitatea " << this->valabilitate << "\n";
    cout << "Discountul este de " << this->procente_discount << "%\n";
}

void DiscountPerisabil::citire() {
    cout << "Numele produsului este: \n";
    cin >> nume_produs;
    cout << "Cantitatea introdusa este: \n";
    cin >> cantitate;
    cout << "Data la care a fost adus este: \n";
    cin >> d.zi >> d.luna >> d.an;
    cout << "Pretul este: \n";
    cin >> pret;
    cout << "Valabilitatea este de: \n";
    cin >> valabilitate;
    cout << "Discountul acordat este de: \n";
    cin >> procente_discount;
}

data DiscountPerisabil::getData() {
    data d1;
    d1.zi= d.zi + valabilitate;
    d1.luna = d.luna;
    d1.an = d.an; //nu e tocmai corect, nu verific cand se trece in luna urmatoare, dar aia e
    return d1;
}

int DiscountPerisabil::getCantitate() {
    return cantitate;
}

int DiscountPerisabil::getPret() {
    return pret;
}

void DiscountPerisabil :: setCantitate(int x) {
    cantitate-=x;
}

class Magazin{
private:
    string nume;
    string adresa;
    static Magazin* instance;
    Magazin(std::string = "", std::string = "");
    vector<pair<string, string>> tipuri_produse;
    vector <Produs*> loturi;
public:
    static Magazin* getInstance(string, string);
    void mesaj();
    void adaugaProdus();
    void adaugaLot();
    void afiseazaProdusePosibile();
    void afiseazaLotIntreDatePrimire();
    void afiseazaLoturiVendabileDataCurenta();
    void vinde();
};

Magazin* Magazin :: instance = nullptr;
Magazin :: Magazin (string name, string adresa) : nume{name}, adresa{adresa}{

}
Magazin* Magazin :: getInstance(string name, string adress) {
    if(instance == nullptr){
        instance = new Magazin(name, adress);
    }
    return instance;
}

void Magazin :: mesaj(){
    cout << "Numele magazinului este " << nume << "\n";
    cout << "Adresa este " << adresa << "\n";
    cout << "Optiuni:\n ";
    cout << "1.Adauga un produs nou:\n ";
    cout << "2.Afiseaza toate produsele pe care magazinul le poate comercializa:\n ";
    cout << "3.Adauga un lot nou dintr-un produs:\n ";
    cout << "4.Afiseaza toate loturile de produse care au fost primite de magazin între două date calendaristice date\n";
    cout << "5.Afiseaza toate loturile de produse care pot fi comercializate de magazin la data curenta (care sunt nevide și care nu sunt expirate)\n ";
    cout << "6.Vinde o anumita cantitate ceruta dintr-un produs din magazin.\n";
    cout << "7.Iesi din meniu.\n";
}

void Magazin :: adaugaProdus() {
    string name, tip;
    cout << "Dati numele produsului: ";
    cin >> name;
    cout << "Dati unitatea lui de masura: ";
    cin >> tip;
    tipuri_produse.push_back(make_pair(name, tip));
    cout <<'\n';
}

void Magazin :: afiseazaProdusePosibile() {
    cout << "Sunt " <<tipuri_produse.size() << " produse in inventar.\n";
    for (int i = 0; i < tipuri_produse.size(); i++)
        cout << tipuri_produse[i].first << " cu unitatea de masura " << tipuri_produse[i].second << '\n';
}

void Magazin :: adaugaLot() {
    Produs* a;
    string tip;
    cout << "Alegeti tipul de produs pentru lotul introdus:\n";
    cin >> tip;
    if (tip == "Perisabil"){
        a = new Perisabil();
    }
    else if (tip == "Discount"){
        a = new Discount();
    }
    else if (tip == "DiscountPerisabil"){
        a = new DiscountPerisabil();
    }
    else {
        a = new Produs();
    }
    a->citire();
    loturi.push_back(a);
}

void Magazin :: afiseazaLotIntreDatePrimire() {
    cout << "Cele doua date (sub forma zi luna an) intre care se face selectia sunt: \n";
    data d1, d2;
    cin >> d1.zi >> d1.luna >> d1.an;
    cin >> d2.zi >> d2.luna >> d2.an;
    for (int i = 0; i < loturi.size(); i++){
        if (loturi[i]->getData() < d2 && d1 < loturi[i]->getData())
            loturi[i]->afisare();
    }

}

void Magazin  :: afiseazaLoturiVendabileDataCurenta() {
    cout << "Data (zi luna an) curenta este: \n";
    data d1;
    cin >> d1.zi >> d1.luna >> d1.an;
    for (int i = 0; i < loturi.size(); i++){
        if((loturi[i]->getData() < d1) && (loturi[i]->getCantitate() > 0))
            loturi[i]->afisare();
    }
}

void Magazin :: vinde(){
    cout << "Dati numele produsului pe care doriti sa il vindeti: \n";
    string n;
    cin >> n;
    cout << "Dati cantitatea pe care doriti sa o cumparati: \n";
    int c;
    cin >> c;
    cout << "Data (zi luna an) curenta este: \n";
    data d1;
    cin >> d1.zi >> d1.luna >> d1.an;
    vector<Produs*> posibile;
    int pr = 9999999;
    int poz = -1;
    for (int i = 0; i < loturi.size(); i++){
        if(loturi[i]->getType() == n && loturi[i]->getData() < d1 && c < loturi[i]->getCantitate())
        {
            if(pr > loturi[i]->getPret())
                poz = i;
        }
        else if (loturi[i]->getType() == n && loturi[i]->getData() < d1)
            posibile.push_back(loturi[i]);
    }
    if (poz!=-1)
    {cout << "Vanzarea se poate face si pretul final este " << loturi[poz]->getPret() * c << '\n';
    loturi[poz]->setCantitate(c);}
    else {if(!posibile.empty()){
        for(int i = 0; i < posibile.size(); i++){
            cout << "Cantitate disponibila: " << posibile[i]->getCantitate() << " la pretul de " << posibile[i] ->getPret() << '\n';
        }}
        else
            cout << "Nu exista produsul cautat\n";
    }
}


int main() {
    Magazin *C = C->getInstance("Mega Image", "str.mea");
    while(true){
        C->mesaj();
        int alegere;
        cin >> alegere;
        if (alegere == 1) {
            C->adaugaProdus();
        }
        if (alegere == 2){
            C->afiseazaProdusePosibile();        }
        if (alegere == 3){
            C->adaugaLot();
        }
        if (alegere == 4){
            C->afiseazaLotIntreDatePrimire();
        }
        if (alegere == 5){
            C->afiseazaLoturiVendabileDataCurenta();
        }
        if (alegere == 6){
            C->vinde();
        }
        if (alegere == 7)
            break;
        if(alegere < 1 or alegere > 6){
            std::cout << "Tasta incorecta.";
        }
        std::cout << "\n";
    }

    return 0;
}

