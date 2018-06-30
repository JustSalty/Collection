#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
vector<double> vols = {0, 7, 3.4, 1.10, 0.77};
float targ = 15;
int msize = 5;
//**/


///It is explicitly meant for the vols to be sorted in decreasing order
int main()
{

    /**
    vector<double> blocks = {0,0,0,0,0};
    vector<int> nums={0,0,0,0,0}, ans = {0,0,0,0,0};
    //**/

    //**
    cout << "\n Enter the target value, number of coins and their values: ";
    int n, msize;
    double targ, k;
    cin >> targ >> n;
    msize = n+1;
    vector<double> vols, blocks;
    vector<int> nums, ans;
    vols.push_back(-1);
    blocks.push_back(-1);
    nums.push_back(-1);
    ans.push_back(-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        vols.push_back(k);
        blocks.push_back(0);
        nums.push_back(0);
        ans.push_back(0);
    }
    //**/

    /**
    cout << endl;
    for (int i = 0; i < vols.size(); ++i)
    {
        cout << " " << vols[i];
    }
    //**/


    double min_diff = targ, curr_tail = targ;
    bool finish = false;
    int tmp = 1;
    while(!finish)
    {
        while (tmp < msize) {
            while (vols[tmp] <= curr_tail)
            {
                blocks[tmp] += vols[tmp];
                nums[tmp]++;
                curr_tail -= vols[tmp];
            }
            tmp++;
        }
        if (min_diff > curr_tail) {
            min_diff = curr_tail;
            for (int i = 1; i < msize; ++i)
            {
                ans[i] = nums[i];
            }
        }
        if (curr_tail == 0) break;
        tmp = msize - 1;
        nums[tmp] = 0;
        curr_tail += blocks[tmp];
        blocks[tmp] = 0;
        while (nums[tmp] == 0) {tmp--;}
        if (tmp == 0) {finish = true;}
        else {
            nums[tmp]--;
            blocks[tmp] -= vols[tmp];
            curr_tail += vols[tmp];
            tmp++;
        }
    }

    cout << "\n Minimal error is " << min_diff << " which is attainable on ";
    for (int i = 1; i < msize; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/**
    stack seq;
    int max = 3, tmp = max, tmp2 = 0;
    bool finish = false;
    while (!finish)
    {
        while (curr_sum + vols[tmp] <= targ)
        {
            curr_sum += vols[tmp];
            seq.push(tmp);
        }
        if (min_diff > targ - curr_sum) min_diff = targ - curr_sum;
        if (min_diff == 0) break;
        if (tmp > 0 && targ - curr_sum > vols[tmp-1]) {tmp--;}
        else
        {
            tmp = seq.pop();
            curr_sum -= vols[tmp];
            while (tmp2 == seq.pop())
            {

            }
        }
    }
    //**/
