#include <iostream>
#include <random>
#include <array>
#include <format>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace std::chrono;

int main() {
   int freq0{0}, freq1{0}, freq2{0}, freq3{0}, freq4{0}, freq5{0};

   auto start = high_resolution_clock::now();

#pragma omp parallel
   {
      default_random_engine engine(omp_get_thread_num()); // Seed based on thread number
      uniform_int_distribution randomDie{1, 6};

#pragma omp for reduction(+:freq0,freq1,freq2,freq3,freq4,freq5)
      for (int roll = 1; roll <= 60'000'000; ++roll) {
         switch (randomDie(engine)) {
            case 1: ++freq0; break;
            case 2: ++freq1; break;
            case 3: ++freq2; break;
            case 4: ++freq3; break;
            case 5: ++freq4; break;
            case 6: ++freq5; break;
         }
      }
   }


   auto end = high_resolution_clock::now();
   auto duration = duration_cast<milliseconds>(end - start);
   auto duration_nano = duration_cast<nanoseconds>(end - start);

   // Store results in array for easier printing
   array<int, 6> frequencies{freq0, freq1, freq2, freq3, freq4, freq5};

   cout << format("{:>4}{:>13}\n", "Face", "Frequency");
   for (int i = 0; i < 6; ++i) {
      cout << format("{:>4}{:>13}\n", i + 1, frequencies[i]);
   }

   cout << format("\nExecution time: {} milliseconds\n", duration.count());
   cout << format("Execution time: {} nanoseconds\n", duration_nano.count());
   cout << format("Number of threads: {}\n", omp_get_max_threads());
}