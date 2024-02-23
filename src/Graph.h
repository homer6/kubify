#pragma once

#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <queue>

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



            std::string print( const std::string& rootId ) const {

                std::stringstream ss;
                std::unordered_set<std::string> visited; // Tracks visited nodes to avoid duplicates

                ss << "digraph G {\n";
                ss << "  rankdir=LR;\n"; // Set graph direction from top to bottom

                if (nodes.find(rootId) == nodes.end()) {
                    ss << "}\n";
                    return ss.str(); // Return an empty graph if rootId is not found
                }

                std::queue<std::shared_ptr<Node>> queue;
                queue.push(nodes.at(rootId));
                visited.insert(rootId);

                while (!queue.empty()) {
                    auto current = queue.front();
                    queue.pop();

                    // Print the current node if not printed already
                    ss << "  \"" << current->id << "\";\n";

                    for (const auto& neighbor : current->neighbors) {
                        // Check if neighbor is already visited
                        if (visited.find(neighbor->id) == visited.end()) {
                            // Mark as visited
                            visited.insert(neighbor->id);
                            queue.push(neighbor);

                            // Since this neighbor is directly connected and not visited, it's a child
                            // Print edge from current to this child
                            ss << "  \"" << current->id << "\" -> \"" << neighbor->id << "\";\n";
                        }
                        // Note: No need to check for reverse edges, as we only add unvisited children
                    }
                }

                ss << "}\n";
                return ss.str();

            }




    };

}
