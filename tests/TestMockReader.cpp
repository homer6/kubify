#include <gtest/gtest.h>
#include "Graph.h"
#include "MockReader.h"

using namespace kubify;

TEST(MockReaderTest, PopulatesGraphCorrectly) {

    Graph graph;
    auto reader = std::make_unique<MockReader>();
    graph.populate(std::move(reader));

    // Verify nodes exist
    ASSERT_TRUE(graph.nodes.find("Root") != graph.nodes.end());
    ASSERT_TRUE(graph.nodes.find("Child1") != graph.nodes.end());
    ASSERT_TRUE(graph.nodes.find("Child2") != graph.nodes.end());

    // Verify edges (connections between nodes)
    auto rootChildren = graph.nodes["Root"]->neighbors;
    ASSERT_EQ(rootChildren.size(), 2); // Assuming undirected graph implementation
    
}
