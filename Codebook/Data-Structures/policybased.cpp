/*
find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
*/
include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key