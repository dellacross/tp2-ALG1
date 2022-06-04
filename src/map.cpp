#include "map.hpp"
#include <queue>

Map::Map(fstream &file)
{
    string line = "";
    getline(file, line);
    stringstream lineStream(line);

    lineStream >> numberOfCitys >> numberOfHighways >> numberOfQueries;
    initMapMatrix();
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

void Map::findMax(int source, int destiny)
{
    source--;
    destiny--;

    int updtNumOfPaths = 0, numOfPaths = 1;
    pair<int, int> initCity, moveAux;
    queue<int> possibleWeights;
    queue<pair<int, int>> adjCitys;
    bool visited[numberOfCitys];

    for (int i = 0; i < numberOfCitys; i++)
        visited[i] = false;

    initCity.first = source;
    initCity.second = 0;
    adjCitys.push(initCity);
    visited[source] = true;

    while (!adjCitys.empty())
    {
        int auxC = adjCitys.front().first;
        int auxW = adjCitys.front().second;
        adjCitys.pop();

        for (int i = 0 && i != auxC; i < numberOfCitys; i++)
        {
            if (!visited[i] && mapMatrix[auxC][i] > 0)
            {
                moveAux.first = i;
                if (auxW == 0)
                    moveAux.second = mapMatrix[auxC][i];
                else if (mapMatrix[auxC][i] < auxW)
                    moveAux.second = mapMatrix[auxC][i];

                if (i == destiny)
                {
                    if (auxW == 0)
                        possibleWeights.push(mapMatrix[auxC][i]);
                    else
                    {
                        if (mapMatrix[auxC][i] < auxW)
                            possibleWeights.push(mapMatrix[auxC][i]);
                        else
                            possibleWeights.push(auxW);
                    }
                }
                else
                {
                    adjCitys.push(moveAux);
                    visited[i] = true;
                    updtNumOfPaths++;
                }
            }
        }

        numOfPaths--;

        if (numOfPaths == 0)
        {
            numOfPaths = updtNumOfPaths;
            updtNumOfPaths = 0;
        }
    }

    int maior = 0;
    while (!possibleWeights.empty())
    {
        if (possibleWeights.front() > maior)
            maior = possibleWeights.front();
        possibleWeights.pop();
    }
    cout << maior << "\n";
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
        findMax(source, destiny);
    }
}