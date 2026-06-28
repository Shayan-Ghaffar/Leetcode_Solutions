class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
	sort(occupiedIntervals.begin(), occupiedIntervals.end(), [](vector<int>& a, vector<int>& b) {return
		a[0] < b[0];
		});
	vector<vector<int>> check;
	check.push_back(occupiedIntervals[0]);
	for (int i = 1; i < occupiedIntervals.size(); i++)
	{
		vector<int>& lastMerged = check.back();
		if (lastMerged[1] >= occupiedIntervals[i][0] - 1)
		{
			lastMerged[1] = max(lastMerged[1], occupiedIntervals[i][1]);
            if(lastMerged[0] > occupiedIntervals[i][0])
                lastMerged[0] = occupiedIntervals[i][0];
		}
		else
		{
			check.push_back(occupiedIntervals[i]);
		}
	}
	vector<vector<int>> result;
	for (const auto& interval : check) {
		int start = interval[0];
		int end = interval[1];
		if (end < freeStart || start > freeEnd) {
			result.push_back(interval);
		}
		else {
			if (start < freeStart) {
				result.push_back({ start, freeStart - 1 });
			}
			if (end > freeEnd) {
				result.push_back({ freeEnd + 1, end });
			}
		}
		
	}
    return result;
}
};