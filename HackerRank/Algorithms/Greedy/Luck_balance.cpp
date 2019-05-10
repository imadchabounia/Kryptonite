int luckBalance(int k, vector<vector<int>> contests) {

  // in order to following a greedy approach we will consider that lena loses all contests

  // contests and the amount of luck are represented as a 2D array (matrix)

  int luck_balance = 0;
  vector<int> importants;
  vector<int> not_importants;

  for(int i = 0; i < contests.size(); i++){

      if(contests[i][1] == 1) importants.push_back(contests[i][0]);
      else not_importants.push_back(contests[i][0]);

  }

  sort(importants.begin(), importants.end(), greater<int>());
  sort(not_importants.begin(), not_importants.end());

  if(!importants.empty())
  for(int i = 0; i < k; i++){
    luck_balance += importants[i];
  }

  if(!not_importants.empty())
  for(int i = 0; i < not_importants.size(); i++){
    luck_balance += not_importants[i];
  }

  // she has to win only one contest for maximizing the luck luckBalance
  for(int i = k; i < importants.size(); i++){
    luck_balance -= importants[i];
  }

  return luck_balance;
}
