#include <bits/stdc++.h>
using namespace std;
class Pacient{
protected:
    string nume;
    string prenume;
    int varsta;
    string adresa;
    double colesterol;
    double tensiune;
    string datacolesterol;
    string datatensiune;
public:
    explicit Pacient(string lname = "", string fname = "", int v = 0, string adr="", double col = 0.0, double tens = 0.0, string dc="", string dt="");
    virtual ~Pacient() = default;
    Pacient(const Pacient& pc) = default;
    Pacient& operator=(const Pacient &pc);

    virtual void citire() = 0;
    virtual void afisare() = 0;
    virtual string getType() = 0;
    virtual string getRisc() = 0;
    virtual string getNume() = 0;

};

Pacient :: Pacient(string lname, string fname, int v, string adr, double col, double tens, string dc, string dt) {
    nume = lname;
    prenume = fname;
    varsta = v;
    adresa = adr;
    colesterol = col;
    tensiune = tens;
    datacolesterol = dc;
    datatensiune = dt;
}

Pacient &Pacient::operator=(const Pacient &pc) {
    if (this == &pc)
        return *this;
    else {
        nume = pc.nume;
        prenume = pc.prenume;
        varsta = pc.varsta;
        adresa = pc.adresa;
        colesterol = pc.colesterol;
        tensiune = pc.tensiune;
        datacolesterol = pc.datacolesterol;
        datatensiune = pc.datatensiune;
        return *this;
    }
}

class PacientPeste40 : public Pacient{
protected:
    string fumator;
    string sedentarism;
public:
    explicit PacientPeste40(string lname = "", string fname = "", int v = 0, string adr="", double col = 0.0, double tens = 0.0, string dc="", string dt="", string f="", string sed="");
    virtual ~PacientPeste40() override = default;
    PacientPeste40(const PacientPeste40& pc) = default;
    PacientPeste40& operator=(const PacientPeste40& pc);
    virtual void citire() override;
    virtual void afisare() override;
    virtual string getType() override;
    virtual string getNume() override;
    virtual string getRisc() override;
};

string PacientPeste40 :: getType() {
    return "PacientPeste40";
}

string PacientPeste40 :: getNume(){
    return nume;
}

string PacientPeste40 :: getRisc(){
    int ok = 0;
    if (sedentarism == "ridicat") ok++;
    if (fumator == "fumator") ok++;
    if(colesterol > 240.0) ok++;
    if(tensiune > 139) ok++;
    if(ok== 1)
        return "DA";
    if (ok >= 2)
        return "RIDICAT";
    if (ok == 0)
        return "NU";
}

PacientPeste40::PacientPeste40(string lname, string fname, int v, string adr, double col, double tens, string dc,
                               string dt, string f, string sed) {
    nume = lname;
    prenume = fname;
    varsta = v;
    adresa = adr;
    colesterol = col;
    tensiune = tens;
    datacolesterol = dc;
    datatensiune = dt;
    fumator = f;
    sedentarism = sed;
}

PacientPeste40 &PacientPeste40::operator=(const PacientPeste40 &pc) {
    if(&pc == this) return *this;
    Pacient::operator=(pc);
    this->fumator = pc.fumator;
    this->sedentarism = pc.sedentarism;
    return *this;
}

void PacientPeste40 :: citire(){
    cout << "Dati numele pacientului: \n";
    cin >> nume;
    cout << "Dati prenumele pacientului: \n";
    cin >> prenume;
    cout << "Dati varsta pacientului: \n";
    cin >> varsta;
    cout << "Dati valoare colesterol pacient: \n";
    cin >> colesterol;
    cout << "Dati data la care a fost efectuata analiza de colesterol: \n";
    cin >> datacolesterol;
    cout << "Dati valoarea tensiunii: \n";
    cin >> tensiune;
    cout << "Dati data la care a fost efectuata analiza de colesterol: \n";
    cin >> datatensiune;
    cout << "Pacientul este fumator? \n";
    cin >> fumator;
    cout << "Care este gradul de sedentarism al fumatorului? \n";
    cin >> sedentarism;
}

