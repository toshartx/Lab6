#include "../headers/UsefulLib.h"

int UTFbytes(char c)
{
  if ((c & 0x80) == 0x00)
    return 1;
  if ((c & 0xE0) == 0xC0)
    return 2;
  if ((c & 0xF0) == 0xE0)
    return 3;
  if ((c & 0xF8) == 0xF0)
    return 4;
  return -1;
}

int numberOfWords(const char *str)
{
  int counter = 0;
  for (int i = 0, c = 0; str[i] != '\0'; i += c)
  {
    c = UTFbytes(str[i]);
    if (str[i] != ' ' && (str[i + c] == ' ' || str[i + c] == '\0'))
    {
      ++counter;
    }
  }
  return counter;
}

void AutoFill(int *startIndex, int *endIndex, const char *str, bool **matches, int size)
{
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0, counter = 0; j < size; ++j)
    {
      if (i != j && str[endIndex[i]] == str[startIndex[j]])
        matches[i][j] = 1;
      else
        matches[i][j] = 0;
    }
  }
}

void Rec(int *result, int *indexes, bool **copy, int size, int i, int j)
{
  static int calls = 0;
  static int maxCombination = 0;
  for (int k = 0; k < size; ++k)
  {
    copy[k][i] = 0;
  }
  indexes[calls] = i;
  ++calls;
  for (int i = 0; i < size; ++i)
  {
    if (copy[j][i] == 1)
    {
      Rec(result, indexes, copy, size, j, i);
    }
  }
  for (int i = 0; i < size; ++i)
  {
    if (indexes[i] == -1)
    {
      indexes[i] = j;
      break;
    }
  }
  ++calls;
  if (calls > maxCombination)
  {
    maxCombination = calls;
    for (int i = 0; i <= calls; ++i)
    {
      result[i] = indexes[i];
    }
  }
  calls = 0;
}

void MagicOutput(const char *str, int *start, int *end, int *maxCombination, int size)
{
  for (int i = 0; i < size; ++i)
  {
    int index = maxCombination[i];
    for (int j = start[index]; j <= end[index]; ++j)
    {
      std::cout << str[j];
    }
    std::cout << " ";
  }
  std::cout << std::endl;
}

void Solve_2()
{
  const char *str = StringInput();
  int size = numberOfWords(str);
  std::cout << "Количество слов: " << size << '\n';
  int endIndex[size];
  int startIndex[size];
  // Заполняем endIndex и startIndex
  for (int i = 0, c = 0, j = 0; str[i] != '\0'; i += c)
  {
    c = UTFbytes(str[i]);
    if ((i == 0 && str[i] != ' ') ||
        (str[i] != ' ' && str[i - 1] == ' '))
    {
      startIndex[j] = i;
    }
    if (str[i] != ' ' && (str[i + c] == ' ' || str[i + c] == '\0'))
    {
      endIndex[j] = i;
      ++j;
    }
  }
  std::cout << "Индексы начала | конца слов :\n";
  for (int i = 0; i < size; ++i)
  {
    std::cout << startIndex[i] << " " << endIndex[i] << '\n';
  }
  int indexes[size]; // хранит индексы максимальной комбинации
  std::cout << "Изначальные индексы макс комбинации:\n";
  for (int i = 0; i < size; ++i)
  {
    indexes[i] = -1;
    std::cout << indexes[i] << " ";
  }
  std::cout << '\n';

  bool **matches = new bool *[size];
  for (int i = 0; i < size; ++i)
    matches[i] = new bool[size];

  std::cout << "Матрица соответствий:\n";
  AutoFill(startIndex, endIndex, str, matches, size);
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0, counter = 0; j < size; ++j)
    {
      std::cout << matches[i][j] << " ";
    }
    std::cout << '\n';
  }

  int resultIndexes[size];
  for (int i = 0; i < size; ++i)
  {
    resultIndexes[i] = -1;
  }

  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      if (matches[i][j] == 1)
      {
        Rec(resultIndexes, indexes, matches, size, i, j);
        AutoFill(startIndex, endIndex, str, matches, size);
      }
    }
  }
  std::cout << "Конечные индексы макс комбинации:\n";
  for (int i = 0; i < size; ++i)
  {
    std::cout << resultIndexes[i] << " ";
  }
  std::cout << '\n';

  std::cout << "Новая строка:";
  MagicOutput(str, startIndex, endIndex, resultIndexes, size);
  if (resultIndexes[0] == -1)
  {
    for (int i = startIndex[0], c = 0; i <= endIndex[0]; i += c)
    {
      c = UTFbytes(str[i]);
      std::cout << str[i];
    }
    std::cout << '\n';
  }

  for (int k = 0; k < size; ++k)
  {
    delete[] matches[k];
    matches[k] = nullptr;
  }
  delete[] matches;
  matches = nullptr;
  DeleteString(str);
}

int main()
{
  Solve_2();
  return 0;
}
