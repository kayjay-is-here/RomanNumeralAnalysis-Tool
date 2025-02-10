// chord.hpp
#ifndef CHORD_H
#define CHORD_H
#include <string>

enum Note {
    C = 1,
    Cs = 2,
    D = 3,
    Ds = 4,
    E = 5,
    F = 6,
    Fs = 7,
    G = 8,
    Gs = 9,
    A = 10,
    As = 11,
    B = 12
};

enum Quality
{
    Major = 0,
    Minor = 1,
    Diminished = 2,
    Augmented = 3,
    HalfDiminished = 4
};

// Maps enharmonic notes using an unordered map 
Note stringToNote(const std::string &s);

class Chord 
{
    Note rootNote;
    Quality quality;
    std::string Extension; // TODO actually figure out how this works

    Chord(); // This should throw an error actually since I don't want a chord with nothing set to it 
    Chord(Note rootNote);
    Chord(Note rootNote, Quality quality);
    Chord(Note rootNote, Quality quality, std::string extension);

};
#endif
