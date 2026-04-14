#include "inverted-tower-rooms.h"

#include <iostream>

void printNeededFloorAndRoom(std::uint64_t room_number) {
  std::uint64_t total_floors = 0;
  std::uint64_t group = 1;
  std::uint64_t rooms_in_group;

  while (true) {
    rooms_in_group = group * group;

    if (room_number <= rooms_in_group) {
      break;
    }

    total_floors += group;
    room_number -= rooms_in_group;
    group++;
  }

  std::uint64_t floor_in_group = (room_number - 1) / group;
  std::uint64_t room_on_floor = ((room_number - 1) % group) + 1;

  std::uint64_t floor_number = total_floors + floor_in_group + 1;

  std::cout << floor_number << " " << room_on_floor << "\n";
}