void PacientPeste40 :: afisare(){
    cout << "Numele si prenumele pacientului: " + nume + " " + prenume+'\n';
    cout << "Varsta pacientului: " << varsta << " ani\n";
    cout << "Valoarea colesterolului: " << colesterol << " efectuata la data de " << datacolesterol << '\n';
    cout << "Valoarea tensiunii: " << tensiune << " efectuata la data de " <<datatensiune <<'\n';
    if (fumator == "fumator")
        cout << "Pacientul este fumator.\n";
    else
        cout << "Pacientul nu este fumator.\n";
    cout << "Gradul de sedentarism este: " << sedentarism << '\n';
}

class PacientSub40 : public Pacient{
public:
    explicit PacientSub40(string lname = "", string fname = "", int v = 0, string adr="", double col = 0.0, double tens = 0.0, string dc="", string dt="");
    ~PacientSub40() override = default;
    PacientSub40(const PacientSub40& pc) = default;
    PacientSub40& operator=(const PacientSub40 &pc);

    void afisare() override;
    void citire() override;
    string getType() override;
    string getNume() override;
    string getRisc() override;

};

PacientSub40::PacientSub40(string lname, string fname, int v, string adr, double col, double tens, string dc, string dt)
        : Pacient(lname, fname, v, adr, col, tens, dc, dt) {

}

PacientSub40& PacientSub40::operator=(const PacientSub40& pc) {
    if(&pc == this) return *this;
    Pacient :: operator=(pc);
    return *this;
}

void PacientSub40 :: afisare(){
    cout << "Numele si prenumele pacientului: " + nume + " " + prenume+'\n';
    cout << "Varsta pacientului: " << varsta << " ani\n";
    cout << "Valoarea colesterolului: " << colesterol << " efectuata la data de " << datacolesterol << '\n';
    cout << "Valoarea tensiunii: " << tensiune << " efectuata la data de " <<datatensiune <<'\n';
}

void PacientSub40 :: citire(){
    cout << "Dati numele pacientului: \n";
    cin >> nume;
    cout << "Dati prenumele pacientului: \n";
    cin >> prenume;
    cout << "Dati varsta pacientului: \n";
    cin >> varsta;
    cout << "Dati valoare colesterol pacient: \n";
    cin >> colesterol;
    cout << "Dati data la care a fost efectuata analiza de colesterol: \n";
    cin >> datacolesterol;
    cout << "Dati valoarea tensiunii: \n";
    cin >> tensiune;
    cout << "Dati data la care a fost efectuata analiza de colesterol: \n";
    cin >> datatensiune;
}

string PacientSub40::getType() {
    return "PacientSub40";
}

string PacientSub40 :: getNume() {
    return  nume;
}

string PacientSub40 :: getRisc() {
    int ok = 0;
    if(colesterol > 240.0) ok++;
    if(tensiune > 139) ok++;
    if(ok== 1)
        return "DA";
    if (ok >= 2)
        return "RIDICAT";
    if (ok == 0)
        return "NU";
}
class Copil : public Pacient{
protected:
    string precedentMama;
    string precedentTata;
    string numeMama;
    string numeTata;
    string dataProteinaC;
    double proteinaC;
public:
    explicit Copil(string lname = "", string fname = "", int v = 0, string adr="", double col = 0.0, double tens = 0.0, string dc="", string dt="", string pm="", string pt="", string nm="", string nt="", string dp="", double pr=0.0);
    virtual ~Copil() override= default;
    Copil(const Copil& c) = default;
    Copil& operator=(const Copil& c);

    virtual void afisare() override;
    virtual void citire() override;
    virtual string getType() override;
    virtual string getNume() override;
    virtual string getRisc() override;

};

string Copil :: getType() {
    return "Copil";
}

string Copil :: getNume(){
    return nume;
}

