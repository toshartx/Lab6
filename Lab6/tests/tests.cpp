#include <gtest/gtest.h>
#include <solve.h>

TEST(Task1, Test1)
{
  const char* str = "Abubakr very well";
  int test[3] = {7, 1, 0};
  EXPECT_TRUE(Solve_1(str,test));
}

TEST(Task1, Test2)
{
  const char* str = "Я был пришельцем и меня не уважали";
  int test[3] = {10, 3, 6};
  EXPECT_TRUE(Solve_1(str,test));
}

TEST(Task1, Test3)
{
  const char* str = "Init Google Test";
  int test[3] = {6, 2, 5};
  EXPECT_TRUE(Solve_1(str,test));
}


TEST(Task1, Test4)
{
  const char* str = "Mbappe strong player? Seriously?";
  int test[3] = {10, 4, 22};
  EXPECT_TRUE(Solve_1(str,test));
}

TEST(Task1, Test5)
{
  const char* str = "My name is your name =)";
  int test[3] = {4, 2, 3};
  EXPECT_TRUE(Solve_1(str,test));
}

TEST(Task1, Test6)
{
  const char* str = "jergojspgjpoaojpogprejgpowjgp5po3jgp2pmpgappirejgpojpogjwrpogjpogjpowjgpwjgpofd";
  int test[3] = {79, 1, 0};
  EXPECT_TRUE(Solve_1(str,test));
}

TEST(Task1, Test7)
{
  const char* str = "Примичева Зоя - прекрасный преподаватель";
  int test[3] = {13, 5, 27};
  EXPECT_TRUE(Solve_1(str,test));
}

TEST(Task1, Test8)
{
  const char* str = "Lorem Ipsum";
  int test[3] = {5, 1, 0};
  EXPECT_TRUE(Solve_1(str,test));
}

TEST(Task1, Test9_H)
{
  const char* str = "";
  int test[3] = {0, 1, 0};
  EXPECT_TRUE(Solve_1(str,test));
}

TEST(Task1, Test10_H)
{
  const char* str = "                                          alo      52";
  int test[3] = {3, 1, 42};
  EXPECT_TRUE(Solve_1(str,test));
}

TEST(Task2, Test1)
{
  const char* str = "ab bc cd";
  int test[3] = {0, 1, 2};
  EXPECT_TRUE(Solve_2(str,test));
}

TEST(Task2, Test2)
{
  const char* str = "y bil priselcem i meny ne uvazali";
  int test[7] = {2, 4, 0, -1, -1, -1, -1};
  EXPECT_TRUE(Solve_2(str,test));
}

TEST(Task2, Test3)
{
  const char* str = "Init GooglI test";
  int test[3] = {1, 0, 2};
  EXPECT_TRUE(Solve_2(str,test));
}


TEST(Task2, Test4)
{
  const char* str = "cde abc lke eba";
  int test[4] = {2,3,1,0};
  EXPECT_TRUE(Solve_2(str,test));
}

TEST(Task2, Test5)
{
  const char* str = "My name is your name =)";
  int test[6] = {0, 3, -1, -1, -1, -1};
  EXPECT_TRUE(Solve_2(str,test));
}

TEST(Task2, Test6)
{
  const char* str = "jergojspgjpoaojpogprejgpowjgp5po3jgp2pmpgappirejgpojpogjwrpogjpogjpowjgpwjgpofd";
  int test[1] = {-1};
  EXPECT_TRUE(Solve_2(str,test));
}

TEST(Task2, Test7)
{
  const char* str = "Upomecano nikolas siUUUU ibuklin grushi";
  int test[5] = {4,3,1,2,0};
  EXPECT_TRUE(Solve_2(str,test));
}

TEST(Task2, Test8)
{
  const char* str = "Lorei Ipsum mamba";
  int test[3] = {1, 2, -1};
  EXPECT_TRUE(Solve_2(str,test));
}

TEST(Task2, Test9_H)
{
  const char* str = "";
  int test[3] = {0, 1, 0};
  EXPECT_TRUE(Solve_2(str,test));
}

TEST(Task2, Test10_H)
{
  const char* str = "mt fg kf gl hk ql lr ab cd bc";
  int test[10] = {4, 2, 1, 3, 6, -1, -1, -1, -1, -1};
  EXPECT_TRUE(Solve_2(str,test));
}

TEST(Task3, Test1)
{
  const char* str = "abc";
  int sum = 294;
  EXPECT_TRUE(Solve_3(str,sum));
}

TEST(Task3, Test2)
{
  const char* str = "aaaaaabbbccccc";
  int sum = 294;
  EXPECT_TRUE(Solve_3(str,sum));
}

TEST(Task3, Test3)
{
  const char* str = "Init Google Test";
  int sum = 1129;
  EXPECT_TRUE(Solve_3(str,sum));
}


TEST(Task3, Test4)
{
  const char* str = "Mbappe strong player? Seriously?";
  int sum = 1783;
  EXPECT_TRUE(Solve_3(str,sum));
}

TEST(Task3, Test5)
{
  const char* str = "My name is your name =)";
  int sum = 1311;
  EXPECT_TRUE(Solve_3(str,sum));
}

TEST(Task3, Test6)
{
  const char* str = "jergojspgjpoaojpogprejgpowjgp5po3jgp2pmpgappirejgpojpogjwrpogjpogjpowjgpwjgpofd";
  int sum = 1548;
  EXPECT_TRUE(Solve_3(str,sum));
}

TEST(Task3, Test7)
{
  const char* str = "";
  int sum = 0;
  EXPECT_TRUE(Solve_3(str,sum));
}

TEST(Task3, Test8)
{
  const char* str = "Lorem Ipsum";
  int sum = 960;
  EXPECT_TRUE(Solve_3(str,sum));
}

TEST(Task3, Test9_H)
{
  const char* str = "1234567890qwertyuiop[]asdfghjkl;'zxcvbnm,./";
  int sum = 3791;
  EXPECT_TRUE(Solve_3(str,sum));
}

TEST(Task3, Test10_H)
{
  const char* str = "        ";
  int sum = 32;
  EXPECT_TRUE(Solve_3(str,sum));
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}