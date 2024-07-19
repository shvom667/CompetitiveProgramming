#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define fbo find_by_order(x)
#define ook(x) order_of_key(x)
/*
 * find_by_order(x) : return the (x + 1) th smallest element
 * order_of_key(x)  : number of elements strictly less than x
 */
