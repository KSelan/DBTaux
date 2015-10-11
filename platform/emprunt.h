#ifndef EMPRUNT_H
#define EMPRUNT_H

#include <map>

#include "flux.h"
#include <sstream>

class Emprunt
{
public:
    Emprunt();

    int mois;
    double montant;
    double taux;
    double mensualité;
    double totalNF;
    double total;
    double cout;

    std::map<int,Flux> echeancier;
    std::map<int,Flux> anticipés;
    std::map<int,Flux> echeancier2;

    void build()
    {
        for(int i = 1; i <= this->mois; i++)
        {
           Flux flx(i,this->mensualité);
           this->echeancier.insert(std::pair<int,Flux>(i,flx));
        }

        for(int i = 1; i <= this->mois; i++)
        {
           Flux flx(i,this->montant/this->mois);
           this->echeancier2.insert(std::pair<int,Flux>(i,flx));
        }

        volatile double capital = 0;

        for(std::map<int,Flux>::iterator it=this->echeancier.begin(); it!=this->echeancier.end();it++)
        {
           it->second.discount(this->taux);

           Flux & fl = it->second;
           fl.discount(this->taux);
           this->totalNF += fl.NFValue;
           this->total += fl.DiscountedValue;
           capital += fl.DiscountedValue;
           fl.capital += capital;
        }

        for(std::map<int,Flux>::iterator it=this->echeancier2.begin(); it!=this->echeancier2.end();it++)
        {
           it->second.financer(this->taux);

           Flux fl = it->second;
           fl.financer(this->taux);
           this->totalNF += fl.NFValue;
           this->total += fl.DiscountedValue;
        }

        this->cout = this->totalNF - this->total;
    }

    void display(std::stringstream & output)
    {

        output << "Calcul du pret de " << this->mois << " mois et de taux " << this->taux*100 << "%" << std::endl;
        output << "echeancier" << std::endl;
        output << "mois;NFValue;DiscountedValue;capital remboursé" << std::endl;
        for(std::map<int,Flux>::iterator it = this->echeancier.begin(); it!=this->echeancier.end();it++)
        {
            Flux & flx = it->second;
            output << it->first << ";" << flx.NFValue << ";" << flx.DiscountedValue <<";" << flx.capital << std::endl;
        }

        output << "value=" << this->total << std::endl;
        output << "NFvalue=" << this->totalNF << std::endl;
        output << "cout=" << this->cout << std::endl;
        output << "capital Remboursé=" << std::endl;

        output << "****************************************" << std::endl;
        double initValue = 0;
        double financedValue = 0;
        for(std::map<int,Flux>::iterator it = this->echeancier2.begin(); it!=this->echeancier2.end();it++)
        {
            Flux flx = it->second;
            initValue += flx.NFValue;
            financedValue += flx.DiscountedValue;
            output << it->first << ";" << flx.NFValue << ";" << flx.DiscountedValue << std::endl;
        }
         output << "cout=" << financedValue - initValue << std::endl;

         output << "****************************************" << std::endl;
         output << "cout =" << this->mensualité*this->mois - this->montant << std::endl;
    }
};

#endif // EMPRUNT_H
