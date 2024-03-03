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


## Installation

To install Kubify on Ubuntu, follow these steps:

1. Go to the [Releases page](https://github.com/homer6/kubify/releases) of the Kubify repository.

2. Download the latest release asset for Ubuntu. Look for a file named like `kubify-vX.X.X-ubuntu-latest`, where `X.X.X` is the version number.

3. Make the downloaded binary executable:

   ```bash
   chmod +x kubify-vX.X.X-ubuntu-latest
   ```

4. Move the binary to a directory in your `PATH` (optional, but recommended for easier execution):

   ```bash
   sudo mv kubify-vX.X.X-ubuntu-latest /usr/local/bin/kubify
   ```

5. You can now run Kubify using the `kubify` command:

   ```bash
   kubify
   ```

## Usage

Provide instructions on how to use your application here.
