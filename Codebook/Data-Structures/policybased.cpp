/*
find_by_order(k): return iterator to k'th element(counting from zero)
order_of_key(k) : number of items < k in O(logn) time.
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, 
rb_tree_tag, tree_order_statistics_node_update> ordered_set;
