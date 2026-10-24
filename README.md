# Huffman Coding Simulator

A C++ console program that demonstrates Huffman coding, a lossless data
compression algorithm. It takes text as input, builds a Huffman tree, and
shows each character's frequency, its binary code, and the compression result.

## Features
- Counts the frequency of every character in the input
- Builds the Huffman tree using a min-priority queue
- Generates a unique prefix-free binary code for each character
- Encodes the full text
- Compares original size (8 bits per character) vs encoded size

## How It Works
1. Count how often each character appears.
2. Put each character into a min-priority queue as a leaf node.
3. Repeatedly remove the two lowest-frequency nodes and merge them into a
   parent node whose frequency is their sum, until one node (the root) remains.
4. Traverse the tree: left edge = `0`, right edge = `1`. The path to each leaf
   is that character's code.
5. Replace each character in the text with its code.

Frequent characters get shorter codes, rare ones get longer codes, which
reduces the total number of bits.

## Technologies Used
- C++ (STL: `priority_queue`, `map`, `string`, `vector`)

## Requirements
- A C++ compiler with C++11 or later support (e.g., g++)

## Build and Run
```bash
g++ huffmancodingsimulator.cpp -o huffman
./huffman          # on Windows: huffman.exe
```

## Example
```
Enter text: hello

Character frequencies and codes:
e  Frequency: 1  Code: 00
h  Frequency: 1  Code: 01
l  Frequency: 2  Code: 1
o  Frequency: 1  Code: ...

Original size: 40 bits
Encoded size: ... bits
```
(Replace with your real output: run the program and paste it.)

## Project Structure
```
.
├── huffmancodingsimulator.cpp
└── README.md
```

## Limitations
- Only encodes; no decoding feature yet
- The code table isn't saved, so the output can't be decompressed on its own
- Reads a single line of input

## Future Improvements
- Add a decoder to reconstruct the original text
- Read from and write to files
- Free allocated tree memory (currently never `delete`d)
- Display the Huffman tree visually
