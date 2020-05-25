#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
#include <memory>
#include "Interfejs.hh"
class Przeszkoda {
public:
virtual bool czy_kolizja(std::shared_ptr<Interfejs> drone) const = 0;
};
#endif