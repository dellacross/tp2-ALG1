#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Map
{
public:
    Map(fstream &file);

    void initMapMatrix();
    void uptadeMapMatrix(fstream &file);
    void leitor(fstream &file);
    void findMax(int source, int destiny);

private:
    int **mapMatrix;
    int numberOfCitys;
    int numberOfQueries;
    int numberOfHighways;
};