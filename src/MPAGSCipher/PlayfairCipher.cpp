#include "PlayfairCipher.hpp"

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

    // Append the alphabet to the key
    key_ += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Make sure the key is upper case
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),::toupper);

    // Remove non-alphabet characters
    auto iter = std::remove_if(std::begin(key_), std::end(key_),[](const char c) { return !std::isalpha(c); });
    key_.erase(iter, std::end(key_));

    // Change J -> I
    std::transform(std::begin(key_), std::end(key_), std::begin(key_), [](const char c) { return c == 'J' ? 'I' : c; });

    // Remove duplicated letters


    // Store the coordinates of each letter
    // The grid is 5x5, so calculate row and column from index

    

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
