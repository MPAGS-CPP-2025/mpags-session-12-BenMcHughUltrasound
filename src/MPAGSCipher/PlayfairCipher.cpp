#include "PlayfairCipher.hpp"
#include <iostream>
#include <algorithm>
#include <string>

/**
 * \file PlayfairCipher.cpp
 * \brief Contains the implementation of the PlayfairCipher class
 */

PlayfairCipher::PlayfairCipher(const std::string& key)
{
    this->setKey(key);
}

void PlayfairCipher::setKey(const std::string& key)
{
    // Store the original key
    key_ = key;

    // Debug output of the original key
    // std::cout << "Initial key: " << key_ << std::endl;

    // Append the alphabet to the key
    key_ += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Debug output of the appended key
    //std::cout << "Initial key + Alphabet: " << key_ << std::endl;

    // Make sure the key is upper case
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),::toupper);
    // Debug output of the upper case conversion
    //std::cout << "Upper case key: " << key_ << std::endl;

    // Remove non-alphabet characters
    auto iter = std::remove_if(std::begin(key_), std::end(key_),[](const char c) { return !std::isalpha(c); });
    key_.erase(iter, std::end(key_));

    // Debug output of the non-alphabet removal
    // std::cout << "Alphabet characters only key: " << key_ << std::endl;

    // Change J -> I
    std::transform(std::begin(key_), std::end(key_), std::begin(key_), [](const char c) { return c == 'J' ? 'I' : c; });
    
    // Debug output of the J -> I change
    //std::cout << "J -> I key: " << key_ << std::endl;

    // Remove duplicated letters

    // first declare a string to track which letters we've already encountered
    std::string encountered{}; 
    
  // Use remove_if to identify duplicates
    auto duplicateIter = std::remove_if(std::begin(key_), std::end(key_),
        [&encountered](const char c) {
  
            if (encountered.find(c) != std::string::npos) {
                // Found it - this is a duplicate, so remove it (return true)
                return true;
            }
            // Not found yet - add it to encountered and keep it (return false)
            encountered += c;
            return false;
        });
    
    // Step 3: Actually erase the duplicates (remove_if doesn't actually erase)
    key_.erase(duplicateIter, std::end(key_));

    // Store the coordinates of each letter
    // The grid is 5x5, so calculate row and column from index

    
    for (size_t i = 0; i < key_.size(); ++i) {
        // Calculate row and column from index
        const size_t row = i / 5;
        const size_t col = i % 5;
        
        // Create a coordinate pair
        const Coordinate coord{row, col};
        
        // Store both directions
        charToCoord_[key_[i]] = coord;      // char → coordinate
        coordToChar_[coord] = key_[i];      // coordinate → char
    }
    // debug output of the processed key
    //std::cout << "Processed key: " << key_ << std::endl;

    // Debug output of the maps
    // std::cout << "Character to Coordinate map:" << std::endl;
    // for (const auto& pair : charToCoord_) {
    //     std::cout << "  " << pair.first << " -> (" << pair.second.first << ", " << pair.second.second << ")" << std::endl;
    // }

    // std::cout << "Coordinate to Character map:" << std::endl;
    for (const auto& pair : coordToChar_) {
        std::cout << "  (" << pair.first.first << ", " << pair.first.second << ") -> " << pair.second << std::endl;
    }

}

std::string PlayfairCipher::applyCipher(const std::string& inputText,
                                        const CipherMode /*cipherMode*/) const
{
    // Create the output string, initially a copy of the input text
    std::string outputText{inputText};

    // Change J -> I

    // Find repeated characters and add an X (or a Q for repeated X's)

    // If the size of the input is odd, add a trailing Z

    // Loop over the input bigrams

    // - Find the coordinates in the grid for each bigram

    // - Apply the rules to these coords to get new coords

    // - Find the letters associated with the new coords

    // - Make the replacements

    // Return the output text
    return outputText;
}
