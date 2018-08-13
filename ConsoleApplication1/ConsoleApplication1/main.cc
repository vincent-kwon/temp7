// Copyright 2018 Hanpil Kang

#include <cstdio>
#include <cstring>
#include <iostream>

#include "node.h"
#include "typing_machine.h"
#include "getch.h"
#include <vector>

using namespace std;

const char full_board[5][34] = {
  "+-------+   +-------+   +-------+",
  "|       |   |       |   |       |",
  "|  ' '  |<--+  ' '  +-->|  ' '  |",
  "|       |   |       |   |       |",
  "+-------+   +-------+   +-------+"
};

const char empty_board[5][34] = {
  "            +-------+            ",
  "            |       |            ",
  "            |  ' '  |            ",
  "            |       |            ",
  "            +-------+            "
};


void printNode(Node* node) {
  if (!node) {
    return;
  }
  char print_board[5][34];
  memcpy(print_board, full_board, sizeof print_board);
  Node* prev = node->GetPreviousNode();
  Node* next = node->GetNextNode();

  if (!prev) {
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 13; ++j)
        print_board[i][j] = empty_board[i][j];
  } else {
    print_board[2][4] = prev->GetData();
  }
  if (!next) {
    for (int i = 0; i < 5; ++i)
      for (int j = 20; j < 33; ++j)
        print_board[i][j] = empty_board[i][j];
  } else {
    print_board[2][28] = next->GetData();
  }
  print_board[2][16] = node->GetData();

  for (int i = 0; i < 5; ++i)
    puts(print_board[i]);
  return;
}

void TestNode() {
  Node* node = new Node(' ');
  while (true) {
    printNode(node);
    puts("Usage: ");
    puts("Browse with left and right Arrow.");
    puts("Insert with [ and ] key.");
    puts("Erase with , and . key.");
    puts("");
    int user_key = GetKeyInput();
    switch (user_key) {
      case KEY_LEFT: {
        if (node->GetPreviousNode()) {
          node = node->GetPreviousNode();
        }
        break;
      }
      case KEY_RIGHT: {
        if (node->GetNextNode()) {
          node = node->GetNextNode();
        }
        break;
      }
      case '[': {
        user_key = GetKeyInput();
        if (32 <= user_key && user_key <= 126) {
          node->InsertPreviousNode(user_key);
        }
        break;
      }
      case ']': {
        user_key = GetKeyInput();
        if (32 <= user_key && user_key <= 126) {
          node->InsertNextNode(user_key);
        }
        break;
      }
      case ',': {
        node->ErasePreviousNode();
        break;
      }
      case '.': {
        node->EraseNextNode();
        break;
      }
      default: {
        // ignore
        break;
      }
    }
  }
}

void TestTypingMachine() {
  TypingMachine tape;
  while (true) {
    puts(tape.Print('|').c_str());
    int user_key = GetKeyInput();
    switch (user_key) {
      case KEY_LEFT: {
        tape.LeftKey();
        break;
      }
      case KEY_RIGHT: {
        tape.RightKey();
        break;
      }
      case KEY_HOME: {
        tape.HomeKey();
        break;
      }
      case KEY_END: {
        tape.EndKey();
        break;
      }
      case KEY_DEL2: {
        tape.EraseKey();
        break;
      }
      default: {
        tape.TypeKey(user_key);
        break;
      }
    }
  }
}
extern std::vector<int> CountingSort(std::vector<int> V);
extern std::vector<int> InsertionSort(std::vector<int> V);
extern std::vector<int> QuickSort(std::vector<int> V);

void TestCountSort() {
  cout << "Count sort test..." << endl;
  vector<int> myVector = {9, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  vector<int> myVector2 = {100, 99, 100, 99, 98, 100};
  vector<int> returnedVector = CountingSort(myVector);
  for (auto i : returnedVector) {
    cout << i << " ";
  }
  cout << "" << endl;
  cout << "Count sort test..." << endl;
}

void TestInsertionSort() {
  cout << "Insertion sort test..." << endl;
  vector<int> myVector = { 9, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  //vector<int> myVector = { 97, 98, 99, 100 };
  vector<int> returnedVector = InsertionSort(myVector);
  for (auto i : returnedVector) {
    cout << i << " ";
  }
  cout << "" << endl;
  cout << "Insertion sort test..." << endl;
}

void TestQuickSort() {
  cout << "Quick sort test..." << endl;
  //vector<int> myVector = { 9, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  vector<int> myVector = { 100, 100, 100 };
  vector<int> myVector2 = { 100, 99, 100, 99, 98, 100 };
  vector<int> returnedVector = QuickSort(myVector);
  for (auto i : returnedVector) {
    cout << i << " ";
  }
  cout << "" << endl;
  cout << "Quick sort test..." << endl;
}


int main() {
  //TestCountSort();
  //TestInsertionSort();
  TestQuickSort();
  /*
  puts("1: Test Node.");
  puts("2: Test Typing Machine.");
  while (true) {
    int user_key = GetKeyInput();
    if (user_key == '1') {
      TestNode();
      return 0;
    }
    if (user_key == '2') {
      TestTypingMachine();
      return 0;
    }
  }
  */
}









