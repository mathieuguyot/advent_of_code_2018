#include <catch.hpp>

#include "aoc_2.hpp"
#include "utils.hpp"

using namespace std;    

TEST_CASE("AOC2 - PART 1", "[checksum]") 
{
    auto start_time = begin_aoc(2, 1);
	
    BoxIds box_ids = parse_box_ids_file("./data/box_ids.txt");
    int res = checksum(box_ids);

    cout << res << endl;
    REQUIRE(res == 7688);

    end_aoc(start_time);
}

TEST_CASE("AOC2 - PART 2", "[prototype_box_id]") 
{
    auto start_time = begin_aoc(2, 2);
	
    BoxIds box_ids = parse_box_ids_file("./data/box_ids.txt");
    string res = prototype_box_id(box_ids);

    cout << res << endl;
    REQUIRE(res == "lsrivmotzbdxpkxnaqmuwcchj");

    end_aoc(start_time);
}

TEST_CASE("AOC2 - bad path", "[parse_box_ids_file]") 
{
	REQUIRE(parse_box_ids_file("foo.txt").size() == 0);
}

TEST_CASE("AOC2 - good path", "[parse_box_ids_file]") 
{
    BoxIds box_ids = parse_box_ids_file("./data/box_ids.txt");
	REQUIRE(box_ids.size() == 250);
    REQUIRE(box_ids[0] == "lsrivfotzgdxpkefaqmuiygchj");
    REQUIRE(box_ids[249] == "lsrivfotzbdxphenaqmuwyghvj");
}
