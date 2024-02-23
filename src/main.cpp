#include "KubifyApp.h"
#include <iostream>

int main(){

    kubify::KubifyApp app;
    std::cout << app.run() << std::endl;
    return 0;

}
