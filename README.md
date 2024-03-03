# Kubify

Kubify accelerates your team into Kubernetes.

## Description

- Quickly and automatically launches your software into a new or existing Kubernetes cluster with cluster autoscaling and workload autoscaling for cost-efficient, resource-efficient, and scalable workloads.
- Automatically detects all required infrastructure for your software, automatically provisions it into Kubernetes, and connects it to your application.
- Automatically creates CI/CD pipelines for streamlined development and deployment.
- Enables hot-reloading for fast, responsive development changes launched into Kubernetes.
- Quickly install other cluster needs, such as observability.
- Quickly backup, restore, query, or modify any Kubernetes cluster.
- Kubify create and manages an opinionated Kubernetes cluster to deliver on the promises of cloud native.
- Kubify tries to use stable CNCF projects as components, wherever possible.


## Examples

```bash
# Create an LLM prompt for your project
kubify contents prompt --ignore src/CLI /docs /tests /build -- . > contents.txt

# Create a GraphViz representation of your project
kubify contents graph --ignore src/CLI /docs /tests /build -- . > project.gv

# Connect to k8s and export all kinds
kubify k8s export kinds > all_kinds.json

# Connect to k8s and export all resources
kubify k8s export resources > all_resources.json
```


## Build Requirements

https://github.com/homer6/kubepp


## Build and Install

```bash
cmake .
make -j4
sudo make install
sudo ldconfig
```



