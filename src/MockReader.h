#pragma once

#include "Reader.h"
#include "Graph.h"

namespace kubify {

    class MockReader : public Reader {

        public:

            void populateGraph(Graph& graph) override {

                // Simulating a directory structure:
                // /root
                // /root/child1
                // /root/child2

                std::string rootId = "root";
                std::string child1Id = "root/child1";
                std::string child2Id = "root/child2";

                graph.addNode(rootId);
                graph.addNode(child1Id);
                graph.addNode(child2Id);

                graph.addEdge(rootId, child1Id);
                graph.addEdge(rootId, child2Id);

            }
            
    };

} // namespace kubify
