#ifndef WODA_HH
#define WODA_HH
/*!
 * \file
 * \brief Definicja klasy Woda
 *
 * Plik zawiera definicje klasy Woda,
 * oraz deklaracje metod tej klasy.
 */
#include "Plaszczyzna.hh"
using drawNS::Point3D;
using std::vector;
/*!
* \brief Model pojęcia tafli wody
*
* Klasa modeluje pojęcie tafli wody dziedzicząc
* publicznie po klasie Plaszczyzna.
*/
class Woda: public Plaszczyzna {
public:
    /*!
    * \brief Konstruktor bezparametryczny klasy Woda
    * 
    * Konstruktor inicjalizuje wymiary tafli wartością zero.
    */    
Woda();
    /*!
    * \brief Konstruktor sześcioparametryczny klasy Woda
    * 
    * Konstruktor inicjalizuje wymiary tafli wartościami 
    * parametrów \n
    * \param[in] max_x - maksymalny wymiar w osi x
    * \param[in] min_x - minimalny wymiar w osi x
    * \param[in] max_y - maksymalny wymiar w osi y
    * \param[in] min_y - minimalny wymiar w osi y
    * \param[in] z - poziom płaszczyzny w osi z
    * \param[in] api - wskaźnik do programu graficznego, w którym ma być rysowany obiekt
    */
Woda(double max_x, double min_x, double max_y, double min_y,double z, drawNS::Draw3DAPI * api);
void Poziom(double level) override;
void Rysuj() override;
void Wymaz() override;
bool czy_kolizja(std::shared_ptr<Interfejs> drone) const override;
};
#endif