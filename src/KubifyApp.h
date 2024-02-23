#pragma once

#include <string>

#include "FileSystemDirectoryReader.h"
#include "Graph.h"


namespace kubify {
    
    class KubifyApp {

        public:
            std::string run() {

                const string root_path = ".";

                FileSystemDirectoryReader reader(root_path);
                reader.populateGraph(graph);

                return graph.print(root_path);
            }


        Graph graph;
            
    };

}
