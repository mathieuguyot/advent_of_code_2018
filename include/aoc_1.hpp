#ifndef DEF_AOC_1_HPP
#define DEF_AOC_1_HPP

#include <string>
#include <vector>

typedef std::vector<int> Frequencies;

Frequencies parse_frequency_file(std::string file_path); 
int frequency_sum(const Frequencies& frequencies);
int first_twice_reached_frequecy(const Frequencies& frequencies);

#endif