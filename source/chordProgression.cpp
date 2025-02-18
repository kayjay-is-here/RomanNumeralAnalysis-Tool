#include "chordProgression.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <unordered_map>

// Helper function to convert a semitone difference (0..11) into a pair of Roman numeral strings
static std::pair<std::string, std::string> getRomanNumeralBase(int diff) {
    switch (diff) {
        case 0:  return { "I",   "i"   };
        case 1:  return { "#I",  "bII" };
        case 2:  return { "II",  "ii"  };
        case 3:  return { "#II", "bIII"};
        case 4:  return { "III", "iii" };
        case 5:  return { "IV",  "iv"  };
        case 6:  return { "#IV", "bV"  };
        case 7:  return { "V",   "v"   };
        case 8:  return { "#V",  "bVI" };
        case 9:  return { "VI",  "vi"  };
        case 10: return { "#VI", "bVII"};
        case 11: return { "VII", "vii" };
        default:
            return { "?", "?" };
    }
}

// Determine default chord quality from roman numeral case
static Quality defaultQualityFromRoman(const std::string &numeral) {
    for (char c : numeral) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            if (std::isupper(static_cast<unsigned char>(c)))
                return Major;
            else
                return Minor;
        }
    }
    return Major;
}

// Convert the core roman numeral (without accidentals or modifiers) to its semitone offset
static int offsetFromBaseRoman(const std::string &romanNoAccidentals) {
    std::string upper;
    for (char c : romanNoAccidentals)
        upper.push_back(std::toupper(static_cast<unsigned char>(c)));
    if      (upper == "I"   || upper == "I+"   || upper == "I°"   || upper == "IØ")    return 0;
    else if (upper == "II"  || upper == "II+"  || upper == "II°"  || upper == "IIØ")   return 2;
    else if (upper == "III" || upper == "III+" || upper == "III°" || upper == "IIIØ")  return 4;
    else if (upper == "IV"  || upper == "IV+"  || upper == "IV°"  || upper == "IVØ")   return 5;
    else if (upper == "V"   || upper == "V+"   || upper == "V°"   || upper == "VØ")    return 7;
    else if (upper == "VI"  || upper == "VI+"  || upper == "VI°"  || upper == "VIØ")   return 9;
    else if (upper == "VII" || upper == "VII+" || upper == "VII°" || upper == "VIIØ")  return 11;
    if      (upper == "I")   return 0;
    else if (upper == "II")  return 2;
    else if (upper == "III") return 4;
    else if (upper == "IV")  return 5;
    else if (upper == "V")   return 7;
    else if (upper == "VI")  return 9;
    else if (upper == "VII") return 11;
    throw std::invalid_argument("Invalid base Roman numeral: " + romanNoAccidentals);
}

// Parse a single roman numeral string into a Chord
static Chord parseRomanChord(const std::string &romanStr, Note key) {
    int accidental = 0;
    size_t pos = 0;
    while (pos < romanStr.size()) {
        if (romanStr[pos] == 'b') {
            accidental -= 1;
            pos++;
        } else if (romanStr[pos] == '#') {
            accidental += 1;
            pos++;
        } else {
            break;
        }
    }
    std::string core;
    while (pos < romanStr.size()) {
        char c = romanStr[pos];
        if (c == '+' || c == '°' || c == 'ø')
            break;
        core.push_back(c);
        pos++;
    }
    if (core.empty())
        throw std::invalid_argument("Invalid or missing core Roman numeral in: " + romanStr);
    Quality qual = defaultQualityFromRoman(core);
    if (pos < romanStr.size()) {
        char mod = romanStr[pos];
        if (mod == '+') {
            qual = Augmented;
            pos++;
        } else if (mod == '°') {
            qual = Diminished;
            pos++;
        } else if (mod == 'ø') {
            qual = HalfDiminished;
            pos++;
        }
    }
    std::string extension;
    if (pos < romanStr.size())
        extension = romanStr.substr(pos);
    int baseOffset = offsetFromBaseRoman(core);
    int finalOffset = baseOffset + accidental;
    finalOffset = ((finalOffset % 12) + 12) % 12;
    int keyVal = static_cast<int>(key);
    int newVal = ((keyVal - 1 + finalOffset) % 12 + 12) % 12 + 1;
    Note newRoot = static_cast<Note>(newVal);
    return Chord(newRoot, qual, extension);
}

ChordProgression::ChordProgression() : chords() { }

ChordProgression::ChordProgression(const std::vector<Chord>& chords)
    : chords(chords) { }

ChordProgression::ChordProgression(const std::vector<std::string>& romanNumerals, Note key) {
    chords.reserve(romanNumerals.size());
    for (const auto& rn : romanNumerals)
        chords.push_back(parseRomanChord(rn, key));
}

void ChordProgression::addChord(const Chord &chord) {
    chords.push_back(chord);
}

void ChordProgression::removeChordAt(size_t index) {
    if (index >= chords.size())
        throw std::out_of_range("Index out of range in removeChordAt");
    chords.erase(chords.begin() + index);
}

std::vector<Chord> ChordProgression::getChords() const {
    return chords;
}

ChordProgression ChordProgression::transpose(int semitones) const {
    std::vector<Chord> transposed;
    transposed.reserve(chords.size());
    for (const auto &chord : chords)
        transposed.push_back(chord.transpose(semitones));
    return ChordProgression(transposed);
}

static std::string chordToRoman(const Chord &chord, Note key) {
    int diff = ((int)chord.getRootNote() - (int)key + 12) % 12;
    auto [uppercaseRN, lowercaseRN] = getRomanNumeralBase(diff);
    bool isUpper = false;
    switch (chord.getQuality()) {
        case Major:
        case Augmented:
            isUpper = true;
            break;
        case Minor:
        case Diminished:
        case HalfDiminished:
            isUpper = false;
            break;
    }
    std::string label = (isUpper ? uppercaseRN : lowercaseRN);
    switch (chord.getQuality()) {
        case Augmented:
            label += "+";
            break;
        case Diminished:
            label += "°";
            break;
        case HalfDiminished:
            label += "ø";
            break;
        default:
            break;
    }
    if (!chord.getExtension().empty())
        label += chord.getExtension();
    return label;
}

std::string ChordProgression::toRomanNumerals(Note key) const {
    std::ostringstream oss;
    for (size_t i = 0; i < chords.size(); ++i) {
        oss << chordToRoman(chords[i], key);
        if (i != chords.size() - 1)
            oss << " ";
    }
    return oss.str();
}

std::ostream &operator<<(std::ostream &os, const ChordProgression &cp) {
    os << "[ ";
    for (const auto &chord : cp.chords)
        os << chord << " ";
    os << "]";
    return os;
}
