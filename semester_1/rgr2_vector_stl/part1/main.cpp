#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <cmath>

void print_vector(std::vector<int>& vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void enter_vector_line(std::istream& instream, std::vector<int>& vec)
{
    std::string line;
    std::getline(instream, line);

    std::stringstream strstream(line);
    int number;

    while(strstream >> number)
    {
        vec.push_back(number);
    }

    if(!strstream.eof())
    {
        throw "Error: wrong input";
    }
}

int main() {

    try
    {
        std::vector<int> vec1;
        enter_vector_line(std::cin, vec1);
//
        std::cout << "Summ of elements: ";
        std::cout << std::accumulate(vec1.begin(), vec1.end(), 0) << std::endl;
//
        std::cout << "Amount of elements: ";
        std::cout << vec1.size() << std::endl;
//
        const int comp_element = 3;
        std::cout << "Amount of elements equal to " << comp_element << ": ";
        std::cout << std::count(vec1.begin(), vec1.end(), comp_element) << std::endl;
//
        const int more_than_element = 5;
        std::cout << "Amount of elements more than " << more_than_element << ": ";
        std::cout << std::count_if(vec1.begin(), vec1.end(), [](int n) {return n > more_than_element;}) << std::endl;
//
        std::cout << "Vector after 0 is changed to mid value: ";
        int sum = std::accumulate(vec1.begin(), vec1.end(), 0);
        int amount = vec1.size();
        int midnumber = sum / amount;
        for(int& element : vec1)
        {
            if(element == 0)
            {
                element = midnumber;
            }
        }
        print_vector(vec1);
//
        std::cout << "Add sum of interval ";
        const int beg_index = 3, end_index = 5;
        std::cout << "from " << beg_index << " to " << end_index << ": ";
        int interval_sum = std::accumulate(vec1.begin() + beg_index - 1, vec1.begin() + end_index, 0);
        for(int i = 0; i < vec1.size(); ++i)
        {
            vec1.at(i) += interval_sum;
        }
        print_vector(vec1);
//
        std::cout << "Change even numbers to max-min: ";
        auto max = std::max_element(vec1.begin(), vec1.end());
        auto min = std::min_element(vec1.begin(), vec1.end());
        int difference = *max - *min;
        for(int i = 0; i < vec1.size(); ++i)
        {
            if(std::abs(vec1.at(i)) % 2 == 0)
            {
                vec1.at(i) = difference;
            }
        }
        print_vector(vec1);
//
        std::cout << "Delete abs-equal numbers: ";
        for(std::vector<int>::iterator i = vec1.begin(); i != vec1.end(); i++)
        {
            int abs = std::abs(*i);
            std::vector<int>::iterator it = i;
            it++;
            while(it != vec1.end())
            {
                if (*it == abs)
                {
                    it = vec1.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
        print_vector(vec1);
    }
    catch(const char* msg)
    {
        std::cerr << msg << std::endl;
        return 1;
    }
    catch(std::out_of_range)
    {
        std::cerr << "Error: Out of range!";
        return 1;
    }
    catch(...)
    {
        std::cerr << "Unknown Error!" << std::endl;
        return 1;
    }

    return 0;
}