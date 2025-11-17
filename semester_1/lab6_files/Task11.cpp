#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdint>

bool FileIsEmpty (std::ifstream& fileStream)
{
    return fileStream.peek() == std::ifstream::traits_type::eof();
}

void ReadDataFromFile (std::vector<std::string> &READvector, const std::string& filename)
{
    std::ifstream inStream (filename);
    if(!(inStream.is_open()))
    {
        throw "Error! Could not open a file: " + filename;
    }
    if(FileIsEmpty(inStream))
    {
        throw "Error! File: " + filename + " is empty!";
    }

    std::string line;
    while(getline(inStream, line))
    {
        READvector.push_back(line);
    }
}

void PrintVector (std::vector<std::string> &Vector)
{
    int VectorSize = Vector.size();
    for(int i = 0; i < VectorSize; ++i)
    {
        std::cout << Vector[i] << std::endl;
    }
}

int Find_Line_With_Min_word (std::vector<std::string> &Vector)
{
    std::string::size_type begIndex = Vector[0].find_first_not_of(" ");
    std::string::size_type endIndex = Vector[0].find_first_of(" ", begIndex);
    int MinWordSize = endIndex - begIndex;

    int LinesAmount = Vector.size();
    int LineNumber = 0;
    for(int line = 0; line < LinesAmount; ++line)
    {
        std::string::size_type begIndex = Vector[line].find_first_not_of(" ");
        std::string::size_type endIndex = Vector[line].find_first_of(" ", begIndex);
        while(begIndex != std::string::npos)
        {
            int WordSize = endIndex - begIndex;
            if((WordSize != 0) && (WordSize < MinWordSize))
            {
                MinWordSize = WordSize;
                LineNumber = line;
            }
            begIndex = Vector[line].find_first_not_of(" ", endIndex);
            endIndex = Vector[line].find(" ", begIndex);
            if(endIndex == std::string::npos){ endIndex = Vector[line].size(); }
        }
    }
    //std::cout << MinWordSize << std::endl;
    return LineNumber;
}

int Find_Line_With_Max_word (std::vector<std::string> &Vector)
{
    std::string::size_type begIndex = Vector[0].find_first_not_of(" ");
    std::string::size_type endIndex = Vector[0].find_first_of(" ", begIndex);
    int MaxWordSize = endIndex - begIndex;

    int LinesAmount = Vector.size();
    int LineNumber = 0;
    for(int line = 0; line < LinesAmount; ++line)
    {
        std::string::size_type begIndex = Vector[line].find_first_not_of(" ");
        std::string::size_type endIndex = Vector[line].find_first_of(" ", begIndex);
        while(begIndex != std::string::npos)
        {
            int WordSize = endIndex - begIndex;
            if((WordSize != 0) && (WordSize > MaxWordSize))
            {
                MaxWordSize = WordSize;
                LineNumber = line;
            }
            begIndex = Vector[line].find_first_not_of(" ", endIndex);
            endIndex = Vector[line].find(" ", begIndex);
            if(endIndex == std::string::npos){ endIndex = Vector[line].size(); }
        }
    }
    //std::cout << MinWordSize << std::endl;
    return LineNumber;
}

void SwapLines(std::vector<std::string> &Vector, int line1, int line2)
{
    std::swap(Vector[line1], Vector[line2]);
}

int main()
{
    const std::string inputFile ("Input.txt");
    
    try
    {
        std::vector<std::string> READvector;
        ReadDataFromFile(READvector, inputFile);

        std::cout << "Readed information: " << std::endl;
        std::cout << "-----------------" << std::endl;
        PrintVector(READvector);
        std::cout << "-----------------" << std::endl;

        //std::cout << "Line with min word: " << Find_Line_With_Min_word(READvector) << std::endl;
        //std::cout << "Line with max word: " << Find_Line_With_Max_word(READvector) << std::endl;
        SwapLines(READvector, Find_Line_With_Min_word(READvector), Find_Line_With_Max_word(READvector));

        std::cout << "Changed information: " << std::endl;
        std::cout << "-----------------" << std::endl;
        PrintVector(READvector);
        std::cout << "-----------------" << std::endl;
    }
    catch(const std::string& msg)
    {
        std::cerr << msg << std::endl;
    }
    catch(...)
    {
        std::cerr << "Unknown Error!" << std::endl;
    }
}