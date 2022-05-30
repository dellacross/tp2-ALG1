#include "map.hpp"

Map::Map(fstream &file)
{
    string line = "";
    getline(file, line);
    stringstream lineStream(line);

    lineStream >> numberOfCitys >> numberOfHighways >> numberOfQueries;
    initMapMatrix();
    uptadeMapMatrix(file);

    print();
}

void Map::initMapMatrix()
{
    mapMatrix = new int *[numberOfCitys];
    for (int i = 0; i < numberOfCitys; i++)
        mapMatrix[i] = new int[numberOfCitys];
}

void Map::uptadeMapMatrix(fstream &file)
{
    string line = "";
    int x, y, maximumWeight;
    for(int i = 0; i < numberOfHighways; i++)
    {
        getline(file, line);
        stringstream lineStream(line);
        lineStream >> x >> y >> maximumWeight;
        mapMatrix[x-1][y-1] = maximumWeight;
    }
}

void Map::print()
{
    cout << "MapMatrix: " << "\n";
    for(int i = 0; i < numberOfCitys; i++)
    {
        for(int j = 0; j < numberOfCitys; j++)
           cout << mapMatrix[i][j] << " ";
        cout << "\n";
    }
}