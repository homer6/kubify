# Kubify

Kubify accelerates your workloads into Kubernetes.


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



