#pragma once


#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <sstream>

#include "FileSystemDirectoryReader.h"
#include "Graph.h"



#include <kubepp/KubernetesClient.h>
using kubepp::KubernetesClient;

#include <kubepp/json.hpp>
using json = nlohmann::json;



namespace kubify::apps {

    class KubernetesApp {

        public:

            void exportKinds(){

                KubernetesClient kube_client;

                json all_kinds = kube_client.getApiResources();
                cout << all_kinds.dump(4) << endl;
                
            }


            void exportResources(){


               
                KubernetesClient kube_client;

                json all_resources = kube_client.runQuery( "SELECT * FROM *" );
                json all_json_ptr_resources = all_resources.flatten();


                // filter out some fields

                    const vector<string> ignore_fields = { 
                        "metadata/managedFields", 
                        "metadata/resourceVersion",
                        "metadata/uid",
                        "/status/"
                    };
                

                json results = json::object();

                for( const auto& [key, value] : all_json_ptr_resources.items() ){

                    bool filter = false;

                    for( const string& ignore_field : ignore_fields ){

                        if( key.find(ignore_field) != string::npos ){
                            filter = true;
                            break;
                        }

                    }

                    if( !filter ){
                        results[key] = value;
                    }

                }


                // unflatten and pretty print the filtered json

                    cout << results.unflatten().dump(4) << endl;
                
            }




    };

}







