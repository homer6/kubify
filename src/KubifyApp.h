#pragma once

#include <string>

#include "FileSystemDirectoryReader.h"
#include "Graph.h"


namespace kubify {
    
    class KubifyApp {

        public:
            std::string run() {

                FileSystemDirectoryReader reader(".");
                reader.populateGraph(graph);

                return graph.print();
            }


        Graph graph;
            
    };

}
