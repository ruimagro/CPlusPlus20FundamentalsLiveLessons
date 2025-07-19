#include <iostream>
#include <random>
#include <array>
#include <format>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;

void worker(int start, int count, array<int, 6>& frequencies, int seed) {
   default_random_engine engine(seed);
   uniform_int_distribution randomDie{1, 6};

   array<int, 6> local_freq{};
   for (int roll = 0; roll < count; ++roll) {
      ++local_freq[randomDie(engine) - 1];
   }

   // Add local results to global frequencies
   for (int i = 0; i < 6; ++i) {
#pragma atomic
      frequencies[i] += local_freq[i];
   }
}

int main() {
   array<int, 6> frequencies{};
   const int TOTAL_ROLLS = 60'000'000;
   const int NUM_THREADS = thread::hardware_concurrency();
   const int ROLLS_PER_THREAD = TOTAL_ROLLS / NUM_THREADS;

   auto start = high_resolution_clock::now();

   vector<thread> threads;
   for (int t = 0; t < NUM_THREADS; ++t) {
      threads.emplace_back(worker,
          t * ROLLS_PER_THREAD,
          ROLLS_PER_THREAD,
          ref(frequencies),
          t);
   }

   // Wait for all threads to complete
   for (auto& t : threads) {
      t.join();
   }

   auto end = high_resolution_clock::now();
   auto duration = duration_cast<milliseconds>(end - start);
   auto duration_nano = duration_cast<nanoseconds>(end - start);

   cout << format("{:>4}{:>13}\n", "Face", "Frequency");
   for (int i = 0; i < 6; ++i) {
      cout << format("{:>4}{:>13}\n", i + 1, frequencies[i]);
   }

   cout << format("\nExecution time: {} milliseconds\n", duration.count());
   cout << format("Execution time: {} nanoseconds\n", duration_nano.count());
   cout << format("Number of threads: {}\n", NUM_THREADS);
}