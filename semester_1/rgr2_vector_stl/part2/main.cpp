#include "time_utility.h"
#include "train.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// time_utility test?
/*int main() {

    using namespace time_utility;

    std::random_device rd;
    std::mt19937 generator(rd());

    std::time_t t1 = SetTime(12, 23);
    try {
        t1 = SetTime(12, 60);
    } catch (const std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }

    std::time_t t2 = GenerateRandomTime(generator);

    std::cout << "t1: ";
    PrintTime(t1);
    
    std::cout << "t2: ";
    PrintTime(t2);
    
    std::cout << "t1 < t2: " << std::boolalpha << (t1 < t2) <<'\n';
    std::cout << "t2 < t1: " << std::boolalpha << (t2 < t1) << '\n';



    return EXIT_SUCCESS;
}*/

std::vector<Train> ReadFile(const std::string& inputfile)
{
    std::vector<Train> all_trains;
    std::ifstream instream(inputfile);

    if(!(instream.is_open()))
    {
        throw "Error! Cannot open the file!";
    }

    std::string line;
    while(std::getline(instream, line))
    {
        std::istringstream lineStream(line);
        TrainId id;
        if(!(lineStream >> id))
        {
            throw "Error! Wrong train id detected";
        }
        std::string string_type, destination;
        if(!(lineStream >> string_type))
        {
            throw "Error! Wrong train type detected";
        }
        if(!(lineStream >> destination))
        {
            throw "Error! Wrong train destination detected";
        }

        size_t disp_hours, disp_minutes, travel_hours, travel_minutes;
        if(!(lineStream >> disp_hours >> disp_minutes))
        {
            throw "Error! Wrong data in dispatch time detected!";
        }
        if(!(lineStream >> travel_hours >> travel_minutes))
        {
            throw "Error! Wrong data in travel time detected!";
        }

        // преобразование данных
        TrainType type = Train::Select_train_type(string_type);
        std::time_t disp_time = time_utility::SetTime(disp_hours, disp_minutes);
        std::time_t travel_time = time_utility::SetTime(travel_hours, travel_minutes);

        Train new_train(id, type, destination, disp_time, travel_time);
        all_trains.push_back(new_train);
    }

    instream.close();
    return all_trains;
}

void PrintList(const std::vector<Train>& trains_list)
{
    for(int i = 0; i < trains_list.size(); ++i)
    {
        PrintTrainInfo(trains_list[i]);
    }
}

int main()
{
    try
    {
        std::cout << "---Программа для управления расписанием поездов---" << std::endl;
        std::cout << "--------------------------------------------------";

        std::string inputfile = "Input.txt";
        std::cout << "Чтение файла " << inputfile << " ..." << std::endl;
        std::vector<Train> trains_list;
        trains_list = ReadFile(inputfile);

        if(trains_list.empty())
        {
            throw "Error! Failed to upload data";
        }

        std::cout << "Успешно загружено " << trains_list.size() << " поездов!" << std::endl;
        std::cout << "--------------------------------------------------";

        std::cout << "Сортировка поездов по времени отправления поездов:";
        PrintList(trains_list);

    }
    catch(const char* msg)
    {
        std::cerr << msg << std::endl;
        return 1;
    }
    catch(...)
    {
        std::cerr << "Unknown error!" << std::endl;
        return 1;
    }
}