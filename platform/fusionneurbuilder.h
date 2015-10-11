#ifndef FUSIONNEURBUILDER_H
#define FUSIONNEURBUILDER_H

#include "fusionneur.h"

class FusionneurBuilder
{
public:
    FusionneurBuilder(){}
    Fusionneur getFusionneur()
    {
            Fusionneur f;
            f.addSource("french.pgn");
            f.addSource("east_indian.pgn");
            f.addSource("grunfeld.pgn");
            f.setDestination("openings.pgn");

            return f;
    }
};

#endif // FUSIONNEURBUILDER_H
