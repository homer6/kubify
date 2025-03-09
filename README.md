# Kubify

Kubify accelerates your software into Kubernetes.

## Description

- Quickly and automatically launches your software into a new or existing Kubernetes cluster with cluster autoscaling and workload autoscaling for cost-efficient, resource-efficient, and scalable workloads.
- Automatically detects all required infrastructure for your software, automatically provisions it into Kubernetes, and connects it to your application.
- Automatically creates CI/CD pipelines for streamlined development and deployment.
- Enables hot-reloading for fast, responsive development changes launched into Kubernetes.
- Quickly install other cluster needs, such as observability.
- Quickly backup, restore, query, or modify any Kubernetes cluster.
- Kubify creates and manages opinionated Kubernetes clusters, offering complete and opinionated developer workflow management, to deliver on the promises of cloud native.
- Kubify tries to use stable [CNCF projects](https://landscape.cncf.io/) as components, wherever possible.


## Examples

```bash
# Generate an LLM prompt for your project
kubify contents prompt --ignore src/CLI /docs /tests /build -- . > contents.txt

# Create a GraphViz representation of your project's directory structure
kubify contents graph --ignore src/CLI /docs /tests /build -- . > project.gv

# Export all kinds in a Kubernetes cluster
kubify k8s export kinds > all_kinds.json

# Export all resources from a Kubernetes cluster for backup or analysis
kubify k8s export resources > all_resources.json

# Kubepp-sql queries with the ability to flatten to JSON Pointer or ignore common fields
kubify k8s export resources --query "SELECT * FROM Pod" --ignore-common-fields > filtered_pods.json
kubify k8s export resources --query "SELECT * FROM Deployment,DaemonSet,StatefulSet" > workloads.json
kubify k8s export resources --query "SELECT * FROM Pod,Job" --flatten > unfiltered_pods_flattened.json

```


## Install

Install [spack](https://spack-tutorial.readthedocs.io/en/latest/tutorial_basics.html)

```bash
spack repo add https://github.com/homer6/spack-repo/spack
spack install kubify
spack load kubify
ln -s $(which gke-gcloud-auth-plugin) ~/.kube/gke-gcloud-auth-plugin
kubify --help
```


## Requirements

- An AWS account with CLI credentials
- Linux-based system (currently; we'll target other platforms soon). Developed on Ubuntu 23.10.


## How it Works

- Kubify creates a local bootstrap k8s cluster (k3s) and injects its operator and secrets into that boostrap cluster.

- From the bootstrap cluster, Kubify then sets up a remote (AWS EKS) cluster as a management cluster. This management cluster serves as a permanent, but small, cluster to offer services that span many child clusters, such as federated auth with [Keycloak](https://www.keycloak.org/), [gitea](https://docs.gitea.com/installation/install-on-kubernetes) for source control management, or [harbor](https://goharbor.io/) for image repository hosting.

- From the management cluster, Kubify will provision one or many regional workload clusters, or other infrastructure such as Cloudflare global service load balancers, DNS entries, etc.


## Build Requirements

https://github.com/homer6/kubepp


## Build and Install (Ubuntu)

```bash
sudo apt-get install libgtest-dev
cmake .
make -j8
sudo make install
sudo ldconfig
```

## Build and Install (MacOS)

```bash
brew install googletest
cmake .
make -j8
sudo make install
```


## Support

Kubify offers [professional support and services](https://kubify.ai), upon request. I'm also happy to help via github issues, whenever possible.