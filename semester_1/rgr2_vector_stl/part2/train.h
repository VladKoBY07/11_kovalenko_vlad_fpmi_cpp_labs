#pragma once

#include <string>
#include <iostream>
#include "time_utility.h"

using TrainId = size_t;
using namespace time_utility;


enum class TrainType { 
    PASSENGER, FREIGHT, HIGH_SPEED, SUBWAY, SPECIALIZED
};


class Train {
    friend void PrintTrainInfo(const Train&);
private:
    TrainId id_;   // номер поезда
    TrainType type_;   // тип поезда
    std::string destination_;   // название пункта назначения
    std::time_t dispatch_time_;   // время отправления
    std::time_t travelling_time_;   // время в пути (в секундах)

public:
    Train() = default;

    Train(TrainId id, TrainType type, const std::string& destination, std::time_t disp_time, std::time_t travel_time):
    id_(id), type_(type), destination_(destination), dispatch_time_(disp_time), travelling_time_(travel_time) {};

    std::time_t GetDispatchTime() const
    {
        return dispatch_time_;
    }

    std::time_t GetTravelTime() const
    {
        return travelling_time_;
    }

    std::string GetDestination() const
    {
        return destination_;
    }

    TrainType GetType() const
    {
        return type_;
    }

    // Ввод типа поезда
    static TrainType Select_train_type(const std::string& strtype)
    {
        //PASSENGER, FREIGHT, HIGH_SPEED, SUBWAY, SPECIALIZED
        if((strtype == "PASSENGER")||(strtype == "Passenger")||(strtype == "passenger"))
        {
            return TrainType::PASSENGER;
        }
        if((strtype == "FREIGHT")||(strtype == "Freight")||(strtype == "freight"))
        {
            return TrainType::FREIGHT;
        }
        if((strtype == "HIGH_SPEED")||(strtype == "High_speed")||(strtype == "high_speed"))
        {
            return TrainType::HIGH_SPEED;
        }
        if((strtype == "SUBWAY")||(strtype == "Subway")||(strtype == "subway"))
        {
            return TrainType::SUBWAY;
        }
        if((strtype == "SPECIALIZED")||(strtype == "Specialized")||(strtype == "specialized"))
        {
            return TrainType::SPECIALIZED;
        }
        return TrainType::SPECIALIZED;
    }
};

// печать информации о поезде
    void PrintTrainInfo(const Train& single_train)
    {
        std::cout << std::endl;
        std::cout << "Поезд №" << single_train.id_;
        std::string lable;
        switch (single_train.type_)
        {
        case TrainType::PASSENGER:
            lable = "Пассажирский";
            break;
        
        case TrainType::FREIGHT:
            lable = "Грузовой";
            break;

        case TrainType::HIGH_SPEED:
            lable = "Высокоскоростной";
            break;

        case TrainType::SUBWAY:
            lable = "Подземный";
            break;

        case TrainType::SPECIALIZED:
            lable = "Специальный";
            break;

        default:
            lable = "Не определен";
            break;
        }

        std::cout << " | " << "Тип: " << lable;
        std::cout << " | " << "Пункт назначения: " << single_train.destination_;
        std::cout << " | " << "Время отправления: ";
        time_utility::PrintTime(single_train.GetDispatchTime());

        std::cout << " | " << "Время в пути: ";
        std::time_t travel_sec = single_train.GetTravelTime();
        int hours = travel_sec / 3600;
        int mins = (travel_sec % 3600) / 60;
        std::cout << hours << " часов " << mins << " минут";
        
        std::cout << std::endl;
    }