#include <bits/stdc++.h>
using namespace std;
struct Applicant
{
    string name;
    int workingHours;
    int cost;
};
int maximizeWorkingHours(int budget, vector<Applicant> &applicants,
                         vector<string> &selectedNames, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        int hours = applicants[i - 1].workingHours;
        int cost = applicants[i - 1].cost;
        for (int j = 0; j <= budget; ++j)
        {
            if (j >= cost)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost] +
                                                 hours);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int remainingBudget = budget;
    for (int i = n; i > 0 && remainingBudget >= 0; --i)
    {
        if (dp[i][remainingBudget] != dp[i - 1][remainingBudget])
        {
            selectedNames.push_back(applicants[i - 1].name);
            remainingBudget -= applicants[i - 1].cost;
        }
    }
    return dp[n][budget];
}
int main()
{
    int budget;
    cin >> budget;
    int n;
    cin >> n;
    vector<Applicant> applicants(n);
    for (int i = 0; i < n; i++)

    {
        cin >> applicants[i].name;
        cin >> applicants[i].workingHours;
        cin >> applicants[i].cost;
    }
    vector<string> selectedApplicants;
    cout << "Maximum Working Hours: " << maximizeWorkingHours(budget, applicants, selectedApplicants, n) << endl;
    cout << "Selected Applicants: ";
    for (const auto &name : selectedApplicants)
    {
        cout << name << " ";
    }
    cout << endl;
    return 0;
}