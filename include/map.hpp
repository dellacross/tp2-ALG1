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
     * @param file with the data
     */
    Map(fstream &file);

    /**
     * @brief Destroy the Map object
     */
    ~Map();

    /**
     * @brief map Matrix constructor
     */
    void initMapMatrix();

    /**
     * @brief update the map matrix data
     * @param file with the data
     */
    void uptadeMapMatrix(fstream &file);

    /**
     * @brief read the queries
     * @param file with the data
     */
    void reader(fstream &file);

    /**
     * @brief find the maximal weight of a path
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