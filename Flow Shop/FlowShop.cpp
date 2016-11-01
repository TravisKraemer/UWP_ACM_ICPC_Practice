#include <iostream>

using namespace std;

int main()
{
    int numSwathers,numStages;
    int testCase = 1;
    cin >> numSwathers >> numStages;
    while(numSwathers != 0 || numStages != 0)
    {
        //Dynamically allocated array, using syntax for [x][y] is more difficult
        //Manually do offsets
        int* timeArray = new int[numSwathers*numStages];
        //Read in all the data
        for(int i = 0; i < numSwathers; i++)
            for(int j = 0; j < numStages; j++)
                cin >> timeArray[i*numStages + j];
        //Process the first row
        for(int i = 1; i < numStages; i++)
            timeArray[0*numStages + i] += timeArray[0*numStages + i-1];
        //Process all other rows
        for(int i = 1; i < numSwathers; i++)
        {
            //Calculate when first stage finishes
            timeArray[i*numStages + 0] += timeArray[(i-1)*numStages + 0];
            //Calculate the rest of the stages
            for(int j = 1; j < numStages; j++)
            {
                int prevSwather = timeArray[(i-1)*numStages + j];
                int prevStage = timeArray[i*numStages + j-1];
                //Add max of time for previous swather to complete stage
                // and time for previous stage of same swather to complete
                if(prevSwather > prevStage)
                    timeArray[i*numStages + j] += prevSwather;
                else
                    timeArray[i*numStages + j] += prevStage;
            }
        }
        //Do the Output
        cout << "Case " << testCase++ << ":";
        for(int i = 0; i < numSwathers; i++)
        {
            //Print time it finished (Print space before so the last one doesn't have space after it
            cout << " " << timeArray[i*numStages + numStages - 1];
        }
        cout << endl;
        //Free memory, else memory leak
        delete[] timeArray;
        cin >> numSwathers >> numStages;
    }
    return 0;
}
