/* shared_ptr represents an object that has multiple owners: one out of several
objects will delete the owned object

an example could be a tcp connection, which is established by multiple threads to
send data. Each thread uses the TCP connection to send data and then terminates. We
want to delete the TCP connection when the last thread has finished executing, but
it is not always the same thread that terminates last; it could be any of the
threads. Alternatively, if we are modeling a graph of connected nodes, we might
want to delete a node when every connection to it is removed from the graph.
unique_ptr does not solve these cases, since there is not a single owner for the
object. shared_ptr can be used in such situations: shared_ptr can be copied many
times, and the object pointed to by the pointer will remain alive until the last
shared_ptr is destroyed. We guarantee that the object remains valid as long as
there is at least one shared_ptr instance pointing to it */
#include <memory>
#include <vector>

class Node
{
    public:
        void addConnectedNode(std::shared_ptr<Node> node);
        void removeConnectedNode(std::shared_ptr<Node> node);

    private:
        std::vector<std::shared_ptr<Node>> d_connections;
};

/* Here, we can see that we are holding many shared_ptr instance to nodes. If we
have a shared_ptr instance to a node, we want to be sure that the node exists, but
when we remove the shared pointer, we do not care about the node anymore: it might
be deleted, or it might be kept alive if there is another node connected to it

You might notice that there might be a problem in the example we showed: what
happens if node A is connected to node B and node B is connected to node A? Both
nodes have a shared_ptr instance to the other, and even if no other node has a
connection to them, they will remain alive because a shared_ptr instance to them
exists. This is an example of circular dependency. When using shared pointers, we
must pay attention to these cases. The standard library offers a different kind of
pointer to handle these situations: std::weak_ptr (read as weak pointer). weak_ptr
is a smart pointer that can be used in conjunction with shared_ptr to solve the
circular dependencies that might happen in our programs. Generally, shared_ptr is
enough to model most cases where unique_ptr does not work, and together they cover
the majority of the uses of dynamic memory in a code base.

Lastly, we are not helpless if we want to use dynamic memory for arrays of which we
know the size only at runtime. unique_ptr can be used with array types, and
shared_ptr can be used with array types starting from C++17 */
std::unique_ptr<int[]>ints = std::make_unique<int[]>();
std::shared_ptr<float[]>floats = std::make_shared<float[]>();