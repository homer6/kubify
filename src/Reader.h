namespace kubify {

    class Graph; // Forward declaration

    class Reader {
    public:
        virtual ~Reader() = default;

        // Abstract method to populate a graph
        virtual void populateGraph(Graph& graph) = 0;
    };

}
