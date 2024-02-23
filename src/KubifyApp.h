#pragma once

#include <string>

#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"   // support for loading levels from the environment variable
#include "spdlog/fmt/ostr.h"  // support for user defined types

#include "FileSystemDirectoryReader.h"
#include "Graph.h"

#include "apps/ClusterApp.h"


namespace kubify {
    
    class KubifyApp {

        public:
            std::string run() {

                const string root_path = ".";

                FileSystemDirectoryReader reader(root_path);
                reader.populateGraph(graph);

                //return graph.print(root_path);

                return graph.exportFullContents();
            }


        Graph graph;
        apps::ClusterApp cluster_app;
            
    };

}
