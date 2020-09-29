#ifndef ZONE_H
#define ZONE_H
#include <string>
using namespace std;

class Zone
{
    public:
        Zone();
        virtual ~Zone();
        string getType();
        void setType(string type);

        unsigned short int getXmin();
        void setXmin(unsigned int value);
        unsigned short int getXmax();
        void setXmax(unsigned int value);

        unsigned short int getYmin();
        void setYmin(unsigned int value);
        unsigned short int getYmax();
        void setYmax(unsigned int value);

    protected:

    private:
        unsigned short int xMin;
        unsigned short int xMax;
        unsigned short int yMin;
        unsigned short int yMax;
        string typeZone;
};

#endif // ZONE_H
