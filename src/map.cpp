#include "map.hpp"
#include <queue>

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
    int aux = o, c = -1, heavy = 0, radar = 1, pa = 0;
    bool visited[numberOfCitys];
    int path[numberOfCitys - 1];
    queue<int> pp;

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
            if (((pa == 0 && mapMatrix[aux][j] > heavy) || (pa != 0 && mapMatrix[aux][j] <= pa)) && !visited[j])
            {
                heavy = mapMatrix[aux][j];
                c = j;
            }

            if(j == d)
                pp.push(mapMatrix[aux][j]);
        }

        aux = c;
        visited[aux] = true;
        if (heavy == 0)
        {
            path[radar] = -1;
            radar--;
            aux = path[radar];
        }
        else
        {
            path[radar] = aux;
            radar++;
            if(pa == 0 || heavy <= pa)
                pa = heavy;
            cout << "pa: " << pa << "\n";
        }
        heavy = 0;
        c = -1;
    }

    pp.push(pa);
    int maior = 0;

    cout << "Vector:" << "\n";
    while(!pp.empty())
    {
        cout << pp.front() << " ";
        if(pp.front() > maior)
            maior = pp.front();
        pp.pop();
    }
    
    cout << "\n" << maior << "\n";
}

void Map::leitor(fstream &file)
{
    string line = "";
    int source, destiny;
    for (int i = 0; i < numberOfQueries; i++)
    {
        getline(file, line);
        stringstream lineStream(line);
        lineStream >> source >> destiny;
        cout << "source: " << source << " destiny: " << destiny << "\n";
        findMax(source, destiny);
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