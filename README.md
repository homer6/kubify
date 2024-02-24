# Kubify

Kubify is a modern c++ application designed to simplify your Kubernetes deployments.

## Building

```
cmake -S . -B build
cmake --build build --target all
```

## Running

```
./build/kubify contents prompt --ignore src/CLI /docs /tests /build -- . > contents.txt

./build/kubify contents graph --ignore src/CLI /docs /tests /build -- . > project.gv
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
