#include "KubifyApp.h"
#include <CLI/CLI.hpp>
#include <iostream>


int main(int argc, char **argv) {

    // Create logger (defaults to stdout and log level of INFO)
    //auto logger = spdlog::stdout_color_mt("console");


    kubify::KubifyApp kubify_app;
    //std::cout << kubify_app.run() << std::endl;

    CLI::App app{"Kubify - Accelerating your workloads into Kubernetes."};
    app.require_subcommand(1);

    CLI::App *cluster_app = app.add_subcommand("cluster", "Manage local Kubernetes bootstrap clusters.");

    // Manage Cluster app

        // Bootstrap new cluster command
        CLI::App *cluster_bootstrap = cluster_app->add_subcommand("bootstrap", "Initializes a new local Kubernetes cluster using k3s.");
        std::string cluster_name;
        std::string k3s_version = "latest";
        cluster_bootstrap->add_option("--name", cluster_name, "The unique name for the new Kubernetes cluster")->required();
        cluster_bootstrap->add_option("--version", k3s_version, "Specifies the version of k3s to use. Defaults to the latest stable release.");

        // List clusters command
        cluster_app->add_subcommand("list", "Lists all bootstrapped local Kubernetes clusters with their status and names.");

        // Get cluster info command
        CLI::App *cluster_info = cluster_app->add_subcommand("info", "Displays information about a specific local k3s cluster.");
        cluster_info->add_option("--name", cluster_name, "The name of the Kubernetes cluster to retrieve information for")->required();

        // Stop cluster command
        CLI::App *cluster_stop = cluster_app->add_subcommand("stop", "Stops a specific local k3s cluster.");
        cluster_stop->add_option("--name", cluster_name, "The name of the Kubernetes cluster to stop")->required();

        // Start cluster command
        CLI::App *cluster_start = cluster_app->add_subcommand("start", "Starts a specific stopped local k3s cluster.");
        cluster_start->add_option("--name", cluster_name, "The name of the Kubernetes cluster to start")->required();

        // Delete cluster command
        CLI::App *cluster_delete = cluster_app->add_subcommand("delete", "Deletes a specific local k3s cluster and cleans up all associated resources.");
        cluster_delete->add_option("--name", cluster_name, "The name of the Kubernetes cluster to delete")->required();

        // Set current cluster command
        CLI::App *cluster_use = cluster_app->add_subcommand("use", "Sets a specific local k3s cluster as the current context for subsequent kubify operations.");
        cluster_use->add_option("--name", cluster_name, "The name of the Kubernetes cluster to set as the current context")->required();


    // Contents command
        CLI::App *contents_app = app.add_subcommand("contents", "Manage the project's contents.");
        string contents_path = "."; // Default path is the current directory
        const vector<string> default_ignore_paths = {".git", ".vscode", "CMakeFiles"};
        vector<string> ignore_paths;


        // Generate prompt command
        CLI::App *contents_prompt_app = contents_app->add_subcommand("prompt", "Generate a prompt from the project's contents (stdout).");
        contents_prompt_app->add_option("path", contents_path, "The path to list contents for. Defaults to the current directory.")
                            ->default_val(contents_path);
        contents_prompt_app->add_option("--ignore", ignore_paths, "Paths to ignore. Can specify multiple times.")
                            ->expected(-1); // Allows multiple instances



        // Generate project's graph command
        CLI::App *contents_graph_app = contents_app->add_subcommand("graph", "Generate a graphviz document from the project's contents (stdout).");
        contents_graph_app->add_option("path", contents_path, "The path to list contents for. Defaults to the current directory.")
                            ->default_val(contents_path);
        contents_graph_app->add_option("--ignore", ignore_paths, "Paths to ignore. Can specify multiple times.")
                        ->expected(-1); // Allows multiple instances



        // Kubernetes command
        CLI::App *kubernetes_app = app.add_subcommand("k8s", "Manage Kubernetes resources.");
        CLI::App *kubernetes_export_app = kubernetes_app->add_subcommand("export", "Export Kubernetes resources to a file.");
        CLI::App *kubernetes_export_kinds_app = kubernetes_export_app->add_subcommand("kinds", "Export all Kubernetes resources types (kinds) to stdout.");
        CLI::App *kubernetes_export_resources_app = kubernetes_export_app->add_subcommand("resources", "Export all Kubernetes resources to stdout.");
        
        kubernetes_export_resources_app->add_flag("--flatten", "Flatten the resources to JSON Pointers.");

        string kubepp_sql_query;
        kubernetes_export_resources_app->add_option("--query", kubepp_sql_query, "Apply a kubepp-sql query to the resources.")
                                        ->default_val("SELECT * FROM *");

        kubernetes_export_resources_app->add_flag("--ignore-common-fields", "Ignore common fields like metadata/uid, metadata/resourceVersion, metadata/managedFields, and status fields.");



    // parse the command line arguments

        CLI11_PARSE(app, argc, argv);


        ignore_paths.insert( ignore_paths.end(), default_ignore_paths.begin(), default_ignore_paths.end() );


        // cluster command

            if( *cluster_bootstrap ){
                kubify_app.cluster_app.bootstrap(cluster_name, k3s_version);
            }else if( *cluster_info ){
                kubify_app.cluster_app.info(cluster_name);
            }else if( *cluster_stop ){
                kubify_app.cluster_app.stop(cluster_name);
            }else if( *cluster_start ){
                kubify_app.cluster_app.start(cluster_name);
            }else if( *cluster_delete ){
                kubify_app.cluster_app.del(cluster_name);
            }else if( *cluster_use ){
                kubify_app.cluster_app.use(cluster_name);
            }


        // contents command

            else if (*contents_prompt_app) {

                for( const string& ignore_path : ignore_paths ){
                    std::cout << "Ignoring: " << ignore_path << std::endl;
                }
                kubify_app.contents_app.generateContents(contents_path, ignore_paths);

            }else if( *contents_graph_app ){

                for( const string& ignore_path : ignore_paths ){
                    std::cout << "Ignoring: " << ignore_path << std::endl;
                }
                kubify_app.contents_app.printGraph(contents_path, ignore_paths);
            }

        // k8s command

            else if( *kubernetes_export_kinds_app ){
                kubify_app.kubernetes_app.exportKinds();
            }else if( *kubernetes_export_resources_app ){
                bool flatten = kubernetes_export_resources_app->count("--flatten");
                bool ignore_common_fields = kubernetes_export_resources_app->count("--ignore-common-fields");

                kubify_app.kubernetes_app.exportResources( kubepp_sql_query, flatten, ignore_common_fields );
            }

    return 0;

}
