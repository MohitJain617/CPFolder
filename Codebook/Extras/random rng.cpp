  //include <random> and <chrono>
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//   mt19937 rng((uint64_t) new char);