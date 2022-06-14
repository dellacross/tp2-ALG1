#include "map.hpp"
#include <queue>

Map::Map(int nCitys, int nHighways, int nQueries)
{
    numberOfCitys = nCitys; /* set the number of citys */
    numberOfHighways = nHighways; /* set the number of highways */
    numberOfQueries = nQueries; /* set the number of queries */
    initMapMatrix();
}

void Map::initMapMatrix()
{
    mapMatrix = new int *[numberOfCitys];
    for (int i = 0; i < numberOfCitys; i++)
        mapMatrix[i] = new int[numberOfCitys];
}

void Map::findMax(int source, int destiny)
{
    source--;
    destiny--;

    int updtNumOfPaths = 0, numOfPaths = 1; /* numOfPaths: number of paths */
    pair<int, int> initCity, moveAux;       /* initCity: city where the search begins */
    queue<int> possibleWeights;             /* possibleWeights: queue that store all weights of a path between two citys */
    queue<pair<int, int>> adjCitys;         /* adjCitys: queue that store the adjacent citys of the current city on the search */
    bool visited[numberOfCitys];            /* visited[i]: if city i has already visited, visited[i] == true, else, visited[i] == false */

    for (int i = 0; i < numberOfCitys; i++) /* set all citys as unvisited */
        visited[i] = false;

    initCity.first = source;
    initCity.second = 0;
    adjCitys.push(initCity); /* push the initial city into the adjCitys queue */
    visited[source] = true;  /* set the initial city as visited */

    while (!adjCitys.empty())
    {
        int auxCity = adjCitys.front().first;    /* store the current city of the search */
        int auxWeight = adjCitys.front().second; /* store the current maximal weight of the path */
        adjCitys.pop();

        for (int i = 0 && i != auxCity; i < numberOfCitys; i++)
        {
            if (!visited[i] && mapMatrix[auxCity][i] > 0) /* if the city i is unvisited and maximal weight of the highway between auxCity and i is > 0 */
            {
                moveAux.first = i;
                if (auxWeight == 0) /* if the current maximal weight is == 0 */
                    moveAux.second = mapMatrix[auxCity][i];
                else if (mapMatrix[auxCity][i] < auxWeight) /* if the weight of the current highway is lower than the current maximal weight */
                    moveAux.second = mapMatrix[auxCity][i];

                if (i == destiny) /* if the current city is the destiny */
                {
                    if ((auxWeight == 0) || (mapMatrix[auxCity][i] < auxWeight)) /* if the current maximal weight of the path is == 0 or if the weight of the current highway is lower than the current maximal weight */
                        possibleWeights.push(mapMatrix[auxCity][i]); /* push the weight between city auxCity and city i into the possibleWeights queue */
                    else
                        possibleWeights.push(auxWeight);
                }
                else
                {
                    adjCitys.push(moveAux); /* push the current city into the adjCitys queue */
                    visited[i] = true;      /* set the city i as visited */
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

    visited[destiny] = true; /* find all possible weights*/
    int maior = 0;
    while (!possibleWeights.empty()) /* find the maximal weight possible between all possible weights of the path */
    {
        if (possibleWeights.front() > maior)
            maior = possibleWeights.front();
        possibleWeights.pop();
    }
    cout << maior << "\n"; /* print the maximal weight of the path */
}

Map::~Map()
{
    for (int i = 0; i < numberOfCitys; i++)
        delete mapMatrix[i];
    delete[] mapMatrix;
}