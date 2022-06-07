#include "map.hpp"

int main(int argc, char *argv[])
{
    fstream file(argv[1]);

    if (file)
    {
        Map map(file);
        map.uptadeMapMatrix(file);
        map.reader(file);
    }
    else
        cout << "ERROR: FILE NOT FOUND!"
             << "\n";

    return 0;
}