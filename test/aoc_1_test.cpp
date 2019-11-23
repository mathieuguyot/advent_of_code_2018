#include <catch.hpp>

#include "aoc_1.hpp"
#include "utils.hpp"

using namespace std;

TEST_CASE("AOC1 - PART 1", "[frequency_sum]") 
{
    auto start_time = begin_aoc(1, 1);
	
    Frequencies frequencies = parse_frequency_file("./data/frequencies.txt");
    int res = frequency_sum(frequencies);
    
    cout << res << endl;
    REQUIRE(res == 574);

    end_aoc(start_time);
}

TEST_CASE("AOC1 - PART 2", "[first_twice_reached_frequecy]") 
{
    auto start_time = begin_aoc(1, 2);
	
    Frequencies frequencies = parse_frequency_file("./data/frequencies.txt");
    int res = first_twice_reached_frequecy(frequencies);
    
    cout << res << endl;
    REQUIRE(res == 452);

    end_aoc(start_time);
}

TEST_CASE("AOC1 - bad path", "[parse_frequency_file]") 
{
	REQUIRE(parse_frequency_file("foo.txt").size() == 0);
}

TEST_CASE("AOC1 - good path", "[parse_frequency_file]") 
{
    Frequencies frequencies = parse_frequency_file("./data/frequencies.txt");
	REQUIRE(frequencies.size() == 999);
    REQUIRE(frequencies[0] == 13);
    REQUIRE(frequencies[2] == -8);
    REQUIRE(frequencies[998] == 80339);
}