string Copil :: getRisc(){
    int ok = 0;
    if(proteinaC > 0.60) ok++;
    if(colesterol > 240.0) ok++;
    if(tensiune > 139) ok++;
    if (precedentMama=="DA") ok++;
    if(precedentTata == "DA") ok++;
    if(ok== 1)
        return "DA";
    if (ok >= 2)
        return "RIDICAT";
    if (ok == 0)
        return "NU";
}
Copil::Copil(string lname, string fname, int v, string adr, double col, double tens, string dc, string dt, string pm,
             string pt, string nm, string nt, string dp, double pr) {
    nume = lname;
    prenume = fname;
    varsta = v;
    adresa = adr;
    colesterol = col;
    tensiune = tens;
    datacolesterol = dc;
    datatensiune = dt;
    precedentMama = pm;
    precedentTata = pt;
    numeMama = nm;
    numeTata = nt;
    dataProteinaC = dp;
    proteinaC = pr;
}

Copil &Copil::operator=(const Copil& c) {
    if (this == &c)
        return *this;
    Pacient :: operator=(c);
    precedentMama = c.precedentMama;
    precedentTata = c.precedentTata;
    numeMama = c.numeMama;
    numeTata = c.numeTata;
    dataProteinaC = c.dataProteinaC;
    proteinaC = c.proteinaC;
    return *this;

}

void Copil::afisare() {
    cout << "Numele si prenumele pacientului: " + nume + " " + prenume+'\n';
    cout << "Varsta pacientului: " << varsta << " ani\n";
    cout << "Valoarea colesterolului: " << colesterol << " efectuata la data de " << datacolesterol << '\n';
    cout << "Valoarea tensiunii: " << tensiune << " efectuata la data de " <<datatensiune <<'\n';
    cout << "Numele mamei este: " << numeMama << " si aceasta are val. precedentului: " << precedentMama << '\n';
    cout << "Numele tatalui este: " << numeTata << " si aceasta are val. precedentului: " << precedentTata << '\n';
    cout << "Valoarea proteinei C este: " << proteinaC << " si aceasta a fost efectuata la data de: " << dataProteinaC;
}

void Copil::citire() {
    cout << "Dati numele pacientului: \n";
    cin >> nume;
    cout << "Dati prenumele pacientului: \n";
    cin >> prenume;
    cout << "Dati varsta pacientului: \n";
    cin >> varsta;
    cout << "Dati valoare colesterol pacient: \n";
    cin >> colesterol;
    cout << "Dati data la care a fost efectuata analiza de colesterol: \n";
    cin >> datacolesterol;
    cout << "Dati valoarea tensiunii: \n";
    cin >> tensiune;
    cout << "Dati data la care a fost efectuata analiza de colesterol: \n";
    cin >> datatensiune;
    cout << "Dati numele mamei: \n";
    cin >> numeMama;
    cout << "Dati val. precedentului mamei: \n";
    cin >> precedentMama;
    cout << "Dati numele tatalui: \n";
    cin >> numeTata;
    cout << "Dati precedentul tatalui: \n";
    cin >>  precedentTata;
    cout << "Dati valoarea proteinei C: \n";
    cin >> proteinaC;
    cout << "Dati data proteinei C: \n";
    cin >> dataProteinaC;
}

class Cabinet{
    string numeMedic;
    string adresa;
    static Cabinet* instance;
    explicit Cabinet(std::string = "", std::string = "");
    vector<Pacient*> pacienti;
public:
    static Cabinet* getInstance(string, string);
    void mesaj();
    void adaugaPacient();
    void afiseazaTotiPacientii();
    void afiseazaPacientiNumeFamilieDat(string n);
    void afiseazaAdultiRiscRidicat();
    void afiseazaCopiiRisc();
};

Cabinet* Cabinet :: instance = nullptr;
Cabinet :: Cabinet (string name, string adresa) : numeMedic{name}, adresa{adresa}{

}
Cabinet* Cabinet :: getInstance(string name, string adress) {
    if(instance == nullptr){
        instance = new Cabinet(name, adress);
    }
    return instance;
}

