BASEDIR =  ~/code/password-verify/src

CXX=g++
CXXFLAGS= -O -I./ < $(HEADER)

SRC = driver.cpp md5.cpp pwmanager.cpp
HEADER = md5.h pwmanager.h
OBJ = $(SRC:%.cpp=%.o)

build: 
	$(CXX) -o verify $(SRC)
debug:
	$(CXX) -o verify -g $(SRC)

depend:
	makedepend $(CXXFLAGS) $(SRC)
# DO NOT DELETE

driver.o: md5.h pwmanager.h
md5.o: md5.h
pwmanager.o: pwmanager.h md5.h
