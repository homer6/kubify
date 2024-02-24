#pragma once


#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "FileSystemDirectoryReader.h"
#include "Graph.h"



namespace kubify::apps {

    class ContentsApp {

        public:

            void generateContents( const string& contents_path, const vector<string>& ignore_paths ){

                spdlog::info( "Generating contents for path: {}", contents_path );

                Graph graph;

                FileSystemDirectoryReader reader(contents_path, ignore_paths);
                reader.populateGraph(graph);

                cout << graph.exportFullContents();

                cout << endl << endl;
                cout << ">>> directory structure <<<" << endl << endl;

                cout << graph.print(contents_path);
                
            }



            void printGraph( const string& contents_path, const vector<string>& ignore_paths ){

                spdlog::info( "Printing graph for path: {}", contents_path );

                Graph graph;

                FileSystemDirectoryReader reader(contents_path, ignore_paths);
                reader.populateGraph(graph);

                cout << graph.print(contents_path);
                
            }


    };

}