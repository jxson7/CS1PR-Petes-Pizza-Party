#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pallet
{
    public:
        Pallet();
        Pallet(vector<string> Items) : items(Items) {}
        int GetWeight() { return items.size(); }

    protected:
        vector<string> items;
};

int main()
{
    vector<Pallet> pallets = {
        Pallet({ "Scorpions" }),
        Pallet({ "Dogs", "Bones", "Biscuits", "Cats", "Food", "Toys" }),
        Pallet({ "Computers", "Scientists", "Routers", "Monitors" }) };

    sort(pallets.begin(), pallets.end(), [](auto& a, auto& b) {
      return a.GetWeight() < b.GetWeight();
    });
}
