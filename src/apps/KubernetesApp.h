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

            void test(){

                KubernetesClient kube_client;

                // get several resource types
                    json workloads = kube_client.runQuery( "SELECT * FROM Pod, Deployment, stable.example.com/v1:CronTab" );
                    cout << workloads.dump(4) << endl;


                // get all resources
                    json all_resources = kube_client.runQuery( "SELECT * FROM *" );
                    cout << all_resources.dump(4) << endl;


                // create, then delete a CustomResource
                    json cr = R"({
                        "apiVersion": "stable.example.com/v1",
                        "kind": "CronTab",
                        "metadata": {
                            "name": "my-crontab",
                            "namespace": "default"
                        },
                        "spec": {
                            "cronSpec": "*/5 * * * *",
                            "image": "my-cron-image:latest",
                            "replicas": 3
                        }
                    })"_json;

                    // supports one or many resources
                    json cr_response = kube_client.createResources( cr );
                    cout << cr_response.dump(4) << endl;

                    json delete_cr_response = kube_client.deleteResources( cr );
                    cout << delete_cr_response.dump(4) << endl;
                
            }



    };

}







