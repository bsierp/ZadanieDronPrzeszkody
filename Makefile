CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc 
OBJ=./obj
TRGDIR=./

__start__: ${TRGDIR}/dron
		${TRGDIR}/dron
${TRGDIR}/dron: ${OBJ} ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/Prostopadloscian.o ${OBJ}/WekC.o ${OBJ}/MacC.o ${OBJ}/MacOb.o ${OBJ}/Dron.o ${OBJ}/GraniastoslupHex.o ${OBJ}/Sruba.o ${OBJ}/Woda.o ${OBJ}/Dno.o
			g++ -o ${TRGDIR}/dron ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/Prostopadloscian.o ${OBJ}/WekC.o ${OBJ}/MacC.o ${OBJ}/MacOb.o ${OBJ}/Dron.o ${OBJ}/GraniastoslupHex.o ${OBJ}/Sruba.o ${OBJ}/Woda.o ${OBJ}/Dno.o -lpthread
${OBJ}:
		mkdir ${OBJ}
${OBJ}/main.o: src/main.cpp inc/Obiekt3D.hh inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Prostopadloscian.hh inc/Interfejs.hh inc/MacOb.hh inc/GraniastoslupHex.hh inc/Sruba.hh inc/Plaszczyzna.hh inc/Dno.hh inc/Woda.hh inc/Przeszkoda.hh
		g++ ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp
${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp
${OBJ}/MacC.o: inc/Mac.hh src/Mac.cpp src/MacC.cpp inc/Wek.hh                 
		g++ ${CPPFLAGS} -o ${OBJ}/MacC.o src/MacC.cpp
${OBJ}/WekC.o: inc/Wek.hh src/Wek.cpp src/WekC.cpp                            
		g++ ${CPPFLAGS} -o ${OBJ}/WekC.o src/WekC.cpp
${OBJ}/Prostopadloscian.o: inc/Prostopadloscian.hh src/Prostopadloscian.cpp inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacOb.hh inc/Przeszkoda.hh inc/Interfejs.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Prostopadloscian.o src/Prostopadloscian.cpp
${OBJ}/Dron.o: inc/Dron.hh src/Dron.cpp inc/Obiekt3D.hh inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Prostopadloscian.hh inc/Interfejs.hh inc/MacOb.hh inc/Sruba.hh inc/Przeszkoda.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Dron.o src/Dron.cpp
${OBJ}/MacOb.o: inc/MacOb.hh src/MacOb.cpp inc/Mac.hh inc/Wek.hh
		g++ ${CPPFLAGS} -o ${OBJ}/MacOb.o src/MacOb.cpp
${OBJ}/GraniastoslupHex.o: src/GraniastoslupHex.cpp inc/GraniastoslupHex.hh inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacOb.hh
		g++ ${CPPFLAGS} -o ${OBJ}/GraniastoslupHex.o src/GraniastoslupHex.cpp
${OBJ}/Sruba.o: src/Sruba.cpp inc/Sruba.hh inc/GraniastoslupHex.hh inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacOb.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Sruba.o src/Sruba.cpp
${OBJ}/Dno.o: src/Dno.cpp inc/Dno.hh inc/Plaszczyzna.hh inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacOb.hh inc/Przeszkoda.hh inc/Interfejs.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Dno.o src/Dno.cpp
${OBJ}/Woda.o: src/Woda.cpp inc/Woda.hh inc/Plaszczyzna.hh inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacOb.hh inc/Przeszkoda.hh inc/Interfejs.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Woda.o src/Woda.cpp
inc/Plaszczyzna.hh: inc/Obiekt3D.hh inc/MacOb.hh inc/Wek.hh inc/Mac.hh inc/Draw3D_api_interface.hh inc/Dr3D_gnuplot_api.hh inc/Przeszkoda.hh inc/Interfejs.hh
		touch inc/Plaszczyzna.hh
inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
		touch inc/Dr3D_gnuplot_api.hh
inc/Interfejs.hh: inc/Wek.hh
		touch inc/Interfejs.hh
inc/Obiekt3D.hh: inc/MacOb.hh inc/Mac.hh inc/Wek.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
		touch inc/Obiekt3D.hh
inc/Przeszkoda.hh: inc/Interfejs.hh
		touch inc/Przeszkoda.hh
clear:
		rm -f ${TRGDIR}/test ${OBJ}/*