#pragma once

#include <filesystem>
#include "Reader.h"
#include "Graph.h"

#include <string>
using std::string;

#include <vector>
using std::vector;


#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

static std::string read_file_contents( const std::filesystem::path& pathToFile ) {

    if( fs::is_regular_file(pathToFile) ){

        std::ifstream fileStream(pathToFile, std::ios::binary);
        if (!fileStream.is_open()) {
            throw std::runtime_error("Could not open file: " + pathToFile.string());
        }

        std::string fileContents((std::istreambuf_iterator<char>(fileStream)),
                                std::istreambuf_iterator<char>());
        return fileContents;

    } else {

        //throw std::runtime_error(pathToFile.string() + " is a directory, not a file");
        return "is_directory";

    }


}




namespace kubify {

    class FileSystemDirectoryReader : public Reader {

        public:

            FileSystemDirectoryReader(const string& root_path)
                :root_path(root_path)
            {

            } 


            void populateGraph( Graph& graph ) override {
                addDirectory(graph, this->root_path);
            }



            const string root_path;

        private:

            void addDirectory( Graph& graph, const std::string& path ){

                // ignore common paths (eg. .git, .vscode, CMakeFiles, etc.)
                vector<string> ignore = {".git", ".vscode", "CMakeFiles"};
                for (auto i : ignore){
                    if (path.find(i) != std::string::npos){
                        return;
                    }
                }
             

                for( const auto& entry : std::filesystem::directory_iterator(path) ){
                    std::string nodeId = entry.path().string();
                    std::string parentId = entry.path().parent_path().string();
                    
                    // Ensure nodeId and parentId are relative to root_path if needed

                    auto node = graph.addNode(nodeId);

                    //read file contents into node contents
                    node->contents = read_file_contents(nodeId);

                    if( nodeId != root_path ){ // Avoid linking root to itself
                        graph.addEdge(parentId, nodeId);
                    }

                    if( entry.is_directory() ){
                        addDirectory(graph, nodeId);
                    }
                }

            }
            
    };

}
