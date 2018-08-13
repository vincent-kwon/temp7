// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }

  static void MultipleNodeTest() {
    Node *node = new Node('A');
    Node *insertedNode = node->InsertPreviousNode('B');
    
    ASSERT_EQ(insertedNode, node->GetPreviousNode());
  }
public:
  static void RunTest() {
    SingleNodeTest();
    // add more..
    MultipleNodeTest();
  }
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  // add more..
}