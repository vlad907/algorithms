// CSCI 411 - Fall 2024
// Assignment 3 - Chess Streaks
// Author: Carter Tillquist
// Feel free to use all, part, or none of this code for the investigation of chess streaks using Monte Carlo simulation

#include <iostream>
#include <vector>
#include <random>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <climits>
#include <fstream>
/************************************************************************************
 * Simulate a game between a player with Elo A and a player with Elo B              *
 * A - float - the Elo rating of the first player                                   *
 * B - float - the Elo rating of the second player                                  *
 * generator - std::default_random_engine& - a random number generator used in      *
 *             determining the outcome of the game                                  *
 * return - float - 1 if player A wins, 0.5 if the players draw, 0 if player B wins *
 ************************************************************************************/
float simGame(float A, float B, std::default_random_engine& generator){
  std::uniform_real_distribution<float> unif(0.0f, 1.0f);
  float val = unif(generator);
  float T = (1.0f / 8.0f) * exp(-pow((A - B) / 400.0f, 2.0f));
  float W = (1.0f / (1.0f + pow(10.0f, -(A - B) / 400.0f)))-(0.5f * T);
  
  if (val < W) {
      return 1.0f;  
  } else if (val < W + T) {
      return 0.5f;  
  } else {
      return 0.0f;
  }
}

/**************************************************************************************************************
 * Play a sequence of games with one fixed player. Opponent ratings are drawn from a normal distribution      *
 * A - float - the Elo rating of the player                                                                   *
 * mu - float - the mean of the distribution from which to draw opponent ratings                              *
 * sigma - float - the standard deviation of the distribution from which to draw opponent ratings             *
 * games - int - the number of games to play                                                                  *
 * generator - std::default_random_engine& - a random number generator used in determining an opponent rating *
 * return - std::vector<float> - a sequence of length games consisting of 1s, 0s, and 0.5s representing       *
 *          game outcomes                                                                                     *
 ***************************************************************************************************************/
std::vector<float> simSequence(float A, float mu, float sigma, int games, std::default_random_engine& generator){
  std::vector<float> seq;
  // similar to the use of unif in simGame, think of randElo as a function that returns a random value drawn
  // from a normal distribution when given a source of randomness
  // a line like float B = randElo(generator) may be useful
  std::normal_distribution<float> randElo(mu, sigma);
  // YOUR CODE HERE
  for (int i = 0; i < games; i++) {
    float opponent = randElo(generator);
    float results = simGame(A, opponent, generator);
    seq.push_back(results);
  }
  return seq;
}

/*********************************************************************************************************
 * Calculate the length of streaks in a sequence of games. A streak is allowed to include a single draw. *
 * seq - std::vector<float> - a sequence of game outcomes                                                *
 * return - std::vector<int> - the lengths of streaks present in seq                                     *
 *********************************************************************************************************/
std::vector<int> streakLengths(const std::vector<float>& seq) {
    std::vector<int> lengths;
    
    // Iterate over all starting points in the sequence
    for (int i = 0; i < seq.size(); ++i) {
        int streak_length = 0;
        bool draw_allowed = true;  // One draw is allowed per streak

        for (int j = i; j < seq.size(); ++j) {
            if (seq[j] == 1.0f) {  // Win
                streak_length++;
                lengths.push_back(streak_length);  
            } 
            else if (seq[j] == 0.5f && draw_allowed) {  
                streak_length++;
                lengths.push_back(streak_length);  
                draw_allowed = false;  
            } 
            else { 
                break;
            }
        }
    }

    return lengths;
}

/************************************************************************************************************
 * A function to run all simulations and collect the data                                                   *
 * A - float - the Elo rating of the player to focus on                                                     *
 * mu - float - the mean of a distribution from which to draw opponent Elo values                           *
 * sigma - float - the standard deviation of a distribution from which to draw opponent Elo values          *
 * games - int - the number of games to play per repeat                                                     *
 * repeats - int - the number of game sequences to simulate                                                 *
 * return - std::vector<std::vector<int>> - a two dimensional vector holding streak lengths for all repeats *
 ************************************************************************************************************/
