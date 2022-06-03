#include "map.hpp"
#include <queue>
#include <vector>

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

bool haveUnvisited(bool *v, int n)
{
    for(int i = 0; i < n; i++)
        if(!v[i])
            return true;
    return false; 
}

void Map::findMax(int o, int d)
{
    o--;
    d--;
    int updtNumOfPaths = 0, numOfPaths = 1; 
    pair<int, int> initCity, moveAux;
    queue<int> pp; 
    queue<pair<int, int>> adjCitys;            
    bool visited[numberOfCitys];              

    for (int i = 0; i < numberOfCitys; i++)
        visited[i] = false;

    initCity.first = o;
    initCity.second = 0;
    adjCitys.push(initCity);
    visited[initCity.first] = true;

    while (!adjCitys.empty())
    {
        int auxC = adjCitys.front().first;
        int auxW = adjCitys.front().second;
        adjCitys.pop();

        for(int i = 0 && i != auxC; i < numberOfCitys; i++)
        {
            if(!visited[i] && mapMatrix[auxC][i] > 0)
            {
                moveAux.first = i;
                if(auxW == 0)
                    moveAux.second = mapMatrix[auxC][i];
                else
                    if(mapMatrix[auxC][i] < auxW)
                        moveAux.second = mapMatrix[auxC][i];

                if(i == d)
                {
                    if(auxW == 0)
                        pp.push(mapMatrix[auxC][i]);
                    else
                    {
                        if(mapMatrix[auxC][i] < auxW)
                            pp.push(mapMatrix[auxC][i]);
                        else
                            pp.push(auxW);
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

        if(numOfPaths == 0)
        {
            numOfPaths = updtNumOfPaths;
            updtNumOfPaths = 0;
        }

    }

    int maior = 0;
    while(!pp.empty())
    {
        if(pp.front() > maior)
            maior = pp.front();
        pp.pop();
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