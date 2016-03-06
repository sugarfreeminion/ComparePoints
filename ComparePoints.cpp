/************************************************************************
 * Author:          sugarfreeoh
 * Date:            5 March 2016
 * Description:     Each test case consists of four integeters O,P,Q,R
 *                  For each test case print a line containing one of
 *                  the following: N, NE, E, SE, S, SW, W, NW, here if
 *                  the coordinates Q,R.
 ***********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct coordinate
{
    int x;
    int y;
};

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            coordinate location;
            coordinate destination;
            stringstream lineStream;

            string temp;
            string direction;

            int count = 0;

            lineStream << line;

            while(getline(lineStream,temp,' '))
            {
                int tempCoord;
                stringstream tempStream;

                tempStream << temp;
                tempStream >> tempCoord;

                if(count == 0)
                {
                    location.x = tempCoord;
                }
                else if(count == 1)
                {
                    location.y = tempCoord;
                }
                else if(count == 2)
                {
                    destination.x = tempCoord;
                }
                else if(count == 3)
                {
                    destination.y = tempCoord;
                }

                ++count;
            }

            /*
            cout << "Location Coordinates: " << location.x << "," << location.y << endl;
            cout << "Destination Coordinates: " << destination.x << "," << destination.y << endl;
            */

            if(location.x == destination.x
               && location.y == destination.y)
            {
                direction = "here";
            }

            if(direction.empty())
            {
                if(location.y > destination.y)
                {
                    direction += "S";
                }
                else if(location.y < destination.y)
                {
                    direction += "N";
                }

                if(location.x > destination.x)
                {
                    direction += "W"; 
                }
                else if(location.x < destination.x)
                {
                    direction += "E";
                }
            }

            cout << direction << endl;
        }

        inputFile.close();
    }
    else
    {
        cout << "Error opening input file" << endl;
    }
    
    return 0;
}
