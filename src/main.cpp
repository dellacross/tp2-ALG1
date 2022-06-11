#include "map.hpp"

int main(int argc, char *argv[])
{
    int numberOfCitys, numberOfHighways, numberOfQueries, sourceCity, destinyCity, weight, sourceDestinyCity, queryDestinyCity;
    cin >> numberOfCitys >> numberOfHighways >> numberOfQueries;
    
    Map map(numberOfCitys, numberOfHighways, numberOfQueries);

    for (int i = 0; i < numberOfHighways; i++)
    {
        cin >> sourceCity >> destinyCity >> weight;
        map.uptadeMapMatrix(sourceCity, destinyCity, weight);
    }

    for (int j = 0; j < numberOfQueries; j++)
    {
        cin >> sourceDestinyCity >> queryDestinyCity;
        map.findMax(sourceDestinyCity, queryDestinyCity);
    }

    return 0;
}