#include <iostream>
#include <chrono>

inline std::chrono::time_point<std::chrono::high_resolution_clock> begin_aoc(int number, int part)
{
    std::cout << ">>> PART_" << part << " - AOC_" << number << std::endl;
    return std::chrono::high_resolution_clock::now();
}

inline void end_aoc(std::chrono::time_point<std::chrono::high_resolution_clock> start_time)
{
    auto stop_time = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_time - start_time);
    std::cout << " <<< ENDED IN " << duration.count() << " MICROSECONDS" << std::endl; 
}