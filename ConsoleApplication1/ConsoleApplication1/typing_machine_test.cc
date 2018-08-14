// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"
#include <sstream>

using namespace std;

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

public:
  static void RunTest() {
    BarSeparatorTest();
    // add more..
  }
};

class TmTypeTestSuite
{
private:
  static void TypeKeyTest() {
    TypingMachine tm;
    int returnValue = tm.TypeKey('a');
    ASSERT_EQ(tm.Print('|'), std::string("a|"));
    ASSERT_EQ(returnValue, true);
  }
  static void TypeKeyEdgeTest() {
    TypingMachine tm;
    char leftEdge = (char)32;
    char rightEdge = (char)126;
    int leftReturn = tm.TypeKey(leftEdge);
    int rightReturn = tm.TypeKey(rightEdge);

    ASSERT_EQ(leftReturn, true);
    ASSERT_EQ(rightReturn, true);
 
    stringstream ss;
    ss << leftEdge << rightEdge << "|";
    ASSERT_EQ(tm.Print('|'), ss.str());
  }
  static void TypeKeyOutofEdgeTest() {
    TypingMachine tm;
    char leftEdge = (char)32-1;
    char rightEdge = (char)126+1;
    int returnLeft = tm.TypeKey(leftEdge);
    int returnRight = tm.TypeKey(rightEdge);
    ASSERT_EQ(tm.Print('|'), "|");
    ASSERT_EQ(returnLeft, false);
    ASSERT_EQ(returnRight, false);
  }
public:
  static void RunTest() {
    // add more..
    TypeKeyTest();
    TypeKeyEdgeTest();
    TypeKeyOutofEdgeTest();
  }
};

class TmHomeKeyTestSuite
{
private:
  static void HomeKeyBasicTest() {
    TypingMachine tm;
    //  when data no exists
    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), "|");

    // when data exists
    char leftEdge = 'a';
    int returnLeft = tm.TypeKey(leftEdge);
    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), "|a");

    // when more data exists, add one after home
    char rightEdge = 'b';
    returnLeft = tm.TypeKey(rightEdge);
    ASSERT_EQ(tm.Print('|'), "b|a");

    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), "|ba");
  }
public:
  static void RunTest() {
    HomeKeyBasicTest();
  }
};

class TmEndKeyTestSuite
{
private:
  static void EndKeyBasicTest() {
    TypingMachine tm;
    //  when data no exists
    tm.EndKey();
    ASSERT_EQ(tm.Print('|'), "|");

    // when data exists
    char leftEdge = 'a';
    int returnLeft = tm.TypeKey(leftEdge);
    tm.EndKey();
    ASSERT_EQ(tm.Print('|'), "a|");

    // when more data exists, add one after home
    char rightEdge = 'b';
    returnLeft = tm.TypeKey(rightEdge);
    ASSERT_EQ(tm.Print('|'), "ab|");

    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), "|ab");
    tm.EndKey();
    ASSERT_EQ(tm.Print('|'), "ab|");
  }
public:
  static void RunTest() {
    EndKeyBasicTest();
  }
};

class TmLeftKeyTestSuite
{
private:
  static void LeftKeyBasicTest() {
    TypingMachine tm;
    //  when data no exists
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), "|");

    // when data exists
    char leftEdge = 'a';
    int returnLeft = tm.TypeKey(leftEdge);
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), "|a");

    // when more data exists, add one after home
    char rightEdge = 'b';
    returnLeft = tm.TypeKey(rightEdge);
    ASSERT_EQ(tm.Print('|'), "b|a");

    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), "|ba");

    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), "|ba");
    //tm.EndKey();
    //ASSERT_EQ(tm.Print('|'), "ab|");
  }
public:
  static void RunTest() {
    // add more..
    LeftKeyBasicTest();
  }
};
class TmRightKeyTestSuite
{
private:
  static void RightKeyBasicTest() {
    TypingMachine tm;
    //  when data no exists
    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), "|");

    // when data exists
    char leftEdge = 'a';
    int returnLeft = tm.TypeKey(leftEdge);
    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), "a|");

    // when more data exists, add one after home
    char rightEdge = 'b';
    returnLeft = tm.TypeKey(rightEdge);
    ASSERT_EQ(tm.Print('|'), "ab|");

    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), "a|b");

    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), "ab|");

    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), "ab|");
  }
public:
  static void RunTest() {
    // add more..
    RightKeyBasicTest();
  }
};
class TmEraseTestSuite
{
private:
  static void EraseBasicTest() {
    TypingMachine tm;
    //  when data no exists
    int returnValue = tm.EraseKey();
    ASSERT_EQ(returnValue, false);
    ASSERT_EQ(tm.Print('|'), "|");

    // when data exists
    char leftEdge = 'a';
    int returnLeft = tm.TypeKey(leftEdge);

    ASSERT_EQ(tm.Print('|'), "a|");
    returnValue = tm.EraseKey();
    ASSERT_EQ(returnValue, true);
    ASSERT_EQ(tm.Print('|'), "|");

    // when more data exists, add one after home
    returnLeft = tm.TypeKey(leftEdge);

    char rightEdge = 'b';
    returnLeft = tm.TypeKey(rightEdge);
    ASSERT_EQ(tm.Print('|'), "ab|");

    returnValue = tm.EraseKey();
    ASSERT_EQ(returnValue, true);

    returnValue = tm.EraseKey();
    ASSERT_EQ(returnValue, true);

    ASSERT_EQ(tm.Print('|'), "|");

    //tm.LeftKey();
    //ASSERT_EQ(tm.Print('|'), "a|b");

    //tm.RightKey();
    //ASSERT_EQ(tm.Print('|'), "ab|");

    //tm.RightKey();
    //ASSERT_EQ(tm.Print('|'), "ab|");
  }
public:
  static void RunTest() {
    // add more..
    EraseBasicTest();
  }
};

class TmPrintTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  TmTypeTestSuite::RunTest();
  TmHomeKeyTestSuite::RunTest();
  TmEndKeyTestSuite::RunTest();
  TmLeftKeyTestSuite::RunTest();
  TmRightKeyTestSuite::RunTest();
  TmEraseTestSuite::RunTest();
  TmPrintTestSuite::RunTest();
  // add more..
}