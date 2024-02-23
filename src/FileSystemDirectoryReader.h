#include <filesystem>
#include "Reader.h"
#include "Graph.h"

namespace kubify {

    class FileSystemDirectoryReader : public Reader {

        public:
            void populateGraph(Graph& graph, std::string rootPath = ".") override {
                addDirectory(graph, rootPath);
            }


        private:

            void addDirectory(Graph& graph, const std::string& basePath ){

                for (const auto& entry : std::filesystem::directory_iterator(basePath)) {
                    std::string nodeId = entry.path().string();
                    std::string parentId = entry.path().parent_path().string();
                    
                    // Ensure nodeId and parentId are relative to basePath if needed

                    graph.addNode(nodeId);
                    if (nodeId != basePath) { // Avoid linking root to itself
                        graph.addEdge(parentId, nodeId);
                    }

                    if (entry.is_directory()) {
                        addDirectory(graph, basePath, nodeId);
                    }
                }

            }
            
    };

} // namespace kubify
