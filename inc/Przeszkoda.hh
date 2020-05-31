#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
/*!
* \brief Definicja klasy abstrakcyjnej Przeszkoda
 *
 * Plik zawiera definicje klasy abstrakcyjnej Przeszkoda,
 * oraz deklaracje wirtualnych metod tej klasy.*/
#include <memory>
#include "Interfejs.hh"
/*!
* \brief Model pojęcia przeszkody
*
* Klasa abstrakcyjna modeluje ogólne pojęcie 
* przeszkody
*/
class Przeszkoda {
public:
    /*!
    * \brief Metoda wykrywająca kolizje
    * 
    * Metoda wykrywa czy nastąpiła kolizja drona
    * z przeszkodą \n
    * \param[in] drone - wskaźnik na interfejs drona dla którego będzie sprawdzana kolizja
    * \retval true - jeśli nastąpiła kolizja
    * \retval false - w przeciwnym wypadku
    */
virtual bool czy_kolizja(std::shared_ptr<Interfejs> drone) const = 0;
};
#endif