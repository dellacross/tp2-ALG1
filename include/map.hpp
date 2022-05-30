#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Map
{
    public:
        Map(fstream &file);

        void initMapMatrix();
        void uptadeMapMatrix(fstream &file);

        void print();


    private:
        int **mapMatrix;
        int numberOfCitys;
        int numberOfQueries;
        int numberOfHighways;
};