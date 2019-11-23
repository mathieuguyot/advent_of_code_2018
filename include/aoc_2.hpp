#ifndef DEF_AOC_2_HPP
#define DEF_AOC_2_HPP

#include <string>
#include <vector>

typedef std::vector<std::string> BoxIds;

BoxIds parse_box_ids_file(const std::string& file_path);
int checksum(const BoxIds& box_ids);
std::string prototype_box_id(const BoxIds& box_ids);

#endif