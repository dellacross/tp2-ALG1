#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Map
{
public:
    /**
     * @brief Construct a new Map object
     * @param nCitys number of citys 
     * @param nHighways number of highways
     * @param nQueries number of queries
     */
    Map(int nCitys, int nHighways, int nQueries);

    /**
     * @brief Destroy the Map object
     */
    ~Map();

    /**
     * @brief map Matrix constructor
     */
    void initMapMatrix();

    /**
     * @brief update the mapMatrix
     * @param sourceCity 
     * @param destinyCity 
     * @param weight maximum weight supported by the highway between the sourceCity and the destinyCity
     */
    void uptadeMapMatrix(int sourceCity, int destinyCity, int weight) { mapMatrix[sourceCity - 1][destinyCity - 1] = weight; };

    /**
     * @brief find the maximal weight of each query using BFS (Breadth First Search)
     * @param source is the city where the path starts
     * @param destiny is the city where the path ends
     */
    void findMax(int source, int destiny);

private:
    int **mapMatrix;      /* matrix that store the information about the map */
    int numberOfCitys;    /* number of cities on the map */
    int numberOfQueries;  /* number of queries to do */
    int numberOfHighways; /* number of highways on the map */
};