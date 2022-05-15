//Copyright by Margarita-creator

#include <gtest/gtest.h>
#include "Stack.hpp"
#include "StackSecond.hpp"

TEST(Example, EmptyTest) {
  EXPECT_TRUE(true);
}
TEST(First, True) {
  Stack<int> MySteck;
  int t=2;
  MySteck.push(1);
  MySteck.push(t);
  EXPECT_EQ(MySteck.head(), 2);
  EXPECT_EQ(MySteck.pop(), 2);
  EXPECT_EQ(MySteck.head(), 1);
  EXPECT_EQ(MySteck.pop(), 1);
  std::string err = "Stack is empty";
  try {
    MySteck.pop();
  }
  catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
}

class Myclass {
 public:
  Myclass(Myclass&) = delete;
  Myclass& operator = (Myclass&) = delete;
  Myclass(Myclass&& obj)  noexcept {
    t2 = std::move(obj.t2);
    t1 = obj.t1;
    t0 = obj.t0;
  }
  Myclass& operator=(Myclass&& obj)  noexcept {
    t2 = std::move(obj.t2);
    t1 = obj.t1;
    t0 = obj.t0;
    return *this;
  }
  Myclass(){
    t0 = 0;
    t1 = 0.1;
    t2 = "0";
  }
  Myclass(int a, double b, std::string c): t0(a), t1(b), t2(c){}
  int t0;
  double t1;
  std::string t2;
};
TEST(Second, True) {
  TheSecondStack<Myclass> MySteck;
  int t0 = 2;
  double t1 = 2.2;
  std::string t2 = "2";
  MySteck.push_emplace(Myclass(1, 1.1, "12"));
  MySteck.push_emplace(t0, t1, t2);
  MySteck.push(Myclass());
  EXPECT_EQ(MySteck.pop().t2, "0");
  EXPECT_EQ(MySteck.head().t0, 2);
  EXPECT_EQ(MySteck.pop().t1, 2.2);
  EXPECT_EQ(MySteck.head().t0, 1);
  EXPECT_EQ(MySteck.pop().t2, "12");
  std::string err = "Stack is empty";
  try {
    MySteck.pop();
  }
  catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
}