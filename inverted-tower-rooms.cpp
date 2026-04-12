#include <iostream>

int main() {
  unsigned long long room_number;
  std::cin >> room_number;

  unsigned long long total_floors =
      0; // Суммарное количество этажей в пройденных группах
  unsigned long long group =
      1; // Текущая группа (сколько этажей и комнат на этаже)
  unsigned long long
      rooms_in_group; // Количество комнат в текущей группе (group * group)

  // Этап 1: Находим группу, в которой находится комната
  // Удаляем целые группы из номера комнаты, пока не останется смещение внутри
  // группы
  while (true) {
    rooms_in_group =
        group * group; // Комнат в группе = этажей × комнат на этаже

    // Если номер комнаты не превышает размер текущей группы,
    // значит комната находится в этой группе
    if (room_number <= rooms_in_group) {
      break; // Выходим из цикла
    }

    // Иначе: комната в следующей группе
    total_floors += group; // Добавляем этажи текущей группы к общему счетчику
    room_number -= rooms_in_group; // Вычитаем комнаты текущей группы из номера
    group++;                       // Переходим к следующей группе
  }

  // Этап 2: Определяем позицию комнаты внутри группы
  // Вычитаем 1, чтобы перейти к 0-based индексации для удобства деления
  unsigned long long floor_in_group =
      (room_number - 1) / group; // Этаж внутри группы
  unsigned long long room_on_floor =
      (room_number - 1) % group + 1; // Номер комнаты на этаже

  // Этап 3: Вычисляем глобальный номер этажа
  // total_floors - этажи до текущей группы
  // floor_in_group - этажи внутри текущей группы 
  unsigned long long floor_number = total_floors + floor_in_group + 1;

  std::cout << floor_number << " " << room_on_floor << std::endl;

  return 0;
}