#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class FoodRatings
{
    vector<string> foods;
    vector<string> cuisines;
    vector<int> ratings;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        this->foods = foods;
        this->cuisines = cuisines;
        this->ratings = ratings;
    }

    void changeRating(string food, int newRating)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            if (foods[i] == food)
            {
                ratings[i] = newRating;
            }
        }
    }

    string highestRated(string cuisine)
    {
        string ans = "";
        int maxRating = 0;
        int n = cuisines.size();
        for (int i = 0; i < n; i++)
        {
            if (cuisines[i] == cuisine)
            {
                if (ratings[i] > maxRating)
                {
                    maxRating = ratings[i];
                    ans = foods[i];
                }
                else if (ratings[i] == maxRating)
                {
                    if (foods[i] < ans)
                    {
                        ans = foods[i];
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};
    FoodRatings fr(foods, cuisines, ratings);
    fr.changeRating("ramen", 16);
    for (auto i : ratings)
    {
        cout << i << " ";
    }
    return 0;
}