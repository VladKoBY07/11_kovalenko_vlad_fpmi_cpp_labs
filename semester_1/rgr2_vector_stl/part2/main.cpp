#include "time_utility.h"
#include "train.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

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

size_t to_seconds(size_t hours, size_t mins)
{
    return hours * 3600 + mins * 60;
}

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

        std::time_t travel_time = to_seconds(travel_hours, travel_minutes);

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

void SortByDispatchTime(std::vector<Train>& trains_list)
{
    std::sort(trains_list.begin(), trains_list.end(),
    [](const Train& first, const Train& second)
    {
        return first.GetDispatchTime() < second.GetDispatchTime();
    });
}

void PrintTrainsInTimePeriod(const std::vector<Train>& trains_list, std::time_t begin_time, std::time_t end_time)
{
    bool found_trains = false;
    for(int i = 0; i < trains_list.size(); ++i)
    {
        std::time_t disp_time = trains_list[i].GetDispatchTime();
        if((disp_time >= begin_time) && (disp_time <= end_time))
        {
            PrintTrainInfo(trains_list[i]);
            found_trains = true;
        }
    }

    if(!found_trains)
    {
        std::cout << "На этом интервале поездов нет" << std::endl;
    }
}

void PrintTrainsWithDestination(const std::vector<Train>& trains_list, const std::string& destination)
{
    bool found_trains = false;
    for(int i = 0; i < trains_list.size(); ++i)
    {
        if(trains_list[i].GetDestination() == destination)
        {
            PrintTrainInfo(trains_list[i]);
            found_trains = true;
        }
    }

    if(!found_trains)
    {
        std::cout << "В этом направлении поездов нет" << std::endl;
    }
}

void PrintTrainsWithTypeAndDestination(const std::vector<Train>& trains_list, const TrainType type, const std::string& destination)
{
    bool found_trains = false;
    for(int i = 0; i < trains_list.size(); ++i)
    {
        if(( trains_list[i].GetType() == type )&&( trains_list[i].GetDestination() == destination ))
        {
            PrintTrainInfo(trains_list[i]);
            found_trains = true;
        }
    }

    if(!found_trains)
    {
        std::cout << "Поездов такого типа в этом направлении нет" << std::endl;
    }
}

void FindFastestTrainWithDestination(const std::vector<Train>& trains_list, const std::string& destination)
{
    bool found_trains_destination = false;
    std::time_t min_time;
    int fastest_index;
    for(int i = 0; i < trains_list.size(); ++i)
    {
        if(trains_list[i].GetDestination() == destination)
        {
            min_time = trains_list[i].GetTravelTime();
            fastest_index = i;
            found_trains_destination = true;
            break;
        }
    }

    if(found_trains_destination)
    {
        for(int i = 0; i < trains_list.size(); ++i)
        {
            if((trains_list[i].GetDestination() == destination)&&(trains_list[i].GetTravelTime() < min_time))
            {
                min_time = trains_list[i].GetTravelTime();
                fastest_index = i;
            }
        }
        PrintTrainInfo(trains_list[fastest_index]);
    }
    else
    {
        std::cout << "В этом направлении нет поездов" << std::endl;
    }
}

int main()
{
    try
    {
        std::cout << "---Программа для управления расписанием поездов---" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        std::string inputfile = "Input.txt";
        std::cout << "Чтение файла " << inputfile << " ..." << std::endl;
        std::vector<Train> trains_list = ReadFile(inputfile);

        if(trains_list.empty())
        {
            throw "Error! Failed to upload data";
        }

        std::cout << "Успешно загружено " << trains_list.size() << " поездов!" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        std::cout << "Сортировка поездов по времени отправления поездов:" << std::endl;
        SortByDispatchTime(trains_list);
        PrintList(trains_list);
        std::cout << "--------------------------------------------------" << std::endl;
        
        std::cout << "Все поезда, отправляющиеся с 8.00 до 12.00:" << std::endl;
        std::time_t begin_time = time_utility::SetTime(8, 0);
        std::time_t end_time = time_utility::SetTime(12, 0);
        PrintTrainsInTimePeriod(trains_list, begin_time, end_time);
        std::cout << "--------------------------------------------------" << std::endl;

        std::cout << "Все поезда, направляющиеся в Москву:" << std::endl;
        std::string destination_search = "Москва";
        PrintTrainsWithDestination(trains_list, destination_search);
        std::cout << "--------------------------------------------------" << std::endl;

        std::cout << "Все высокоскоростные поезда, направляющиеся в Москву:" << std::endl;
        std::string destination_search_second = "Москва";
        TrainType type_search = TrainType::HIGH_SPEED;
        PrintTrainsWithTypeAndDestination(trains_list, type_search, destination_search_second);
        std::cout << "--------------------------------------------------" << std::endl;

        std::cout << "Самый быстрый поезд, направляющийся в Москву:" << std::endl;
        std::string destination_search_third = "Москва";
        FindFastestTrainWithDestination(trains_list, destination_search_third);
        std::cout << "--------------------------------------------------" << std::endl;
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