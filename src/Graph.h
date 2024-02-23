#pragma once

#include <unordered_map>
#include <unordered_set>
#include <sstream>

#include "Node.h"
#include "Reader.h"


namespace kubify {

    class Graph {

        public:
            std::unordered_map<std::string, std::shared_ptr<Node>> nodes;

            void addNode( const std::string& id ){
                if( nodes.find(id) == nodes.end() ){
                    nodes[id] = std::make_shared<Node>(id);
                }
            }

            void addEdge( const std::string& fromId, const std::string& toId ){

                this->addNode(fromId); // Ensure nodes exist before adding an edge
                this->addNode(toId);
                this->nodes.at(fromId)->neighbors.push_back( this->nodes.at(toId) );
                // For undirected graph, add the reverse edge as well
                this->nodes[toId]->neighbors.push_back( this->nodes.at(fromId) );

            }

            void populate( std::unique_ptr<Reader> reader ){
                reader->populateGraph(*this); // Delegate the population logic to the Reader
            }

            std::string print() const {

                std::stringstream ss;
                std::unordered_set<std::string> edgesRecorded;

                ss << "digraph G {\n"; // Start of the Graphviz graph

                for (const auto& pair : nodes) {
                    const auto& node = pair.second;
                    // For each node, print the node identifier
                    ss << "  \"" << node->id << "\";\n";

                    // For each edge, print an edge line
                    for (const auto& neighbor : node->neighbors) {
                        std::string edge = node->id + " -> " + neighbor->id;
                        std::string reverseEdge = neighbor->id + " -> " + node->id;

                        // Check if this edge or its reverse has already been recorded
                        if (edgesRecorded.find(edge) == edgesRecorded.end() && edgesRecorded.find(reverseEdge) == edgesRecorded.end()) {
                            ss << "  \"" << node->id << "\" -> \"" << neighbor->id << "\";\n";
                            edgesRecorded.insert(edge);
                        }
                    }
                }

                ss << "}"; // End of the Graphviz graph
                return ss.str();
                
            }

    };

}
