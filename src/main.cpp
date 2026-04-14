#include <cstdint>
#include <iostream>
#include <limits>

#include "inverted-tower-rooms.h"

int main() {
  std::uint64_t room_number;

  if (!(std::cin >> room_number)) {
    std::cerr << "Error: Invalid input. Please enter a valid number."
              << std::endl;
    return 1;
  }

  if (room_number == 0) {
    std::cerr << "Error: Room number must be at least 1 (1 ≤ N < 2^64)"
              << std::endl;
    return 1;
  }

  if (room_number == std::numeric_limits<std::uint64_t>::max()) {
    std::cerr << "Info: Processing maximum possible room number: "
              << room_number << std::endl;
  }

  printNeededFloorAndRoom(room_number);

  return 0;
}