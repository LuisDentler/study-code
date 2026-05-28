#ifndef DRONE_TEST_BENCH_HPP
#define DRONE_TEST_BENCH_HPP

#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <string>






template <typename T>
struct DataSetReport{
    T max;
    T sum;
    T average;
};
template<>
struct DataSetReport<bool>{
    bool enoughTrue;
};



/*
@brief Swap two Values

Template is used to reduce 3 nearly identical functions to one function for all data types.

@param[in] value1 - The first value to swap
@param[in] value2 - The second value to swap    
*/
template <typename T>
void swapValue(T& value1, T& value2){
    T tmp = value1;
    value1 = value2;
    value2 = tmp;
}

/*
@brief Print Sensor Frames

Prints out all Values of the Array SensorFrames
@param[in] sensorFrames - Array of the Sensor Frames to print
*/
template <typename T, const int size>
void printSensorFrames(const T (&sensorFrames)[size]){
    if(sensorFrames != nullptr){
        std::cout << "Sensor Frames: " ;
        for(std::size_t i=0; i<size; ++i){
            std::cout <<"[" << sensorFrames[i] <<"]"; 
        }
        std::cout << std::endl;
    }
}

/*
@brief Get Weakest Measurement

Returns the weakest measurement from the Array SensorFrames
@param[in] sensorFrames - Array of the Sensor Frames to analyze
*/
template <typename T, const int size>
T getWeakestMessure(const T (&sensorFrames)[size]){
    T weakest = 0;
    if(sensorFrames != nullptr){
        T weakest = sensorFrames[0];
        for(std::size_t i=1; i<N; ++i){
            if(sensorFrames[i] < weakest){
                weakest = sensorFrames[i];
            }
        }
    }else{
        std::cout << "Error: sensorFrames is a null pointer." << std::endl;
    }
    return weakest;
}

/*
@brief Print Sensor Metadata

Prints out the metadata for a specific sensor
@param[in] label1 - The label for the first value
@param[in] value1 - The first value to print
@param[in] label2 - The label for the second value
@param[in] metadata - The metadata to print
*/
template <typename T, typename U>
void printSensorMetadata(const std::string& label1, const T& value1, const std::string& label2, const U& metadata){
    std::cout << label1 << ": " << value1 << " " << label2 << ": " << metadata << std::endl;
}


/*
@brief Print Vector

Prints out all Values of the Vector
@param[in] vec - The vector to print
*/
template <typename T>
void printVector(const std::vector<T>& vec){
    for(const auto& value : vec){
        std::cout << value << " ";
    }
    std::cout << std::endl;
}


//------------------SECTION 3------------------


template <typename T>
DataSetReport<T> analyzeDataSet(const std::vector<T>& dataset){
        DataSetReport<T> report;

        auto max = std::max_element(dataset.begin(), dataset.end());
        auto sum = std::accumulate(dataset.begin(),dataset.end(), T{});
        auto avarage = static_cast<double>(sum) / static_cast<double>(dataset.size());

        report.max = *max;
        report.sum = sum;
        report.average = avarage;

        return report;
        
}

template<>
DataSetReport<bool> analyzeDataSet(const std::vector<bool>& dataset){
    DataSetReport<bool> report;
    auto report_sum = std::count(dataset.begin(), dataset.end(), true);
    if(report_sum > dataset.size() / 2){
        report.enoughTrue = true;
    }else{
        report.enoughTrue = false;
    }
  
    return report;
}



template <typename T>
void reportDataSet(const std::vector<T>& dataset){
    if(dataset.empty()){
        std::cout << "Error: Dataset is empty!" <<std::endl;
    }else{
        std::cout << "Data Set: ";
        for(const auto&data : dataset){
            std::cout << data << " ";
        }
        std::cout << std::endl;

        auto report = analyzeDataSet(dataset);
        std::cout << "Data Set Report:" << std::endl;
        std::cout << "Max: " << report.max << std::endl;
        std::cout << "Sum: " << report.sum << std::endl;
        std::cout << "Average: " << report.average << std::endl;
    }
}

template<>
void reportDataSet(const std::vector<bool>& dataset){
    if(dataset.empty()){
        std::cout << "Error: Dataset is empty!" <<std::endl;
    }else{
        std::cout << "Data Set: ";
        auto report = analyzeDataSet(dataset);
        std::cout << "Data Set Report:" << std::endl;
        std::cout << "Enough True: " << std::boolalpha << report.enoughTrue << std::endl;
    }
}


template <typename T, std::size_t N>
std::vector<T> swapArrayToVector(const std::array<T, N>& frame) {
    return std::vector<T>(frame.begin(), frame.end());
}




#endif 