#ifndef INTERFEJS_HH
#define INTERFEJS_HH
#define DRONE_MOVEMENT_FREQUENCY 0.01
#define DRONE_ROTATION_FREQUENCY 0.01
#define PROPELLER_DRONE_LENGTH_RATIO 2
#define PROPELLER_DEGREE_PER_UNIT 90
#define PROPELLER_BASE_EDGE 1
/*!
 * \file
 * \brief Definicja klasy abstrakcyjnej Interfejs
 *
 * Plik zawiera definicje klasy abstrakcyjnej Interfejs,
 * oraz deklaracje wirtualnych metod tej klasy.
 */
#include "Wek.hh"
/*!
* \brief Model pojęcia interfejsu drona
*
* Klasa abstrakcyjna modeluje pojęcie 
* interfejsu sterującego dronem.
*/
class Interfejs{
    public:
    /*!
    * \brief Metoda przesuwająca drona
    * 
    * Zmienia położenie drona w przód
    * o wybraną odległość. Ruch drona jest animowany. \n
    * \param[in] odl - odległość o jaką dron ma się przesunąć
    */
    virtual void ruch_drona(double odl)=0;
    /*!
    * \brief Metoda obracająca drona
    * 
    * Zmienia macierz orientacji drona o wybrany kat
    * (W osi z). Obrót jest animowany. \n
    * \param[in] kat - wartość kąta, o który ma zostać obrócony dron
    */
    virtual void obrot_drona(double kat_obr)=0;
    /*!
    * \brief Metoda ruszająca dronem w osi z
    * 
    * Zmienia położenie drona w osi z
    * o wybraną wartość. Ruch jest animowany. \n
    * \param[in] odl - odleglosc o jaka ma sie wzniesc/opasc dron
    */
    virtual void wznies_opusc_drona(double odl)=0;
    /*!
    * \brief Metoda zwracająca środek drona
    * 
    * Metoda zwraca współrzędne środka 
    * drona*/
    virtual const Wektor<double,3> & zwroc_srodek()const=0 ;
    virtual double zwroc_promien_drona()const=0 ;
};
#endif