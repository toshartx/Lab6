#include "../headers/UsefulLib.h"

int NumberInput()
{
  int a;
  while (!(std::cin >> a) || std::cin.peek() != '\n')
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Некорректный ввод, повторите попытку:\n";
  }
  return a;
}

int Choose(int first, int last)
{
  int a;
  std::cout << "Введите номер задания: ";
  while (!(std::cin >> a) || std::cin.peek() != '\n' || (a < first || a > last))
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Не существует такого задания:\n";
  }
  std::cin.ignore(1000,'\n');
  return a;
}

bool Restart()
{
  std::cout << "Напишите " << "0 - чтобы завершить программу\n" 
                              "\t 1 - чтобы запустить программу\n";
  bool flag;
  while (!(std::cin >> flag) || std::cin.peek() != '\n')
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Команда не распознана. Повторите попытку:\n";
  }
  return flag;
}

const char* StringInput()
{
  char stringSize = 80;
  char* str = new char[stringSize];
  char c;
  char i = 0;
  std::cout << "Введите строку:\n";
  while ((c = getchar()) != '\n' && i < stringSize)
  {
    str[i] = c;
    ++i;
  }
  str = (char*)realloc(str, i+1);
  str[i] = '\0';
  return (const char*)str;
}

char *StringWithoutSpaces(const char *str)
{
  char *resultStr = "";
  int j = 0;
  for (int i = 0; str[i] != '\0'; ++i)
  {
    if (str[i] != ' ')
    {
      resultStr[j++] = str[i];
    }
  }
  resultStr[j] = '\0';
  return resultStr;
}


void DeleteString(const char* str)
{
  delete[] str;
  str = nullptr;
}