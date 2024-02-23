namespace kubify {

    class Node {

        public:
            std::string id; // Unique identifier, e.g., path or name
            std::vector<std::shared_ptr<Node>> neighbors; // Edges to neighbors

            explicit Node(std::string id) : id(std::move(id)) {}
            
    };

}
