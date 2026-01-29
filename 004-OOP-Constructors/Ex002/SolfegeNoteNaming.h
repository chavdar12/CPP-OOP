#ifndef SOLFEGE_NOTE_NAMING_H
#define SOLFEGE_NOTE_NAMING_H

#include <string>
#include "NoteName.h"

class SolfegeNoteNaming
{
public:
    NoteName operator()(const std::string& noteText) const
    {
        char englishName;

        if (noteText == "Do")
        {
            englishName = 'C';
        }
        else if (noteText == "Re")
        {
            englishName = 'D';
        }
        else if (noteText == "Mi")
        {
            englishName = 'E';
        }
        else if (noteText == "Fa")
        {
            englishName = 'F';
        }
        else if (noteText == "Sol")
        {
            englishName = 'G';
        }
        else if (noteText == "La")
        {
            englishName = 'A';
        }
        else if (noteText == "Si")
        {
            englishName = 'B';
        }
        else
        {
            englishName = '?';
        }

        return NoteName(englishName);
    }
};

#endif // SOLFEGE_NOTE_NAMING_H
