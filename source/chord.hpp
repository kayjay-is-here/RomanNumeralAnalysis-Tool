#ifndef CHORD_H
#define CHORD_H

#include <string>
#include <stdexcept>
#include <iostream>

// Define the 12 pitch classes (using 1-indexing for clarity)
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

// Define chord qualities
enum Quality {
    Major = 0,
    Minor = 1,
    Diminished = 2,
    Augmented = 3,
    HalfDiminished = 4
};

// Conversion function declarations
Note stringToNote(const std::string &s);
Note transpose(Note initialNote, int transpose);
std::string noteToString(Note note);
std::string qualityToString(Quality quality);
Quality stringToQuality(const std::string &s);

// Chord class declaration
class Chord {
private:
    Note rootNote;
    Quality quality;
    std::string extension; // e.g., "7", "9", etc.

public:
    // Delete the default constructor to prevent uninitialized chords.
    Chord() = delete;

    Chord(Note rootNote);
    Chord(Note rootNote, Quality quality);
    Chord(Note rootNote, Quality quality, const std::string &extension);

    Note getRootNote() const;
    Quality getQuality() const;
    std::string getExtension() const;

    void setRootNote(Note note);
    void setQuality(Quality q);
    void setExtension(const std::string &ext);

    // Transpose the chord by a given number of semitones
    Chord transpose(int semitones) const;

    // Return the chord as a string (e.g., "C#m7", "Gdim", "Faug7", "Am")
    std::string toString() const;

    // Parse a chord from a string
    // Expected format: [Note][Quality][Extension]
    // Examples: "C#m7", "Gdim", "Faug7", "Am"
    static Chord fromString(const std::string &chordStr);

    friend std::ostream &operator<<(std::ostream &os, const Chord &chord);
};

#endif // CHORD_H

