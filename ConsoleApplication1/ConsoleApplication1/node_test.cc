// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }
public:
  static void RunTest() {
    SingleNodeTest();
  }
};

class NodeInsertTestSuite
{
private:
  static void NodeSingleInsertPreviousTest() {
    Node *node = new Node('A');
    Node *insertedNode = node->InsertPreviousNode('B');
    ASSERT_EQ(insertedNode, node->GetPreviousNode());
    ASSERT_NE(insertedNode, nullptr);
    ASSERT_EQ(insertedNode->GetNextNode(), node);
    delete(node); // TODO: and other clean code needed
  }
  static void NodeSingleInsertPreviousTestWhenExist() {
    Node *node = new Node('A');
    Node *insertedNode = node->InsertPreviousNode('B');
    Node *insertedNode2 = node->InsertPreviousNode('C');
    ASSERT_EQ(insertedNode2, node->GetPreviousNode());
    ASSERT_EQ(insertedNode2->GetNextNode(), node);

    ASSERT_EQ(insertedNode, insertedNode2->GetPreviousNode());
    ASSERT_EQ(insertedNode->GetNextNode(), insertedNode2);
    delete(node); // TODO: and other clean code needed
  }
  static void NodeSingleInsertNextTest() {
    Node *node = new Node('C');
    Node *insertedNode = node->InsertNextNode('D');
    ASSERT_EQ(insertedNode, node->GetNextNode());
    ASSERT_EQ(insertedNode->GetPreviousNode(), node);
    delete(node); // TODO: and other clean code needed
  }
  static void NodeSingleInsertNextTestWhenExist() {
    Node *node = new Node('E');
    Node *insertedNode = node->InsertNextNode('G');
    Node *insertedNode2 = node->InsertNextNode('F');

    ASSERT_EQ(insertedNode2, node->GetNextNode());
    ASSERT_EQ(insertedNode2->GetPreviousNode(), node);

    ASSERT_EQ(insertedNode, insertedNode2->GetNextNode());
    ASSERT_EQ(insertedNode->GetPreviousNode(), insertedNode2);

    ASSERT_EQ(node->GetData(), 'E');
    ASSERT_EQ(node->GetNextNode()->GetData(), 'F');
    ASSERT_EQ(node->GetNextNode()->GetNextNode()->GetData(), 'G');

    delete(node); // TODO: and other clean code needed
  }
  static void NodeSingleInsertPreviousNextTest() {
    Node *node = new Node('E');
    Node *insertedNode = node->InsertNextNode('F');
    Node *insertedNode2 = node->InsertPreviousNode('D');
    ASSERT_NE(insertedNode, nullptr);
    ASSERT_NE(insertedNode2, nullptr);
    ASSERT_EQ(insertedNode, node->GetNextNode());
    ASSERT_EQ(insertedNode2, node->GetPreviousNode());
    delete(node); // TODO: and other clean code needed
  }
public:
  static void RunTest() {
    NodeSingleInsertPreviousTest();
    NodeSingleInsertPreviousTestWhenExist();
    NodeSingleInsertNextTest();
    NodeSingleInsertNextTestWhenExist();
    NodeSingleInsertPreviousNextTest();
    // add more..
  }
};

class NodeEraseTestSuite
{
private:
  static void NodeSingleErasePreviousTest() {
    Node *node = new Node('A');
    Node *insertedNode = node->InsertPreviousNode('B');
    bool returnValue = node->ErasePreviousNode();

    ASSERT_EQ(returnValue, true);
    ASSERT_EQ(node->GetPreviousNode(), (Node*)nullptr);
    ASSERT_EQ(node->GetData(), 'A');

    // non-exist test
    returnValue = node->ErasePreviousNode();
    ASSERT_EQ(returnValue, false);
    delete(node); // TODO: and other clean code needed
  }

  static void NodeSingleErasePreviousWithExistTest() {
    Node *node = new Node('A');
    Node *insertedNode = node->InsertPreviousNode('C');
    Node *insertedNode2 = node->InsertPreviousNode('B');

    bool return1 = node->ErasePreviousNode();

    ASSERT_EQ(return1, true);
    ASSERT_EQ(node->GetPreviousNode(), insertedNode);
    ASSERT_EQ(node->GetPreviousNode()->GetData(), 'C');
    ASSERT_EQ(node->GetData(), 'A');
     
    delete(node); // TODO: and other clean code needed
  }
  static void NodeSingleEraseNextTest() {
    Node *node = new Node('A');
    Node *insertedNode = node->InsertNextNode('B');
    bool returnValue = node->EraseNextNode();

    ASSERT_EQ(returnValue, true);
    ASSERT_NE(node->GetNextNode(), insertedNode);

    delete(node); // TODO: and other clean code needed
  }

  static void NodeSingleEraseNextWithExistTest() {
    Node *node = new Node('A');
    Node *insertedNode = node->InsertNextNode('C');
    Node *insertedNode2 = node->InsertNextNode('B');

    bool return1 = node->EraseNextNode();

    ASSERT_EQ(return1, true);
    ASSERT_EQ(node->GetNextNode(), insertedNode);
    ASSERT_EQ(node->GetNextNode()->GetData(), 'C');
    ASSERT_EQ(node->GetData(), 'A');

    delete(node); // TODO: and other clean code needed
  }
public:
  static void RunTest() {
    NodeSingleErasePreviousTest();
    NodeSingleErasePreviousWithExistTest();
    NodeSingleEraseNextTest();
    NodeSingleEraseNextWithExistTest();
  }
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  NodeInsertTestSuite::RunTest();
  NodeEraseTestSuite::RunTest();
  // add more..
}