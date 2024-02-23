#pragma once

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;


namespace kubify {

    class Node {

        public:
            string id; // Unique identifier, e.g., path or name
            vector<shared_ptr<Node>> neighbors; // Edges to neighbors

            explicit Node(string id) : id(std::move(id)) {}
            
    };

}
