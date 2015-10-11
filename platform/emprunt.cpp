#include "emprunt.h"

Emprunt::Emprunt()
{

}

 /*void Emprunt::build()
 {

     for(int i = 1; i <= this->mois; i++)
    {
        Flux flx(i;this->mensualité;)
        this->echeancier[i]=flx;
     }

     for(std::map<int,Flux>::iterator it=this->echeancier.begin(); it!=this->echeancier.end();it++)
     {
        it->second.compute();
        this->totalNF += it->second.NFValue;
        this->total += it->second.DiscountedValue;
     }

     this->cout = this->total - this->totalNF;
 }*/

/*void Emprunt::display(std::stringstream & output)
{

    output << "Calcul du pret de " << this->mois << " mois et de taux " << this->taux*100 << "%" << std::endl;
    output << echeancier << std::endl;
    outputs << "mois;NFValue;DiscountedValue" << std::endl;
    for(std::map<int,Flux>::iterator it = this->echeancier.begin(); it!=this->echeancier.end();it++)
    {
        Flux flx = it->second;
        output << it->first << ";" << flx.NFValue << ";" << flx.DiscountedValue;
    }

    output << "value=" << this->total << std::endl;
    output << "NFvalue=" << this->totalNF << std::endl;
    output << "cout=" << this->cout << std::endl;
}*/

