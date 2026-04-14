#include <cstdint>
#include <iostream>

#include "inverted-tower-rooms.h"

int main() {
  std::uint64_t room_number;
  std::cin >> room_number;

  printNeededFloorAndRoom(room_number);

  return 0;
}