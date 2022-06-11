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
     * @param nCitys 
     * @param nHighways 
     * @param nQueries 
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
     * @brief 
     * @param sourceCity 
     * @param destinyCity 
     * @param weight 
     */
    void uptadeMapMatrix(int sourceCity, int destinyCity, int weight);

    /**
     * @brief find the maximal weight of each query
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