#ifndef MACOB_HH
#define MACOB_HH
/*!
* \file
* \brief Definicja klasy MacOb
*
* Plik zawiera definicję klasy MacOb,
* oraz deklaracje jej konstruktorów.
* 
*/
#define PI 3.14159265
#include"Mac.hh"
/*!
* \brief Model pojęcia Macierzy Obrotu
*
* Klasa modeluje pojęcie macierzy obrotu,
* dziedziczącą publicznie po klasie Macierz
* o rozmiarze 3 oraz typie danych double.
*/
class MacOb:public Macierz<double,3>{
public:
/*!
* \brief Konstruktor bezparametryczny klasy MacOb
*
* Tworzy macierz jednostkową
*/
MacOb();
/*!
* \brief Konstruktor jednoparametryczny klasy MacOb
*
* Tworzy macierz obrotową z macierzy o wymiarach
* 3x3, pod warunkiem, że jest ortogonalna \n
* \param[in] Mac - Macierz, z której zostanie utworzona klasa obrotu.
*/
MacOb(const Macierz<double,3> & Mac);
/*!
* \brief Konstruktor dwuparametryczny klasy MacOb
* 
* Tworzy macierz obrotową wokół wybranej osi,
* o wybraną wartość kąta. \n
* \param[in] os - oś obrotu macierzy (x,y lub z)
* \param[in] kat - wartość kąta obrotu w stopniach
*/
MacOb(char os,double kat);
};
#endif