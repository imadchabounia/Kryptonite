#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the arraySplitting function below.
 */

vector<int> arr_g;

int finding_split_point(vector<int> arr, int s, int e){


    int leftSum = 0;

      //if(s == e-1) return -1;

    for (int i = s ; i < e ; i++)
        leftSum += arr[i];


    int rightSum = 0;
    for (int i=e-1; i >= 0; i--)
    {
        rightSum += arr[i];

        leftSum -= arr[i] ;

        if (rightSum == leftSum)
            return i ;
    }


    return -1;
}

int solve_helper(int i, int j){

  int split_point = finding_split_point(arr_g, i, j);
    
  if(i == j-1) return 0;

  if(split_point == -1) return 0;

  return 1 + max(solve_helper(i, split_point), solve_helper(split_point, j));

}

int arraySplitting(vector<int> arr) {

  arr_g = arr;
  int n = arr_g.size();

  return solve_helper(0, n);

}

int main()

{
    // the main function it's from Hackerrank for reading inputs and print the output
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        int result = arraySplitting(arr);

        fout << result << "\n";
    }

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
