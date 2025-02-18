#ifndef CHORDPROGRESSION_H
#define CHORDPROGRESSION_H

#include <vector>
#include <string>
#include <iostream>
#include "chord.hpp"

class ChordProgression {
private:
    std::vector<Chord> chords;
public:
    // Constructors
    ChordProgression();
    ChordProgression(const std::vector<Chord>& chords);
    // Create a chord progression from roman numeral analysis strings and a key.
    ChordProgression(const std::vector<std::string>& romanNumerals, Note key);

    // Manipulation methods
    void addChord(const Chord &chord);
    void removeChordAt(size_t index);
    std::vector<Chord> getChords() const;

    // Transpose the entire progression by a given number of semitones
    ChordProgression transpose(int semitones) const;

    // Convert the progression to roman numeral analysis relative to the given key (assumed major)
    std::string toRomanNumerals(Note key) const;

    friend std::ostream &operator<<(std::ostream &os, const ChordProgression &cp);
};

#endif // CHORDPROGRESSION_H

