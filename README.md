# Kubify

Kubify accelerates your workloads into Kubernetes.

## Build and Install

```
cmake .
make -j4
sudo make install
sudo ldconfig
```

## Running

```
kubify contents prompt --ignore src/CLI /docs /tests /build -- . > contents.txt

kubify contents graph --ignore src/CLI /docs /tests /build -- . > project.gv

kubify k8s export kinds > all_kinds.json

kubify k8s export resources > all_resources.json
```

