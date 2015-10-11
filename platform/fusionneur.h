#ifndef FUSIONNEUR_H
#define FUSIONNEUR_H

#include <vector>

class Fusionneur
{
public:
    Fusionneur(){}
    std::vector<std::string> sources;
    std::string destination;
    void addSource(std::string source){this->sources.push_back(source);}
    void setDestination(std::string destination){this->destination=destination;}
    const std::vector<std::string> getSources(){return this->sources;}
    std::string getDestination(){return this->destination;}
};

#endif // FUSIONNEUR_H
