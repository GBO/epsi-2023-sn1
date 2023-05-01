#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Objet{
protected:
    string nom;

public:
    Objet(string nom){
        this->nom = nom;
    }

    void afficher_nom(){
        cout << this->nom << endl;
    }
};

class Arme: public Objet{
protected:
    int stat_arme_phys;
    int stat_arme_mage;

public:
    Arme(string nom, int phys,int mage ): Objet(nom){
        this->stat_arme_phys=phys;
        this->stat_arme_mage = mage;
    }

    void afficher_stat(){
        cout << this->stat_arme_phys << endl;
        cout << this->stat_arme_mage << endl;
    }

    int getarme_phys(){ return this->stat_arme_phys;}
    int getarme_mage(){ return this->stat_arme_mage;}

};

class Main : public Arme{
public:
    Main() : Arme("Main",0,0){}
};
class Epee: public Arme{
public:
    Epee() : Arme("Epee",10,0){}
};
class Baton : public Arme{
public:
    Baton() : Arme("Baton",0,500){}
};
class Dague : public Arme{
public:
    Dague() : Arme("Dague",0,500){}
};
class Bouclier : public Arme{
public:
    Bouclier() : Arme("Bouclier",100,100){}
};

class Armure: public Objet{
protected:
    int stat_armure_phys;
    int stat_armure_mage;
public:
    Armure(string nom, int physiq,int magic): Objet(nom){
        this ->stat_armure_phys = physiq;
        this->stat_armure_mage = magic;
    }

    void afficher_stat(){
        cout << this->stat_armure_phys<<endl;
        cout << this->stat_armure_mage<<endl;
    }

    int getarmure_phys(){ return this->stat_armure_phys;}
    int getarmure_mage(){ return this->stat_armure_mage;}
};

class Veste: public Armure{
public:
    Veste() : Armure("Veste",0,0){}
};
class Cotemaille: public Armure{
public:
    Cotemaille() : Armure("CoteMaille", 100, 0){}
};
class Robe: public Armure{
public:
    Robe() : Armure("Robe", 50, 100){}
};
class Capuche: public Armure{
public:
    Capuche() : Armure("Capuche", 20, 10){}
};
class Blindage: public Armure{
public:
    Blindage() : Armure("Blindage", 200, 0){}
};

class Potion: public Objet{
protected:
    int soin;
    int stat_potion_phys;
    int stat_potion_mage;

public:
    Potion(string nom, int vie, int fis, int magique): Objet(nom){
        this->soin = vie;
        this->stat_potion_phys = fis;
        this->stat_potion_mage = magique;

    }

    void get_nom(){
        cout << this->nom;
    }

    void afficher_potion(){

        cout << this->soin << endl;
        cout << this->stat_potion_phys << endl;
        cout << this->stat_potion_mage << endl;

    }

    int get_soin(){
        return this->soin;
    }

    int get_ad(){
        return this->stat_potion_phys;
    }

    int get_ap(){
        return this->stat_potion_mage;
    }

};

class Elixir: public Potion{
public:
    Elixir() : Potion("Elixir", 50, 10, 0){}
};
class Bleuvage: public Potion{
public:
    Bleuvage() : Potion("Bleuvage", 100, 50, 10){}
};
class Gourde_du_brave: public Potion{
public:
    Gourde_du_brave() : Potion("Gourde du brave", 50, 10, 0){}
};
class Gemme: public Potion{
public:
    Gemme() : Potion("Gemme", 30, 0, 100){}
};


class Personnage {
protected:
    string nom;
    int pv;
    int attack_phys;
    int attack_mag;
    int armure_phys;
    int armure_mag;
    int point_pouvoir;
    int vitesse;
    Armure* armure;
    Arme* arme;
public:
    Personnage(string n, int pv, int att_p, int att_m, int arm_p, int arm_m, int pp, int v ){
        this->nom = n;
        this->pv = pv;
        this->attack_phys = att_p;
        this->attack_mag = att_m;
        this->armure_phys = arm_p;
        this->armure_mag = arm_m;
        this->point_pouvoir = pp;
        this->vitesse = v;
        this->armure = new Veste();
        this->arme = new Main();
    }

