#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH
/*!
 * \file
 * \brief Definicja klasy abstrakcyjnej Plaszczyzna
 *
 * Plik zawiera definicje klasy abstrakcyjnej Plaszczyzna,
 * oraz deklaracje wirtualnych metod tej klasy.
 */
#include "Obiekt3D.hh"
#include "Przeszkoda.hh"
#include "Interfejs.hh"
/*!
* \brief Model pojęcia Płaszczyzna
*
* Klasa modeluje pojęcie płaszczyzny
* dziedzicząc publicznie po klasie Obiekt3D.
*/
class Plaszczyzna:public Obiekt3D,public Przeszkoda{
protected:
/*!
* \brief Wymiary płaszczyzny
* 
* W tablicy przechowywane są wymiary
* plaszczyzny
*/
double granice[5];
public:
    /*!
    * \brief Metoda zmieniająca poziom płaszczyzny
    * 
    * Metoda zmienia poziom płaszczyzny na poziom
    * podany w parametrze
    * \param[in] level - nowy poziom płaszczyzny (w osi z)
    */
virtual void Poziom(double level)=0;
};
#endif