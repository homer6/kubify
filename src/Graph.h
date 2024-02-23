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

            shared_ptr<Node> addNode( const std::string& id );

            void addEdge( const std::string& fromId, const std::string& toId );

            void populate( std::unique_ptr<Reader> reader );


            std::string print( const std::string& rootId ) const;

            std::string exportFullContents() const;



    };

}
