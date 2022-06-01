#include "map.hpp"

Map::Map(fstream &file)
{
    string line = "";
    getline(file, line);
    stringstream lineStream(line);

    lineStream >> numberOfCitys >> numberOfHighways >> numberOfQueries;
    initMapMatrix();
    uptadeMapMatrix(file);
    leitor(file);

    //print();
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
    for (int i = 0; i < numberOfHighways; i++)
    {
        getline(file, line);
        stringstream lineStream(line);
        lineStream >> x >> y >> maximumWeight;
        mapMatrix[x - 1][y - 1] = maximumWeight;
    }
}

void Map::findMax(int o, int d)
{
    o--;
    d--;
    int aux = o, heavy = 0, radar = 1, res = 0;
    bool visited[numberOfCitys];
    int path[numberOfCitys - 1];

    for (int i = 0; i < numberOfCitys; i++)
        visited[i] = false;

    for (int i = 0; i < numberOfCitys-1; i++)
        path[i] = -1;

    path[0] = o;
    visited[o] = true;

    while (!visited[d])
    {
        for (int j = 0; j < numberOfCitys; j++)
        {
            if (mapMatrix[aux][j] > heavy && !visited[j])
            {
                heavy = mapMatrix[aux][j];
                aux = j;
            }
        }

        visited[aux] = true;
        if (heavy == 0)
        {
            path[radar] = -1;
            radar--;
        }
        else
        {
            path[radar] = aux;
            radar++;
        }
        res = heavy;
        heavy = 0;
    }
    cout << res << "\n";
}

void Map::leitor(fstream &file)
{
    string line = "";
    int origem, destino;
    for (int i = 0; i < numberOfQueries; i++)
    {
        getline(file, line);
        stringstream lineStream(line);
        lineStream >> origem >> destino;
        findMax(origem, destino);
    }
}

void Map::print()
{
    cout << "MapMatrix: "
         << "\n";
    for (int i = 0; i < numberOfCitys; i++)
    {
        for (int j = 0; j < numberOfCitys; j++)
            cout << mapMatrix[i][j] << " ";
        cout << "\n";
    }
}