#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

set<pair<int, int>> s_obstacles;

pair<int, int> init(int q_r, int q_c) {

  pair<int, int> queen;
  queen.first = q_r;
  queen.second = q_c;

  return queen;
}

int goUp(int q_r, int q_c, int n) {

  pair<int, int> queen = init(q_r, q_c);
  int num = 0;

  pair<int, int> nex_step = queen;

  nex_step.first += 1;

  while ((nex_step.first < n) &&
         s_obstacles.find(nex_step) == s_obstacles.end()) {

    num += 1;
    nex_step.first += 1;
  }

  return num;
}

int goDown(int q_r, int q_c) {

  pair<int, int> queen = init(q_r, q_c);
  int num = 0;
  pair<int, int> nex_step = queen;

  nex_step.first -= 1;

  while ((nex_step.first >= 0) &&
         s_obstacles.find(nex_step) == s_obstacles.end()) {
    num += 1;
    nex_step.first -= 1;
  }

  return num;
}

int goLeft(int q_r, int q_c) {

  int lower_bound = 0;
  pair<int, int> queen = init(q_r, q_c);
  int num = 0;
  pair<int, int> nex_step = queen;
  nex_step.second -= 1;

  while ((nex_step.second >= 0) &&
         s_obstacles.find(nex_step) == s_obstacles.end()) {
    num += 1;
    nex_step.second -= 1;
  }

  return num;
}

int goRight(int q_r, int q_c, int n) {

  int upper_bound = n;
  pair<int, int> queen = init(q_r, q_c);
  int num = 0;
  pair<int, int> nex_step = queen;
  nex_step.second += 1;

  while ((nex_step.second < n) &&
         s_obstacles.find(nex_step) == s_obstacles.end()) {
    num += 1;
    nex_step.second += 1;
  }

  return num;
}

int diagonal1(int q_r, int q_c, int n) {

  pair<int, int> queen = init(q_r, q_c);
  int num = 0;
  pair<int, int> next_step = queen;
  next_step.second -= 1;
  next_step.first += 1;

  while ((next_step.second >= 0 && next_step.first < n) &&
         s_obstacles.find(next_step) == s_obstacles.end()) {
    num += 1;
    next_step.second -= 1;
    next_step.first += 1;
  }

  next_step = queen;

  next_step.second += 1;
  next_step.first -= 1;

  while ((next_step.second < n && next_step.first >= 0) &&
         s_obstacles.find(next_step) == s_obstacles.end()) {
    num += 1;
    next_step.second += 1;
    next_step.first -= 1;
  }

  return num;
}

int diagonal2(int q_r, int q_c, int n) {

  pair<int, int> queen = init(q_r, q_c);
  int num = 0;
  pair<int, int> next_step = queen;

  next_step.second -= 1;
  next_step.first -= 1;

  while ((next_step.second >= 0 && next_step.first >= 0) &&
         s_obstacles.find(next_step) == s_obstacles.end()) {

    num += 1;
    next_step.second -= 1;
    next_step.first -= 1;
  }

  next_step = queen;
  next_step.second += 1;
  next_step.first += 1;

  while ((next_step.second < n && next_step.first < n) &&
         s_obstacles.find(next_step) == s_obstacles.end()) {

    num += 1;
    next_step.second += 1;
    next_step.first += 1;
  }

  return num;
}

int queensAttack(int n, int k, int r_q, int c_q,
                 vector<vector<int>> obstacles) {

  r_q -= 1;
  c_q -= 1;
  int ans = 0;

  if (k > 0) {

    for (int i = 0; i < k; i++) {

      pair<int, int> tmp = init(obstacles[i][0] - 1, obstacles[i][1] - 1);
      s_obstacles.insert(tmp);
    }

  } else {

    pair<int, int> tmp;
    tmp.first = -1337;
    tmp.second = -1337;
    s_obstacles.insert(tmp);
  }

  ans += goUp(r_q, c_q, n);
  ans += goDown(r_q, c_q);
  ans += goLeft(r_q, c_q);
  ans += goRight(r_q, c_q, n);
  ans += diagonal1(r_q, c_q, n);
  ans += diagonal2(r_q, c_q, n);

  return ans;
}

// this part it's from Hackerrank for reading inputs 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