void Cabinet :: mesaj(){
    cout << "Numele doctorului: " << numeMedic << "\n";
    cout << "Adresa cabinetului: " << adresa << '\n';
    cout << "Optiuni:\n";
    cout << "1.Afiseaza toti pacientii:\n";
    cout << "2.Afiseaza adultii cu risc cardiovasculaar ridicat:\n";
    cout << "3.Afiseaza copiii cu risc cardiovascular: \n";
    cout << "4.Afiseaza toti pacientii cu numele de familie dat: \n";
    cout << "5.Adauga pacient: \n";
    cout << "6.Iesi din program: \n";
}

void Cabinet :: adaugaPacient(){
    Pacient* a;
    string tip;
    cout << "Alegeti tipul de pacient introdus:\n";
    cin >> tip;
    if (tip == "Copil"){
    a = new Copil();
    }
    else if (tip == "Adult"){
    a = new PacientSub40();
    }
    else if (tip == "Adultpeste40"){
    a = new PacientPeste40();
    }

a->citire();
pacienti.push_back(a);}

void Cabinet :: afiseazaTotiPacientii() {
    for (unsigned int i = 0; i < pacienti.size(); i++) {
        if (pacienti[i]->getType() == "Adult") {
            pacienti[i]->afisare();
        }
    }
    std::cout << "Adulti peste 40 ani:\n";
    for (unsigned int i = 0; i < pacienti.size(); i++) {
        if (pacienti[i]->getType() == "Adultpeste40") {
            pacienti[i]->afisare();
        }
    }
    std::cout << "Copii:\n";
    for (unsigned int i = 0; i < pacienti.size(); i++) {
        if (pacienti[i]->getType() == "Copil") {
            pacienti[i]->afisare();
        }
    }
}
void Cabinet::afiseazaPacientiNumeFamilieDat(string n) {
    for(unsigned int i = 0; i < pacienti.size(); i++){
        if(pacienti[i]->getType() == "Adult" and pacienti[i]->getNume() == n){
            pacienti[i]->afisare();
        }
    }
    std::cout << "Adulti peste 40 ani:\n";
    for(unsigned int i = 0; i < pacienti.size(); i++){
        if(pacienti[i]->getType() == "Adult" and pacienti[i]->getNume() == n){
            pacienti[i]->afisare();
        }
    }
    std::cout << "Copii:\n";
    for(unsigned int i = 0; i < pacienti.size(); i++){
        if(pacienti[i]->getType() == "Copil" and pacienti[i]->getNume() == n){
            pacienti[i]->afisare();
        }
    }
}

void Cabinet::afiseazaAdultiRiscRidicat() {
    cout << "Adultii cu risc ridicat sunt: \n";
    for(int i = 0; i < pacienti.size(); i++)
        if(pacienti[i]->getType()!="Copil" && pacienti[i]->getRisc()=="RIDICAT")
            pacienti[i]->afisare();
}

void Cabinet::afiseazaCopiiRisc() {
    cout << "Copiii cu risc sunt: \n";
    for(int i = 0; i < pacienti.size(); i++)
        if(pacienti[i]->getType()=="Copil" && pacienti[i]->getRisc()!="NU")
                    pacienti[i]->afisare();
}


int main() {
    Cabinet *C = C->getInstance("dr. Merchea", "str.mea");
    while(true){
        C->mesaj();
        int alegere;
        cin >> alegere;
        if (alegere == 5) {
            C->adaugaPacient();
        }
        if (alegere == 1){
            C->afiseazaTotiPacientii();        }
        if (alegere == 4){
            string num;
            cout << "Ce nume cauti? \n";
            cin >> num;
            C->afiseazaPacientiNumeFamilieDat(num);
        }
        if (alegere == 2){
            C->afiseazaAdultiRiscRidicat();
        }
        if(alegere == 3){
            C->afiseazaCopiiRisc();
        }
        if (alegere == 6)
            break;
        if(alegere < 1 or alegere > 6){
            std::cout << "Tasta incorecta.";
        }
        std::cout << "\n";
    }
    return 0;
}
