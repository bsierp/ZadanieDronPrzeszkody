#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH
/*!
 * \file
 * \brief Definicja klasy abstrakcyjnej Obiekt3D
 *
 * Plik zawiera definicje klasy abstrakcyjnej Obiekt3D,
 * oraz deklaracje wirtualnych metod tej klasy.
 */
#include"MacOb.hh"
#include"Dr3D_gnuplot_api.hh"
/*!
* \brief Model pojęcia trójwymiarowego obiektu
*
* Klasa abstrakcyjna modeluje ogólne pojęcie 
* trójwymiarowego obiektu
*/
class Obiekt3D{
    protected:
    /*!
    * \brief Środek obiektu trójwymiarowego
    * 
    * Zmienna zawiera współrzędne środka
    * trójwymiarowego obiektu. Wokół tego 
    * punktu następuje obrót obiektu.
    */
    Wektor<double,3> srodek;
    /*!
    * \brief Orientacja obiektu trójwymiarowego
    * 
    * Reprezentuje orientację obiektu
    * względem globalnego układu współrzędnych
    */
    MacOb orient;
    /*!
    * \brief Id obiektu 
    * 
    * Zmienna służąca do przechowywania id
    * obiektu rysowanego w gnuplocie
    */
    int id;
    /*!
    * \brief Wskaźnik do programu graficznego
    * 
    * Zmienna wskaźnikowa do programu graficznego,
    * w którym odbywa się rysowanie obiektu.
    */
    drawNS::Draw3DAPI *gplt;
    static inline int count_current=0;
    static inline int count_destroyed=0;
    public:
    static int zwroc_istniejace(){return count_current;}
    static int zwroc_usuniete(){return count_destroyed;}
    static int zwroc_wszystkie(){return count_current+count_destroyed;}
    Obiekt3D(){count_current++;}
    Obiekt3D(const Obiekt3D & Ob): gplt(Ob.gplt), id(Ob.id), orient(Ob.orient), srodek(Ob.srodek){++count_current;}
    /*!
    * \brief Metoda rysująca trójwymiarowy obiekt
    * 
    * Rysuje obiekt w programie graficznym, do którego
    * wskaźnik posiada obiekt. 
    */
    virtual void Rysuj()=0;
    /*!
    * \brief Metoda wymazująca obiekt
    * 
    * Wymazuje obiekt z programu graficznego.
    * Jest używana za każdym razem, gdy w 
    * metodzie jest metoda Rysuj()
    */
    virtual void Wymaz()=0;
    ~Obiekt3D(){--count_current; ++count_destroyed;}
};
#endif