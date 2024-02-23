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

    {
        // Bootstrap new cluster command
        CLI::App *bootstrap = cluster_app->add_subcommand("bootstrap", "Initializes a new local Kubernetes cluster using k3s.");
        std::string cluster_name;
        std::string k3s_version = "latest";
        bootstrap->add_option("--name", cluster_name, "The unique name for the new Kubernetes cluster")->required();
        bootstrap->add_option("--version", k3s_version, "Specifies the version of k3s to use. Defaults to the latest stable release.");

        // List clusters command
        cluster_app->add_subcommand("list", "Lists all bootstrapped local Kubernetes clusters with their status and names.");

        // Get cluster info command
        CLI::App *info = cluster_app->add_subcommand("info", "Displays information about a specific local k3s cluster.");
        info->add_option("--name", cluster_name, "The name of the Kubernetes cluster to retrieve information for")->required();

        // Stop cluster command
        CLI::App *stop = cluster_app->add_subcommand("stop", "Stops a specific local k3s cluster.");
        stop->add_option("--name", cluster_name, "The name of the Kubernetes cluster to stop")->required();

        // Start cluster command
        CLI::App *start = cluster_app->add_subcommand("start", "Starts a specific stopped local k3s cluster.");
        start->add_option("--name", cluster_name, "The name of the Kubernetes cluster to start")->required();

        // Delete cluster command
        CLI::App *del = cluster_app->add_subcommand("delete", "Deletes a specific local k3s cluster and cleans up all associated resources.");
        del->add_option("--name", cluster_name, "The name of the Kubernetes cluster to delete")->required();

        // Set current cluster command
        CLI::App *use = cluster_app->add_subcommand("use", "Sets a specific local k3s cluster as the current context for subsequent kubify operations.");
        use->add_option("--name", cluster_name, "The name of the Kubernetes cluster to set as the current context")->required();

        CLI11_PARSE(app, argc, argv);

        if (*bootstrap) {
            kubify_app.cluster_app.bootstrap(cluster_name, k3s_version);
        } else if (*info) {
            kubify_app.cluster_app.info(cluster_name);
        } else if (*stop) {
            kubify_app.cluster_app.stop(cluster_name);
        } else if (*start) {
            kubify_app.cluster_app.start(cluster_name);
        } else if (*del) {
            kubify_app.cluster_app.del(cluster_name);
        } else if (*use) {
            kubify_app.cluster_app.use(cluster_name);
        }

    }


    return 0;

}
