#include <gtest/gtest.h>

#include <cstdint>
#include <istream>
#include <sstream>
#include <string>

#include "inverted-tower-rooms.h"

class TowerRoomsTest : public ::testing::Test {
 protected:
  void SetUp() override {}
  void TearDown() override {}

  // Функция для захвата вывода printNeededFloorAndRoom
  std::string captureOutput(std::uint64_t room_number) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    printNeededFloorAndRoom(room_number);

    std::cout.rdbuf(old);
    return buffer.str();
  }

  // Функция для проверки теста
  void testRoom(std::uint64_t input, const std::string& expected_output) {
    std::string output = captureOutput(input);
    // Удаляем символ новой строки
    if (!output.empty() && output.back() == '\n') {
      output.pop_back();
    }
    EXPECT_EQ(output, expected_output) << "Failed for room number: " << input;
  }
};

// Test 1: Room 1 -> Floor 1, Room 1
TEST_F(TowerRoomsTest, Test1_Room1) { testRoom(1, "1 1"); }

// Test 2: Room 2 -> Floor 2, Room 1
TEST_F(TowerRoomsTest, Test2_Room2) { testRoom(2, "2 1"); }

// Test 3: Room 3 -> Floor 2, Room 2
TEST_F(TowerRoomsTest, Test3_Room3) { testRoom(3, "2 2"); }

// Test 4: Room 4 -> Floor 3, Room 1
TEST_F(TowerRoomsTest, Test4_Room4) { testRoom(4, "3 1"); }

// Test 5: Room 5 -> Floor 3, Room 2
TEST_F(TowerRoomsTest, Test5_Room5) { testRoom(5, "3 2"); }

// Test 6: Room 6 -> Floor 4, Room 1
TEST_F(TowerRoomsTest, Test6_Room6) { testRoom(6, "4 1"); }

// Test 7: Room 9 -> Floor 5, Room 1
TEST_F(TowerRoomsTest, Test7_Room9) { testRoom(9, "5 1"); }

// Test 8: Room 10 -> Floor 5, Room 2
TEST_F(TowerRoomsTest, Test8_Room10) { testRoom(10, "5 2"); }

// Test 9: Room 11 -> Floor 5, Room 3
TEST_F(TowerRoomsTest, Test9_Room11) { testRoom(11, "5 3"); }

// Test 10: Room 12 -> Floor 6, Room 1
TEST_F(TowerRoomsTest, Test10_Room12) { testRoom(12, "6 1"); }

// Test 11: Room 13 -> Floor 6, Room 2
TEST_F(TowerRoomsTest, Test11_Room13) { testRoom(13, "6 2"); }

// Test 12: Room 14 -> Floor 6, Room 3
TEST_F(TowerRoomsTest, Test12_Room14) { testRoom(14, "6 3"); }

// Test 13: Room 15 -> Floor 7, Room 1
TEST_F(TowerRoomsTest, Test13_Room15) { testRoom(15, "7 1"); }

// Test 14: Room 18 -> Floor 7, Room 4
TEST_F(TowerRoomsTest, Test14_Room18) { testRoom(18, "7 4"); }

// Test 15: Room 23 -> Floor 9, Room 1
TEST_F(TowerRoomsTest, Test15_Room23) { testRoom(23, "9 1"); }

// Test 16: Room 30 -> Floor 10, Room 4
TEST_F(TowerRoomsTest, Test16_Room30) { testRoom(30, "10 4"); }

// Test 17: Room 92 -> Floor 22, Room 1
TEST_F(TowerRoomsTest, Test17_Room92) { testRoom(92, "22 1"); }

// Test 18: Room 2,000,000,000 -> Floor 1,650,964, Room 845
TEST_F(TowerRoomsTest, Test18_Room2Billion) {
  testRoom(2000000000ULL, "1650964 845");
}

// Test 19: Room 4,294,967,295 (2^32 - 1) -> Floor 2,748,047, Room 1,011
TEST_F(TowerRoomsTest, Test19_Room4294967295) {
  testRoom(4294967295ULL, "2748047 1011");
}

// Test 20: Room 4,294,967,296 (2^32) -> Floor 2,748,047, Room 1,012
TEST_F(TowerRoomsTest, Test20_Room4294967296) {
  testRoom(4294967296ULL, "2748047 1012");
}

// Test 21: Room 9,223,372,036,854,775,808 (2^63) -> Floor 4,574,152,700,389,
// Room 1,735,828
TEST_F(TowerRoomsTest, Test21_Room9223372036854775808) {
  testRoom(9223372036854775808ULL, "4574152700389 1735828");
}

// Test 22: Room 18,446,744,073,709,551,615 (2^64 - 1) -> Floor
// 7,261,014,808,460, Room 3,650,542
TEST_F(TowerRoomsTest, Test22_Room18446744073709551615) {
  testRoom(18446744073709551615ULL, "7261014808460 3650542");
}

// ИСПРАВЛЕННЫЙ ТЕСТ - GroupTransitionTest
TEST_F(TowerRoomsTest, GroupTransitionTest) {
  testRoom(4, "3 1");   // Начало группы из 3 комнат
  testRoom(6, "4 1");   // Начало следующей группы
  testRoom(9, "5 1");   // Исправлено: было "5 2"
  testRoom(11, "5 3");  // Исправлено: было "5 4"
}

// Основная функция для запуска тестов
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}