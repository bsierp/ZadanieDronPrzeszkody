#ifndef DNO_HH
#define DNO_HH
/*!
 * \file
 * \brief Definicja klasy Dno
 *
 * Plik zawiera definicje klasy Dno,
 * oraz deklaracje metod tej klasy.
 */
#include "Plaszczyzna.hh"
using std::vector;
using drawNS::Point3D;
/*!
* \brief Model pojęcia Dno
*
* Klasa modeluje pojęcie dna dziedzicząc
* publicznie po klasie Plaszczyzna.
*/
class Dno: public Plaszczyzna{
public:
    /*!
    * \brief Konstruktor bezparametryczny klasy Dno
    * 
    * Konstruktor inicjalizuje wymiary dna wartością zero.
    */
Dno();
    /*!
    * \brief Konstruktor sześcioparametryczny klasy Dno
    * 
    * Konstruktor inicjalizuje wymiary dna wartościami 
    * parametrów \n
    * \param[in] max_x - maksymalny wymiar w osi x
    * \param[in] min_x - minimalny wymiar w osi x
    * \param[in] max_y - maksymalny wymiar w osi y
    * \param[in] min_y - minimalny wymiar w osi y
    * \param[in] z - poziom płaszczyzny w osi z
    * \param[in] api - wskaźnik do programu graficznego, w którym ma być rysowany obiekt
    */
Dno(double max_x, double min_x, double max_y, double min_y,double z, drawNS::Draw3DAPI * api);
void Rysuj() override;
void Poziom(double level) override;
void Wymaz() override;
bool czy_kolizja(std::shared_ptr<Interfejs> drone) const override;
};
#endif