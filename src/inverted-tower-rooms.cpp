#include "inverted-tower-rooms.h"

#include <iostream>
#include <limits>

void printNeededFloorAndRoom(std::uint64_t room_number) {
  std::uint64_t total_floors = 0;
  std::uint64_t group = 1;
  std::uint64_t rooms_in_group;

  const std::uint64_t MAX_ITERATIONS = 10000000;
  std::uint64_t iterations = 0;

  while (true) {
    iterations++;
    if (iterations > MAX_ITERATIONS) {
      std::cerr << "Error: Maximum iterations exceeded. Possible infinite loop."
                << '\n';
      return;
    }

    if (group > std::numeric_limits<std::uint64_t>::max() / group) {
      rooms_in_group = std::numeric_limits<std::uint64_t>::max();
    } else {
      rooms_in_group = group * group;
    }

    if (room_number <= rooms_in_group) {
      break;
    }

    total_floors += group;
    room_number -= rooms_in_group;
    group++;

    if (group == 0) {
      std::cerr << "Error: Group overflow detected." << '\n';
      return;
    }
  }

  std::uint64_t floor_in_group = (room_number - 1) / group;
  std::uint64_t room_on_floor = ((room_number - 1) % group) + 1;

  std::uint64_t floor_number = total_floors + floor_in_group + 1;

  std::cout << floor_number << " " << room_on_floor << "\n";
}