#include "chordProgression.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>

// --- Constructors ---
ChordProgression::ChordProgression() : chords() { }

ChordProgression::ChordProgression(const std::vector<Chord>& chords)
    : chords(chords) { }

// This constructor builds a chord progression from a list of roman numeral strings and a key.
ChordProgression::ChordProgression(const std::vector<std::string>& romanNumerals, Note key) {
    // For each roman numeral string, convert it into a Chord relative to the given key.
    for (const auto &roman : romanNumerals) {
        // Use the helper function defined below.
        // If conversion fails, an exception will be thrown.
        auto chord = [] (const std::string &romanStr, Note key) -> Chord {
            // Define a helper struct for roman numeral mapping.
            struct RomanMapping {
                std::string numeral;
                int offset; // semitone offset from key (0-based)
                Quality defaultQuality;
            };
            // The order is chosen from longest to shortest to avoid premature matches.
            const std::vector<RomanMapping> romanMappings = {
                { "vii", 11, Diminished },
                { "iii", 4, Minor },
                { "ii", 2, Minor },
                { "vi", 9, Minor },
                { "IV", 5, Major },
                { "V", 7, Major },
                { "I", 0, Major }
            };

            // Attempt to match one of the known roman numeral digits.
            RomanMapping mapping;
            bool found = false;
            size_t numeralLength = 0;
            for (const auto &rm : romanMappings) {
                if (romanStr.size() >= rm.numeral.size() &&
                    romanStr.compare(0, rm.numeral.size(), rm.numeral) == 0) {
                    mapping = rm;
                    numeralLength = rm.numeral.size();
                    found = true;
                    break;
                }
            }
            if (!found)
                throw std::invalid_argument("Invalid roman numeral: " + romanStr);

            // Determine chord quality. Start with the default.
            Quality qual = mapping.defaultQuality;
            size_t pos = numeralLength;

            // Check if a quality modifier is present.
            // Allowed modifiers: '+' for Augmented, '°' for Diminished, 'ø' for HalfDiminished.
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
            // Whatever remains is treated as an extension.
            std::string ext = (pos < romanStr.size()) ? romanStr.substr(pos) : "";

            // Compute the root note relative to the key.
            // Our Note enum is 1-indexed.
            int keyVal = static_cast<int>(key);
            int newVal = ((keyVal - 1 + mapping.offset) % 12 + 12) % 12 + 1;
            Note newRoot = static_cast<Note>(newVal);

            return Chord(newRoot, qual, ext);
        }(roman, key);
        chords.push_back(chord);
    }
}

// --- Manipulation Methods ---
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

// --- Transposition ---
ChordProgression ChordProgression::transpose(int semitones) const {
    std::vector<Chord> transposed;
    for (const auto &chord : chords) {
        transposed.push_back(chord.transpose(semitones));
    }
    return ChordProgression(transposed);
}

// --- Roman Numeral Analysis (Chord to Roman) ---
//
// This helper function converts a single chord to its roman numeral
// representation relative to a given key (assumed major). For chords whose
// root is not diatonic (i.e. not at intervals 0,2,4,5,7,9,11 from the key),
// a marker ("?") is prepended.
static std::string chordToRoman(const Chord &chord, Note key) {
    // Calculate the interval (in semitones) from the key.
    int diff = ((int)chord.getRootNote() - (int)key + 12) % 12;
    std::string ext = chord.getExtension();
    
    switch(diff) {
        case 0: // I
            if(chord.getQuality() == Major)
                return "I" + ext;
            else if(chord.getQuality() == Minor)
                return "i" + ext;
            else if(chord.getQuality() == Augmented)
                return "I+" + ext;
            else if(chord.getQuality() == Diminished)
                return "i°" + ext;
            else if(chord.getQuality() == HalfDiminished)
                return "iø" + ext;
            break;
        case 2: // ii
            if(chord.getQuality() == Minor)
                return "ii" + ext;
            else if(chord.getQuality() == Major)
                return "II" + ext;
            else if(chord.getQuality() == Augmented)
                return "ii+" + ext;
            else if(chord.getQuality() == Diminished)
                return "ii°" + ext;
            else if(chord.getQuality() == HalfDiminished)
                return "iiø" + ext;
            break;
        case 4: // iii
            if(chord.getQuality() == Minor)
                return "iii" + ext;
            else if(chord.getQuality() == Major)
                return "III" + ext;
            else if(chord.getQuality() == Augmented)
                return "iii+" + ext;
            else if(chord.getQuality() == Diminished)
                return "iii°" + ext;
            else if(chord.getQuality() == HalfDiminished)
                return "iiiø" + ext;
            break;
        case 5: // IV
            if(chord.getQuality() == Major)
                return "IV" + ext;
            else if(chord.getQuality() == Minor)
                return "iv" + ext;
            else if(chord.getQuality() == Augmented)
                return "IV+" + ext;
            else if(chord.getQuality() == Diminished)
                return "iv°" + ext;
            else if(chord.getQuality() == HalfDiminished)
                return "ivø" + ext;
            break;
        case 7: // V
            if(chord.getQuality() == Major)
                return "V" + ext;
            else if(chord.getQuality() == Minor)
                return "v" + ext;
            else if(chord.getQuality() == Augmented)
                return "V+" + ext;
            else if(chord.getQuality() == Diminished)
                return "v°" + ext;
            else if(chord.getQuality() == HalfDiminished)
                return "vø" + ext;
            break;
        case 9: // vi
            if(chord.getQuality() == Minor)
                return "vi" + ext;
            else if(chord.getQuality() == Major)
                return "VI" + ext;
            else if(chord.getQuality() == Augmented)
                return "vi+" + ext;
            else if(chord.getQuality() == Diminished)
                return "vi°" + ext;
            else if(chord.getQuality() == HalfDiminished)
                return "viø" + ext;
            break;
        case 11: // vii
            if(chord.getQuality() == Diminished)
                return "vii°" + ext;
            else if(chord.getQuality() == Minor)
                return "vii" + ext;
            else if(chord.getQuality() == Major)
                return "VII" + ext;
            else if(chord.getQuality() == Augmented)
                return "vii+" + ext;
            else if(chord.getQuality() == HalfDiminished)
                return "viiø" + ext;
            break;
        default:
            break;
    }
    // For non-diatonic chords (or unmatched qualities), prepend a marker.
    return "?" + chord.toString();
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

// --- Overloaded Stream Insertion Operator ---
std::ostream &operator<<(std::ostream &os, const ChordProgression &cp) {
    os << "[ ";
    for (const auto &chord : cp.chords) {
        os << chord << " ";
    }
    os << "]";
    return os;
}

