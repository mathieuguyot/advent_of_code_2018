#include "aoc_1.hpp"

#include <iostream>
#include <fstream>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

Frequencies parse_frequency_file(string frequency_file_path)
{
    Frequencies frequencies;
    ifstream frequency_file_stream;
    frequency_file_stream.open(frequency_file_path);
    if(!frequency_file_stream.fail())
    {
        string frequency;
        while(!frequency_file_stream.eof()) {
            getline(frequency_file_stream, frequency);
            if(!frequency.empty())
            {
                frequencies.push_back(atoi(frequency.c_str()));
            }
        }
    }
    return frequencies;
}

int frequency_sum(const Frequencies& frequencies)
{
    return accumulate(frequencies.begin(), frequencies.end(), 0);
}

int first_twice_reached_frequecy(const Frequencies& frequencies)
{
    int first_twice_reached_frequency = 0;
    set<int> reached_frequencies;
    reached_frequencies.insert(first_twice_reached_frequency);
    bool twice_reached_frequency_found = false;
    while(!twice_reached_frequency_found)
    {
        for(int current_frequency: frequencies)
        {   
            first_twice_reached_frequency += current_frequency;
            if(reached_frequencies.find(first_twice_reached_frequency) != reached_frequencies.end())
            {
                twice_reached_frequency_found = true;
                break;
            }
            else 
            {
                reached_frequencies.insert(first_twice_reached_frequency);
            }
        }
    }
    return first_twice_reached_frequency;
}
