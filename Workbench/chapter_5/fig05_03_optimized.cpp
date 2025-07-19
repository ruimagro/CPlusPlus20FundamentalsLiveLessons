// fig05_03.cpp
// Rolling a six-sided die randomly 60,000,000 times.
#include <format>
#include <iostream>
#include <random>
#include <iomanip>
#include <chrono>  // for timing

using namespace std;
using namespace std::chrono;  // for timing functions



int main() {
   // set up random-number generation
   default_random_engine engine{};
   uniform_int_distribution randomDie{1, 6};

   array<int, 6> frequencies{};

   // Start the timer
   auto start = high_resolution_clock::now();

   // Roll the die 60,000,000 times
   for (int roll = 1; roll <= 60'000'000; ++roll) {
      ++frequencies[randomDie(engine) - 1];
   }

   // End the timer
   auto end = high_resolution_clock::now();

   // Calculate duration in milliseconds
   auto duration = duration_cast<milliseconds>(end - start);
   auto duration_nano = duration_cast<nanoseconds>(end - start);

   // Output results
   cout << setw(4) << "Face" << setw(13) << "Frequency" << '\n';
   for (int i = 0; i < 6; ++i) {
      cout << setw(4) << (i + 1) << setw(13) << frequencies[i] << '\n';
   }

   // Print the execution time
   cout << "\nExecution time: " << duration.count() << " milliseconds\n";
   cout << "\nExecution time: " << duration_nano.count() << " nanoseconds\n";
} 




/**************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
