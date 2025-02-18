#include "chord.hpp"
#include <algorithm>
#include <unordered_map>
#include <stdexcept>
#include <iostream>

// Convert a string to a Note enum (handles enharmonic equivalents)
Note stringToNote(const std::string &s) {
    static const std::unordered_map<std::string, Note> noteMap = {
        {"C", C},   {"B#", C},
        {"C#", Cs}, {"Db", Cs},
        {"D", D},
        {"D#", Ds}, {"Eb", Ds},
        {"E", E},   {"Fb", E},
        {"F", F},   {"E#", F},
        {"F#", Fs}, {"Gb", Fs},
        {"G", G},
        {"G#", Gs}, {"Ab", Gs},
        {"A", A},
        {"A#", As}, {"Bb", As},
        {"B", B},   {"Cb", B}
    };

    auto it = noteMap.find(s);
    if (it != noteMap.end())
        return it->second;
    throw std::invalid_argument("Invalid note: " + s);
}

// Convert a Note enum to its canonical string representation
std::string noteToString(Note note) {
    switch (note) {
        case C:  return "C";
        case Cs: return "C#";
        case D:  return "D";
        case Ds: return "D#";
        case E:  return "E";
        case F:  return "F";
        case Fs: return "F#";
        case G:  return "G";
        case Gs: return "G#";
        case A:  return "A";
        case As: return "A#";
        case B:  return "B";
        default: return "Unknown";
    }
}

Note transpose(Note note, int semitones) {
    int newVal = (static_cast<int>(note) - 1 + semitones) % 12;
    if(newVal < 0)
        newVal += 12;
    
    newVal += 1;
    return static_cast<Note>(newVal);
}

// Convert a Quality enum to its string suffix for chord notation
std::string qualityToString(Quality quality) {
    switch (quality) {
        case Major:          return "";
        case Minor:          return "m";
        case Diminished:     return "dim";
        case Augmented:      return "aug";
        case HalfDiminished: return "ø";
        default:             return "";
    }
}

// Convert a string to a Quality enum
Quality stringToQuality(const std::string &s) {
    if (s == "maj" || s == "M" || s == "")
        return Major;
    else if (s == "m" || s == "min")
        return Minor;
    else if (s == "dim")
        return Diminished;
    else if (s == "aug")
        return Augmented;
    else if (s == "ø" || s == "hdim" || s == "m7b5")
        return HalfDiminished;
    else
        throw std::invalid_argument("Invalid quality: " + s);
}


// Constructor with only root note (defaults to Major)
Chord::Chord(Note rootNote)
    : rootNote(rootNote), quality(Major), extension("") { }

// Constructor with specified quality
Chord::Chord(Note rootNote, Quality quality)
    : rootNote(rootNote), quality(quality), extension("") { }

// Constructor with extension
Chord::Chord(Note rootNote, Quality quality, const std::string &extension)
    : rootNote(rootNote), quality(quality), extension(extension) { }

Note Chord::getRootNote() const {
    return rootNote;
}

Quality Chord::getQuality() const {
    return quality;
}

std::string Chord::getExtension() const {
    return extension;
}

void Chord::setRootNote(Note note) {
    rootNote = note;
}

void Chord::setQuality(Quality q) {
    quality = q;
}

void Chord::setExtension(const std::string &ext) {
    extension = ext;
}

// Transpose the chord by a given number of semitones.
Chord Chord::transpose(int semitones) const {
    int newNoteVal = static_cast<int>(rootNote) - 1;
    newNoteVal = (newNoteVal + semitones) % 12;
    if (newNoteVal < 0)
        newNoteVal += 12;
    newNoteVal += 1;
    Note newRoot = static_cast<Note>(newNoteVal);
    return Chord(newRoot, quality, extension);
}


// Return the chord as a string (e.g., "C#m7", "Gdim", etc.)
std::string Chord::toString() const {
    std::string result = noteToString(rootNote);
    result += qualityToString(quality);
    result += extension;
    return result;
}

// Parse a chord from a string.
// Expected format: [Note][Quality][Extension]
// Examples: "C#m7", "Gdim", "Faug7", "Am"
Chord Chord::fromString(const std::string &chordStr) {
    if (chordStr.empty())
        throw std::invalid_argument("Empty chord string");

    size_t pos = 0;
    // Extract the note (letter and optional accidental)
    std::string noteStr;
    noteStr.push_back(chordStr[pos++]);
    if (pos < chordStr.size() && (chordStr[pos] == '#' || chordStr[pos] == 'b')) {
        noteStr.push_back(chordStr[pos++]);
    }
    Note root = stringToNote(noteStr);

    // Default quality is Major.
    Quality qual = Major;
    std::string ext = "";
    if (pos < chordStr.size()) {
        if (chordStr.compare(pos, 3, "dim") == 0) {
            qual = Diminished;
            pos += 3;
        } else if (chordStr.compare(pos, 3, "aug") == 0) {
            qual = Augmented;
            pos += 3;
        } else if (chordStr[pos] == 'm') {
            qual = Minor;
            pos++;
        } else if (chordStr[pos] == 'o') {
            qual = HalfDiminished;
            pos++;
        }
        if (pos < chordStr.size()) {
            ext = chordStr.substr(pos);
        }
    }
    return Chord(root, qual, ext);
}

std::ostream &operator<<(std::ostream &os, const Chord &chord) {
    os << chord.toString();
    return os;
}

