#ifndef INTERVAL_H
#define INTERVAL_H

#include "Datum.h"

class Interval {
public:
    Datum pocetak;
    Datum kraj;

    Interval(Datum p, Datum k);

    int duljina() const;
};

#endif
