#include "aoc_2.hpp"

#include <fstream>
#include <algorithm>

using namespace std;

BoxIds parse_box_ids_file(const string& file_path)
{
    BoxIds box_ids;

    ifstream box_ids_file_stream;
    box_ids_file_stream.open(file_path);
    if(!box_ids_file_stream.fail())
    {
        string box_id;
        while(!box_ids_file_stream.eof()) {
            getline(box_ids_file_stream, box_id);
            if(!box_id.empty())
            {
                box_ids.push_back(box_id);
            }
        }
    }

    return box_ids;
}

int checksum(const BoxIds& box_ids)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int two_same_letters_box_ids_count = 0;
    int three_same_letters_box_ids_count = 0;
    for(auto& box_id : box_ids)
    {
        bool two_same_letters_found = false;
        bool three_same_letters_found = false;
        for(char letter : alphabet)
        {
            int letter_count = count_if(box_id.begin(), box_id.end(), [letter](char current_letter){return letter == current_letter;});
            if(letter_count == 2)
            {
                two_same_letters_found = true;
            }
            if(letter_count == 3)
            {
                three_same_letters_found = true;   
            }
            if(two_same_letters_found && three_same_letters_found) 
            {
                break;
            }
        }
        if(two_same_letters_found)
        {
            two_same_letters_box_ids_count++;
        }
        if(three_same_letters_found)
        {
            three_same_letters_box_ids_count++;
        }
    }
    int checksum = two_same_letters_box_ids_count * three_same_letters_box_ids_count;
    return checksum;
}

string prototype_box_id(const BoxIds& box_ids)
{
    for(int i = 0 ; i < box_ids.size() ; i++)
    {
        for(int j = i ; j < box_ids.size() ; j++)
        {
            if(i != j)
            {
                const string& box_id_1 = box_ids[i];
                const string& box_id_2 = box_ids[j];
                int index = 0;
                int last_difference_index = 0;
                int differences = count_if(box_id_1.begin(), box_id_1.end(), 
                    [&](char letter) {
                        if(letter != box_id_2[index])
                        {
                            last_difference_index = index; 
                        }
                        return letter != box_id_2[index++];
                    }
                );
                if(differences == 1)
                {
                    string res = string(box_id_1).erase(last_difference_index, 1);
                    return res;
                }
            }
        }
    }
    return "";
}