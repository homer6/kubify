#pragma once


#include <string>
using std::string;


namespace kubify::apps {

    class ClusterApp {

        public:
            void bootstrap( const string& cluster_name, const string& cluster_version ){

                spdlog::info( "Bootstrapping a new cluster with name: {} and cluster version: {}", cluster_name, cluster_version );

            }
            
            void info( const string& cluster_name ){

                spdlog::info( "Retrieving information for cluster with name: {}", cluster_name );

            }


            void stop( const string& cluster_name ){

                spdlog::info( "Stopping cluster with name: {}", cluster_name );

            } 

            void start( const string& cluster_name ){

                spdlog::info( "Starting cluster with name: {}", cluster_name );

            }


            void del( const string& cluster_name ){

                spdlog::info( "Deleting cluster with name: {}", cluster_name );

            }

            void use( const string& cluster_name ){

                spdlog::info( "Setting cluster with name: {} as the current context", cluster_name );

            }


    };

}