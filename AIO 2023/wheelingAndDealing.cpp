#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

// #define TESTING

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("dealin.txt", "r", stdin);
	#ifndef TESTING
		freopen("dealout.txt", "w", stdout);
	#endif
	
	int n, m;
	std::cin >> n >> m;
	int v[m], p[m];
	for(int i = 0; i < m; i++) {
		std::cin >> v[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> p[i];
	}
	
	std::vector<std::pair<int, int>> allRivalVotes; // ALL THE VOTES FOR RIVALS with candidates - NEVER CHANGED
	
	int educatedCitizens = 0;
	for(int i = 0, j = 0; i < m; i++) {
		if(v[i] == 1) {
			educatedCitizens++;
		} else {
			allRivalVotes.push_back({p[i], v[i] - 2}); // Sorting is done on the first element - the price
		}
	}
	std::sort(allRivalVotes.begin(), allRivalVotes.end()); // We now have a sorted vector of pairs, the first is the price (sorted), the second is the candidate number
	// allRivalVotes example: [ [$1, rival0 ], [$1, rival2], [$2, rival0], [$4, rival1], etc.]
	
	std::vector<std::queue<int>> voteIndicesForRivals(n - 1);
	for(int i = 0; i < allRivalVotes.size(); i++) {
		std::pair<int, int> vote = allRivalVotes[i];
		voteIndicesForRivals[vote.second].push(i); // votesForRivals now contains a queue of indices for which votes in allRivalVotes it contains
	}
	// voteIndicesForRivals example: [ [0, 2], [3], [1] ]
	
	std::set<std::pair<int, int>> numberOfVotesForRivals;
	for(int i = 0; i < n - 1; i++) {
		numberOfVotesForRivals.insert({voteIndicesForRivals[i].size(), i});
	}
	// numberOfVotesForRivals is now a set where each entry contains [how many votes for, candidate i]
	
	int rivalCosts = 0;
	int bestCost;
	
	std::set<std::pair<int, int>> toBuy; // Set containing all the people we HAVE to buy to reach target - [cost, rivalVoteIndex]
	int toBuyTotal = 0; // Everytime we modify toBuy, we have to modify toBuyTotal as well
	std::set<std::pair<int, int>> notToBuy; // Set containing all the people
	for(int i = 0; i < allRivalVotes.size(); i++) {
		notToBuy.insert({allRivalVotes[i].first, i});
	}
	
	for(int target = m; target >= 1; target--) {
		int cost = 0;
		while((*numberOfVotesForRivals.rbegin()).first >= target) {
			std::pair<int, int> mostPopularRival = *numberOfVotesForRivals.rbegin();
			int candidateNumber = mostPopularRival.second;
			int voteI = voteIndicesForRivals[candidateNumber].front();
			voteIndicesForRivals[candidateNumber].pop();
			int voteCost = allRivalVotes[voteI].first;
			rivalCosts += voteCost;
			#ifdef TESTING
				std::cout << "eliminating vote $" << voteCost << " for rival " << candidateNumber + 2 << std::endl;
			#endif
			
			numberOfVotesForRivals.erase(mostPopularRival);
			numberOfVotesForRivals.insert({mostPopularRival.first - 1, mostPopularRival.second});
			
			std::pair<int, int> indexedVote = {voteCost, voteI};
			if(notToBuy.count(indexedVote)) {
				notToBuy.erase(indexedVote);
			} else if(toBuy.count(indexedVote)) {
				toBuy.erase(indexedVote);
				toBuyTotal -= voteCost;
			} else {
				throw std::runtime_error(""); // This should never happen
			}
			educatedCitizens++;
		}
		cost += rivalCosts;
		#ifdef TESTING
			std::cout << "rival costs: $" << rivalCosts << std::endl;
		#endif
		
		int remainingRequiredVotes = std::max(target - educatedCitizens, 0);
		while(toBuy.size() < remainingRequiredVotes) { // Not enough voters to buy - fill them up from notToBuy
			std::pair<int, int> cheapestVote = *notToBuy.begin(); // notToBuy is sorted cheapest -> most expensive
			notToBuy.erase(cheapestVote);
			toBuy.insert({allRivalVotes[cheapestVote.second].first, cheapestVote.second});
			toBuyTotal += cheapestVote.first;
		}
		while(toBuy.size() > remainingRequiredVotes) { // Too many voters - move them back to notToBuy
			std::pair<int, int> mostExpensiveVote = *toBuy.rbegin();
			toBuy.erase(mostExpensiveVote);
			notToBuy.insert({allRivalVotes[mostExpensiveVote.second].first, mostExpensiveVote.second});
			toBuyTotal -= mostExpensiveVote.first;
		}
		cost += toBuyTotal;
		#ifdef TESTING
			std::cout << "cost to reach target is $" << toBuyTotal << std::endl;
			std::cout << "total cost for target " << target << " is $" << cost << std::endl << "--------------------" << std::endl;
		#endif
		if(target == m || cost < bestCost) {
			bestCost = cost;
		}
	}
	#ifdef TESTING
		std::cout << "min cost: ";
	#endif
	std::cout << bestCost;
	
	return 0;
}