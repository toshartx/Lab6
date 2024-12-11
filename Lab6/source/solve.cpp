#include "../headers/solve.h"

void ContextMenu_1()
{
  std::cout << "--------------------------------------------------------------------------------------\n"
            << "Дана строка, состоящая из слов, разделенных пробелами.\n"
            << "Программа выводит на экран порядковый номер слова максимальной длины и номер позиции\n"
            << "строки, с которой оно начинается.                                         Вариант 13\n"
            << "--------------------------------------------------------------------------------------\n";
}

void ContextMenu_2()
{
  std::cout << "---------------------------------------------------------------------------------------------\n"
            << "В тексте нет слов, начинающихся одинаковыми буквами. Программа печатает слова текста в таком\n"
            << "порядке, чтобы последняя буква каждого слова совпадала с первой буквой последующего слова.\n"
            << "Если все слова нельзя напечатать в таком порядке,\n"
            << "то находится такая цепочка, состоящая из наибольшего количества слов..\n"
            << "                                                                            Вариант 13\n"
            << "---------------------------------------------------------------------------------------------\n";
}

void ContextMenu_3()
{
  std::cout << "--------------------------------------------------------------------------------------\n"
            << "Программа выводит все символы, содержащиеся в строке.                       Вариант 13\n"
            << "--------------------------------------------------------------------------------------\n";
}

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

int StringLength(const char *str)
{
  int length = 0;
  for (int c = 0; str[length] != '\0'; length += c)
  {
    c = UTFbytes(str[length]);
  }
  return length;
}

void MaxLength(int &maxLength, int &wordMaxIndex, int &elementMaxIndex, const char *str)
{
  for (int i = 0, length = 0, word = 1, symbolIndex = 0, sumOfWordIndex = 0, c = 0; str[i] != '\0'; i += c)
  {
    c = UTFbytes(str[i]);
    ++sumOfWordIndex;
    ++symbolIndex;
    if (str[i] != ' ' && (str[i + c] == ' ' || str[i + c] == '\0'))
    {
      ++length;
      if (length > maxLength)
      {
        maxLength = length;
        wordMaxIndex = word;
        elementMaxIndex = symbolIndex - sumOfWordIndex;
      }
    }
    else if (str[i] == ' ' && str[i + c] == ' ')
      continue;
    else if (str[i] == ' ' && str[i + c] != ' ')
    {
      sumOfWordIndex = 0;
      length = 0;
      ++word;
    }
    else
    {
      ++length;
    }
  }
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

void Solve_1(const char *str)
{
  ContextMenu_1();
  int maxLength = 0;
  int wordMaxIndex = 1;
  int elementMaxIndex = 0;

  MaxLength(maxLength, wordMaxIndex, elementMaxIndex, str);

  std::cout << "Максимальная длина слова: " << maxLength << '\n';
  std::cout << "Номер слова в тексте: " << wordMaxIndex << '\n';
  std::cout << "Индекс первого элемента этого слова: " << elementMaxIndex << '\n';
  DeleteString(str);
}

bool Solve_1(const char *str, int* test)
{
  bool testFlag = 1;
  int maxLength = 0;
  int wordMaxIndex = 1;
  int elementMaxIndex = 0;

  MaxLength(maxLength, wordMaxIndex, elementMaxIndex, str);
  int resultArray[3] = {maxLength, wordMaxIndex, elementMaxIndex};
  for (int i = 0; i < 3; ++i)
  {
    if (resultArray[i] != test[i])
    {
      testFlag = 0;
      break;
    }
  }  

  DeleteString(str);
  return testFlag;
}

void Solve_2(const char *str)
{
  ContextMenu_2();
  int size = numberOfWords(str);
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
  int indexes[size]; // хранит индексы максимальной комбинации
  for (int i = 0; i < size; ++i)
  {
    indexes[i] = -1;
  }

  bool **matches = new bool *[size];
  for (int i = 0; i < size; ++i)
    matches[i] = new bool[size];

  AutoFill(startIndex, endIndex, str, matches, size);

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

  std::cout << "Новая строка: ";
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

bool Solve_2(const char *str, int* test)
{
  bool testFlag = 1;
  int size = numberOfWords(str);
  int endIndex[size];
  int startIndex[size];
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
  int indexes[size]; 
  for (int i = 0; i < size; ++i)
  {
    indexes[i] = -1;
  }

  bool **matches = new bool *[size];
  for (int i = 0; i < size; ++i)
    matches[i] = new bool[size];

  AutoFill(startIndex, endIndex, str, matches, size);

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

  for (int i = 0; i < size; ++i)
  {
    if (resultIndexes[i] != test[i])
    {
      testFlag = 0;
      break;
    }
  }

  for (int k = 0; k < size; ++k)
  {
    delete[] matches[k];
    matches[k] = nullptr;
  }
  delete[] matches;
  matches = nullptr;
  DeleteString(str);
  return testFlag;
}

void Solve_3(const char *str)
{
  ContextMenu_3();
  std::sort((char *)str, (char *)str + StringLength(str));
  std::cout << "Все символы в строке: ";
  for (int i = 0, c = 0; str[i] != '\0'; i += c)
  {
    c = UTFbytes(str[i]);
    if (i == 0 || str[i - c] != str[i])
    {
      std::cout << str[i] << " ";
    }
  }
  std::cout << std::endl;
  DeleteString(str);
}

bool Solve_3(const char *str, int sum)
{
  bool testFlag = 1;
  int ourSum = 0;
  std::sort((char *)str, (char *)str + StringLength(str));
  std::cout << "Все символы в строке: ";
  for (int i = 0, c = 0; str[i] != '\0'; i += c)
  {
    c = UTFbytes(str[i]);
    if (i == 0 || str[i - c] != str[i])
    {
      ourSum += str[i];
    }
  }

  if (ourSum != sum)
  {
    testFlag = 0;
  }
  DeleteString(str);
  return testFlag;
}

void Laba(int task)
{
  const char* str = StringInput();
  if (task == 1)
  {
    Solve_1(str);
  }
  else if (task == 2)
  {
    Solve_2(str);
  }
  else if (task == 3)
  {
    Solve_3(str);
  }
}