    void boire(Potion* p){
        this->set_pv(p->get_soin());
        this->set_attack_pysh(p->get_ad());
        this->set_attack_magic(p->get_ap());
    }

    void set_pv(int pvbonus){
        this->pv += pvbonus;
    }

    void set_pp(int pp){
        this->point_pouvoir += pp;
    }

    void set_attack_pysh(int ad){
        this->attack_phys += ad;
    }

    void set_attack_magic(int ap){
        this->attack_mag += ap;
    }

    void set_arme(Arme* a){
        this->arme = a;
    }
    void set_armure(Armure* a){
        this->armure = a;
    }

    string get_nom(){
        return this->nom;
    }

    int get_pv(){
        return this->pv;
    }

    void get_arme(){
        this->arme->afficher_stat();
    }

    void get_armure(){
        this->armure->afficher_stat();
    }

    int get_vitesse(){
        return this->vitesse;
    }

    void afficher(){
        cout << this->nom + "/" + to_string(this->pv) + "/" + to_string(this->attack_phys) + "/" +
                to_string( this->attack_mag) + "/" + to_string(armure_phys)+ "/" +
                to_string(armure_mag) + "/" + to_string(point_pouvoir) + "/" + to_string(vitesse);
    }

    void attaquer(Personnage &adversaire){
        int degats = this->attack_phys + this->arme->getarme_phys();
        cout << this->get_nom();
        cout << " donne un coup a ";
        cout << adversaire.get_nom();
        adversaire.subir(degats);
    }

    void subir(int degats){
        int d = degats * ((100.0 - this->armure_phys + this->armure->getarmure_phys()) / 100.0);
        cout << ": " + to_string(d) + " degats et reste ";
        this->pv -= d;
        cout << this->get_pv() << endl;
    }

    void subirsort(int degats){
        int d = degats * ((100.0 - this->armure_mag + this->armure->getarmure_mage()) / 100.0);
        cout << ": " + to_string(d) + "degats";
        this->pv -= d;
    }
};

class Chevalier : public Personnage{
public:
    Chevalier() : Personnage("Chevalier",50,25,5,10,10,5,10){
        set_armure(new Cotemaille());
        set_arme(new Epee());
    }
};
class Mage : public Personnage{
public:
    Mage() : Personnage("Mage",25,5,25,5,5,50,10){
        set_armure(new Robe());
        set_arme(new Baton());
    }

    void sortigel(Mage &adversaire){
        int degats = this->attack_mag + this->arme->getarme_mage();
        this->afficher();
        cout << "lance une orbe";
        adversaire.afficher();
        adversaire.subirsort(degats);
    }

};
class Tank : public Personnage{
public:
    Tank() : Personnage("Tank",100,20,0,25,25,5,5){
        set_armure(new Blindage());
        set_arme(new Bouclier());
    }
};
class Assasins : public Personnage{
public:
    Assasins() : Personnage("Assasins",20,40,10,1,1,10,20){
        set_armure(new Capuche());
        set_arme(new Dague());
    }
};

class Roi_squelette : public Personnage{
public:
    Roi_squelette() : Personnage("Roi squellete", 100, 30, 30 ,50,50,50,10){}
};
class Squellette : public Personnage{
public:
    Squellette() : Personnage("Squellette",10,10,10,10,10,10,10){}
};


class Inventaire {
private:
    vector<Potion*> potion;
public:
    void addinventaire(Potion* a){
        this->potion.push_back(a);
    }

    int get_inventaire(){
        return this->potion.size();
    }

    void nom_potion(int emplacement){
        potion[emplacement]->get_nom();
    }

    void envoyé_potion(Personnage* p , int emplacement){
        p->boire(this->potion[emplacement]);
        this->potion.erase(this->potion.begin() + emplacement, this->potion.begin() + emplacement +1);
    }

};

class Combat{
private:
    vector<Personnage*> Combatants;
    vector<Personnage*> kos;
    vector<Personnage*> Montres;
    Inventaire* inventaire;
public:
    Combat(vector<Personnage*> genti,vector<Personnage*> mechant, Inventaire* inventaire){
        this->Combatants = genti;
        this->Montres = mechant;
        this->inventaire = inventaire;
    }

