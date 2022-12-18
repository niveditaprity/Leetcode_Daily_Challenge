class Solution
{
    public:
       	//     To calculate the crossProduct 
       	// Cross product of two vectors AB and AC
       	// returns positive for counter clockwise
       	// turn and negative for clockwise turn
        int getRotationAngle(vector<int> A, vector<int> B, vector<int> C)
        {
           	// (x2-x1)(y3-y1) - (y2-y1)(x3-x1) -> 3D Cross-product of AB and AC vectors
            return ((B[0] - A[0]) *(C[1] - A[1])) - ((B[1] - A[1]) *(C[0] - A[0]));
        }

    vector<vector < int>> outerTrees(vector<vector < int>> &trees)
    {
       	//          If less then or equal to 3 return Trees. They all need to included .
        if (trees.size() <= 3) return trees;

      	//      sort them according to increasing order of x cordinates.   
        sort(trees.begin(), trees.end());

       	// Upper HULL construction
        vector<vector < int>> UpperHullTrees;

      	//       Push first 2 points in UpperHullTrees.       
        UpperHullTrees.push_back(trees[0]);
        UpperHullTrees.push_back(trees[1]);

      	//         Travese throw all the points of sorted Trees.
        for (int i = 2; i < trees.size(); i++)
        {
            int Us = UpperHullTrees.size();

           	//             Cross Product > 0  bigger counterclockwise angle . So,we need to remove B and insert C.
            while (UpperHullTrees.size() >= 2 && getRotationAngle(UpperHullTrees[Us - 2], UpperHullTrees[Us - 1], trees[i]) > 0)
            {
                UpperHullTrees.pop_back();
                Us--;
            }
            UpperHullTrees.push_back(trees[i]);
        }

      	// Lower HULL construction
        vector<vector < int>> LowerHullTrees;

        LowerHullTrees.push_back(trees[trees.size() - 1]);
        LowerHullTrees.push_back(trees[trees.size() - 2]);

        for (int i = trees.size() - 3; i >= 0; --i)
        {
            int Ls = LowerHullTrees.size();
            while (LowerHullTrees.size() >= 2 && getRotationAngle(LowerHullTrees[Ls - 2], LowerHullTrees[Ls - 1], trees[i]) > 0)
            {
                LowerHullTrees.pop_back();
                Ls--;
            }
            LowerHullTrees.push_back(trees[i]);
        }

     	//         Add the top hull to down hull
        UpperHullTrees.insert(UpperHullTrees.end(), LowerHullTrees.begin(), LowerHullTrees.end());

       	//          Remove the duplicates present in the lTrees.
        sort(UpperHullTrees.begin(), UpperHullTrees.end());
        UpperHullTrees.erase(unique(UpperHullTrees.begin(), UpperHullTrees.end()), UpperHullTrees.end());

        return UpperHullTrees;
       
        
    }
};
