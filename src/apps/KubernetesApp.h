#pragma once


#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

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
                cout << all_resources.dump(4) << endl;
                
            }




    };

}