    void baston(){
        int tour = 1;
        while (this->Montres.size() > 0 && this->Combatants.size() > 0){
            this->round(tour++);
        }
        if(this->Combatants.size() > 0) {
            cout << "Victoire";
        }else{
            cout << "Defaite";
        }
    };

    int round(int tour){
        cout << "Tour :" << tour << endl;
        bool use = false;
        unsigned int i = 0;
        unsigned int x = 0;
        string option;
        int vise = -1;
        vector<Personnage*> choix;
        while (i < this->Combatants.size()){
            cout << "C'est a " << this->Combatants[i]->get_nom() << " d'attaquer!" << endl;
            if (inventaire->get_inventaire() > 0){
                cout << "Voulez-vous utilisez votre inventaire? [O/N]" << endl;
                cin >> option;
                int potion;
                if (option == "O"){
                    for (int y=0; y < inventaire->get_inventaire(); y++){
                        cout << y << " : " ;
                        inventaire->nom_potion(y);
                        cout << endl;
                    }
                    cout << inventaire->get_inventaire() << " : Ne pas utiliser de potion et attaquer" << endl;
                    cout << "Quel potion voulez-vous utiliser ?" << endl;
                    cin >> potion;
                    while (potion < 0 || potion > inventaire->get_inventaire()+2){
                        cout << "Rentrez une valeur acceptable : " << endl;
                        cin >> potion;
                    }
                    if ( potion != inventaire->get_inventaire()){
                        use = true;
                    }
                    if (use == true){
                        inventaire->envoyé_potion(this->Combatants[i], potion);
                        i++;
                    }
                }
            }
            if (use == false){

                cout << "Que voulez vous faire : " << endl;
                while (x < this->Montres.size()){
                    cout << x << " : " << this->Montres[x]->get_nom() << endl;
                    x++;
                }
                x = 0;
                cout << "Qui voulez vous attaquez ?" << endl;
                cin >> vise;
                if (vise < 0 || vise >= this->Montres.size()){
                    cout << "Selectioner un monstre" << endl;
                    cin >> vise;
                }
                choix.push_back(this->Combatants[i]);
                choix.push_back(this->Montres[vise]);
                i++;
            }
        }
        i = 0;
        while (i < this->Montres.size()){
            choix.push_back(this->Montres[i]);
            choix.push_back(this->Combatants[rand() % this->Combatants.size()]);
            i++;
        }

        cout << "C'est partie pour la castagne" << endl;
        for (i=0; i<choix.size();i+=2){
            choix[i]->attaquer(*choix[i+1]);
        }
        for (i=0; i < this->Combatants.size();i++){
            if (this->Combatants[i]->get_pv() <= 0){
                cout << "Le " << this->Combatants[i]->get_nom() << " a trop subit de coup il tombe a terre et ne peut plus rien faire" << endl;
                this->kos.push_back(this->Combatants[i]);
                this->Combatants.erase(this->Combatants.begin() + i,this->Combatants.begin() + i +1);
            }
        }
        for (i=0; i < this->Montres.size();i++){
            if (this->Montres[i]->get_pv() <= 0){
                cout << "Le " << this->Montres[i]->get_nom() << " a trop subit de coup il tombe a terre et ne peut plus rien faire" << endl;
                this->kos.push_back(this->Montres[i]);
                this->Montres.erase(this->Montres.begin() + i,this->Montres.begin() + i +1);
            }
        }
    }
};



int main() {
    Personnage* c = new Chevalier();
    Personnage* a = new Assasins();
    Personnage* s1 = new Roi_squelette();
    Personnage* s2 = new Squellette();
    Inventaire* inventaire = new Inventaire();
    for (int y=0;y < 2; y++){
        inventaire->addinventaire(new Bleuvage());
    }
    for (int y=0;y < 2; y++){
        inventaire->addinventaire(new Gourde_du_brave());
    }
    c->boire(new Gourde_du_brave);
    vector<Personnage *> genti;
    genti.push_back(c);
    genti.push_back(a);
    vector<Personnage *> mechant;
    mechant.push_back(s1);
    Combat *combat = new Combat(genti,mechant,inventaire);
    combat->baston();




}