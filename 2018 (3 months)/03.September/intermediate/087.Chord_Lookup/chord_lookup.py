#!/usr/bin/python


notes = {   "C" : 0,
            "C#": 1,
            "D" : 2,
            "D#": 3,
            "E" : 4,
            "F" : 5,
            "F#": 6,
            "G" : 7,
            "G#": 8,
            "A" : 9,
            "A#": 10,
            "B" : 11
}
nNotes = 12;

chordType = [["",0,4,7], ["m",0,3,7], ["7",0,4,7,10], ["m7",0,3,7,10], ["maj7",0,4,7,11]]

def splitChord(stringChord):
    if stringChord.find("#") == -1:
        x = [stringChord[0], stringChord[1:6]]
    else:
        x = [stringChord[0:2], stringChord[2:6]]
    return x

def chordLookup(note, chord):
    chordNotes = []
    for t in chordType:
        if t[0] is chord:
            for x in t:
                if t[0] is x:
                    continue
                noteNumber = (notes[note] + x) % nNotes
                intToNote = [name for name, number in notes.items() if number == noteNumber]
                chordNotes.append(intToNote)
    return chordNotes


while True:
    stringChord = input("Enter a chord: ")

    chord = splitChord(stringChord)
    chordNotes = chordLookup(chord[0], chord[1])

    print(chordNotes)
