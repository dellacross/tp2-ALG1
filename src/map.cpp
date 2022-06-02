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
    int aux = o, c = -1, heaviest = 0, radar = 1, pa = 0;
    bool visited[numberOfCitys];
    int path[numberOfCitys - 1];
    queue<int> pp;

    for (int i = 0; i < numberOfCitys; i++)
        visited[i] = false;

    for (int i = 0; i < numberOfCitys-1; i++)
        path[i] = -1;

    path[0] = o;
    visited[o] = true;

    while (haveUnvisited(visited, numberOfCitys))
    {
        for (int j = 0 ; j < numberOfCitys; j++)
        {
            //cout << "mapMatrix[" << aux << "][" << j << "]: " << mapMatrix[aux][j] << "\n";
            //cout << "heaviest: " << heaviest << "\n";
            if (mapMatrix[aux][j] > heaviest && !visited[j])
            {
                heaviest = mapMatrix[aux][j];
                c = j;
            }

            //cout << "j: " << j << " == " << d << "? \n";
            if(j == d)
            {
                //cout << "Sim!" << "\n";
                if(mapMatrix[aux][j] > pa && pa != 0)
                    pp.push(pa);
                else
                    pp.push(mapMatrix[aux][j]);
            }
        }

        aux = c;
        //cout << "aux: " << aux << "\n";
        visited[aux] = true;
        if (heaviest == 0)
        {
            path[radar] = -1;
            radar--;
            aux = path[radar];
        }
        else
        {
            path[radar] = aux;
            radar++;
            if(pa == 0 || heaviest <= pa)
                pa = heaviest;
            //cout << "pa: " << pa << "\n";
        }
        heaviest = 0;
        c = -1;
    }

    pp.push(pa);
    int maior = 0;

    //cout << "Vector:" << "\n";
    while(!pp.empty())
    {
        //cout << pp.front() << " ";
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
        //cout << "source: " << source << " destiny: " << destiny << "\n";
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