#ifndef CODEURSAUVAGE_H
#define CODEURSAUVAGE_H
#include "Codeur.h"


class CodeurSauvage
{
    public:
        CodeurSauvage();
        virtual ~CodeurSauvage();

        int getXMin();
        void setXMin(unsigned int value);

        int getYMin();
        void setYMin(unsigned int value);

        int getXMax();
        void setXMax(unsigned int value);

        int getYMax();
        void setYMax(unsigned int value);

        bool estALinterieurDeToi(int xMin, int xMax, int yMin, int yMax);

        Codeur* getCodeurReference();

    protected:
        Codeur* codeurReference;
        int xMin;
        int yMin;
        int xMax;
        int yMax;

    private:
};

#endif // CODEURSAUVAGE_H
