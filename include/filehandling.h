#pragma once

#include <fstream>
#include <vector>
#include <string>

using Byte=uint8_t;
using Short=uint16_t;
using Int=uint32_t;
using Long=uint64_t;

struct FILE_DATA{
    // number of characters in this file
    Long characterCount;    

    // character number (001 to characterCount)
    std::vector<Int> field1;
    // series id (0=Yu-Gi-Oh!, 5=Vrains)
    std::vector<Int> field2;
    // challenge deck id
    std::vector<Int> field3;
    // playable character flag
    std::vector<Int> field4;
    // old dlc flag
    std::vector<Int> field5;
    // field 6 ??? (1 for Bolt Tanner, Mr. Armstrong and Orbital 7, 0 for everyone else)
    std::vector<Int> field6;
    // challenge arena id
    std::vector<Int> field7;
    // field 8 ??? (always 0)
    std::vector<Int> field8;
    // pointer to character id name
    std::vector<Long> pointer1;
    // pointer to character name
    std::vector<Long> pointer2;
    // pointer to character bio
    std::vector<Long> pointer3;

    // character id name
    std::vector<std::string> string1;
    // character name
    std::vector<std::string> string2;
    // character bio
    std::vector<std::u16string> string3;
};

Byte ReadByte(std::ifstream &file);
Short ReadShort(std::ifstream &file);
Int ReadInt(std::ifstream &file);
Long ReadLong(std::ifstream &file);
std::u16string ReadString(std::ifstream &file);
std::string ReadByteString(std::ifstream &file);

void WriteByte(std::ofstream &file, Byte value);
void WriteShort(std::ofstream &file, Short value);
void WriteInt(std::ofstream &file, Int value);
void WriteLong(std::ofstream &file, Long value);
void WriteString(std::ofstream &file, const std::u16string &string);
void WriteByteString(std::ofstream &file, const std::string &string);

bool ReadFile(const std::string &filename, FILE_DATA &fileData);
bool SaveFile(const std::string &filename, FILE_DATA &fileData);

std::string IntToHexString(const Int &value);

void ClearFileData(FILE_DATA &fileData);
std::string SimplifyString(const std::string &string);