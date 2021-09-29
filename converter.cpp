#include<bits/stdc++.h>
using namespace std;
int main() {
    string path;
    cin>>path;
    ifstream infile(path);
    string line;
    vector<vector<int> > baskets;
    vector<int> items;
    baskets.push_back(vector<int>());
    unordered_map<int, int> item_to_id;
    int basket_id = 1;
    while(getline(infile, line)) {
        cout << line << endl;
        line = line + " ";
        int current_item = 0;
        for(int i = 0; i < line.size(); i++) {
            if(line[i] == ' ') {
                if(current_item) {
                    if(item_to_id[current_item] == 0) {
                        item_to_id[current_item] = item_to_id.size();
                        baskets.push_back(vector<int>());
                        items.push_back(current_item);
                    }
                    baskets[item_to_id[current_item]].push_back(basket_id);
                }
                current_item = 0;
            }
            else {
                current_item = current_item * 10 + (line[i] - '0');
            }
        }
        basket_id += 1;
    }
    sort(items.begin(), items.end());
    infile.close();
    ofstream outfile(path+".out");
    for(auto item: items) {
        cout << "item: " << item << endl;
        outfile<<item<<"\t";
        for(int i = 0; i < baskets[item_to_id[item]].size(); i++) {
            if(i) {
                 outfile<<" ";
            }
            outfile<<baskets[item_to_id[item]][i];
        }
        outfile<<"\n";
    }
    outfile.close();
}