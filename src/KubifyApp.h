#pragma once

#include <string>
using std::string;

#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"   // support for loading levels from the environment variable
#include "spdlog/fmt/ostr.h"  // support for user defined types

#include "apps/ClusterApp.h"
#include "apps/ContentsApp.h"


namespace kubify {
    
    class KubifyApp {

        public:
            apps::ClusterApp cluster_app;
            apps::ContentsApp contents_app;
            
    };

}