std::vector<std::vector<int>> runSimulations(float A, float mu, float sigma, int games, int repeats){
  std::vector<std::vector<int>> data;
  // set the random seed of the generator
  unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  for (int rep = 0; rep < repeats; rep++){
    std::cout << "rep " << rep << "\n";
    std::vector<float> seq = simSequence(A, mu, sigma, games, generator);
    std::vector<int> lengths = streakLengths(seq);
    data.push_back(lengths);
  }
  return data;
}

/*************************************************************************
 * A function to compute the average value of a vector of ints           *
 * v - std::vector<int> - the vector of values to compute the average of *
 * return - float - the average or mean                                  *
 *************************************************************************/
float mean(std::vector<int> v){
  float sum = 0.0;
  for (int i : v){ sum += i; }
  return sum/v.size();
}

/**********************************************************************************************************************
 * Print statistics associated with the simulations. These should help answer the questions in (5e) on the assignment *
 * data - std::vector<std::vector<int>> - a two dimensional vector holding streak information for each sequence       *
 **********************************************************************************************************************/
void printStats(const std::vector<std::vector<int>>& data) {
    int totalStreaks = 0;
    int totalLength = 0;
    int longestStreak = 0;
    int shortestStreak = INT_MAX;
    int streaksOfLength50OrMore = 0;
    int sequencesWithStreak50OrMore = 0;

    for (const auto& streaks : data) {
        totalStreaks += streaks.size();  // Count the number of streaks in this simulation
        totalLength += std::accumulate(streaks.begin(), streaks.end(), 0);  // Sum the lengths of the streaks

        // If there are streaks in this simulation, find the longest and shortest
        if (!streaks.empty()) {
            int maxInSimulation = *std::max_element(streaks.begin(), streaks.end());
            int minInSimulation = *std::min_element(streaks.begin(), streaks.end());
            longestStreak = std::max(longestStreak, maxInSimulation);
            shortestStreak = std::min(shortestStreak, minInSimulation);

            // Count streaks of length 50 or more
            for (int streak : streaks) {
                if (streak >= 50) {
                    streaksOfLength50OrMore++;  // Increment if streak is 50 or longer
                }
            }

            // If at least one streak is 50 or longer, increment the sequence count
            if (maxInSimulation >= 50) {
                sequencesWithStreak50OrMore++;
            }
        }
    }

    // Calculate average streak length
    float averageStreakLength = (totalStreaks > 0) ? static_cast<float>(totalLength) / totalStreaks : 0.0;

    // Calculate the probability of observing at least one streak of length 50 or more
    float probabilityOfStreak50 = (data.size() > 0) ? static_cast<float>(sequencesWithStreak50OrMore) / data.size() : 0.0;

    // Calculate the average number of streaks of length 50 or more per sequence
    float averageStreaksOfLength50OrMore = (data.size() > 0) ? static_cast<float>(streaksOfLength50OrMore) / data.size() : 0.0;

    // Print the statistics
    std::cout << "Total number of streaks: " << totalStreaks << std::endl;
    std::cout << "Average streak length: " << averageStreakLength << std::endl;
    std::cout << "Longest streak: " << longestStreak << std::endl;
    std::cout << "Shortest streak: " << shortestStreak << std::endl;
    std::cout << "Probability of observing at least one streak of length 50 or longer: " << probabilityOfStreak50 << std::endl;
    std::cout << "Average number of streaks of length 50 or longer per sequence: " << averageStreaksOfLength50OrMore << std::endl;
}

void saveStreakLengths(const std::vector<std::vector<int>>& data, const std::string& filename) {
    std::ofstream outfile(filename);  // Open the file for writing
    if (outfile.is_open()) {
        for (const auto& streaks : data) {
            for (int streak : streaks) {
                outfile << streak << "\n";  // Write each streak length on a new line
            }
        }
        outfile.close();
        std::cout << "Streak lengths saved to " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
    }
}

/***************************************
 * A simple main to run the simulation *
 ***************************************/
int main(){
  float A = 3100;
  float mu = 2750;
  float sigma = 150;
  int games = 60000;
  int repeats = 100;

  std::vector<std::vector<int>> data = runSimulations(A, mu, sigma, games, repeats);
  printStats(data);
  saveStreakLengths(data, "streak.txt");
  return 0;
}


