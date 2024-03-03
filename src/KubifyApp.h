#pragma once

#include <string>
using std::string;

#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"   // support for loading levels from the environment variable
#include "spdlog/fmt/ostr.h"  // support for user defined types

#include "apps/ClusterApp.h"
#include "apps/ContentsApp.h"
#include "apps/KubernetesApp.h"


namespace kubify {
    
    class KubifyApp {

        public:
            apps::ClusterApp cluster_app;
            apps::ContentsApp contents_app;
            apps::KubernetesApp kubernetes_app;
            
    };

}
