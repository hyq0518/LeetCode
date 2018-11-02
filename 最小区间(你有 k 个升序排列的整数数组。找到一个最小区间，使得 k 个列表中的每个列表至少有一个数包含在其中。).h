/*
建立最小堆，将所有列表的最小值保存在heap中，同时将各列表的最小值删除
然后早heap中选出最小值，删除该值，同时将最小值对应列表的最小值加入列表中，删除列表中该值
反复进行第二步操作，直到有一列表为空
*/
//寻找一个列表的最小值和最大值
vector<int> findmaxmin(vector<int> heap)
{
	int min, max;
	int wz=0;
	min = 999999;
	max = -999999;
	vector<int> result;
	for (int i = 0; i < heap.size(); i++)
	{
		if (heap[i] < min)
		{
			min = heap[i];
			wz = i;
		}
		if (heap[i]> max)
		{
			max = heap[i];
		}
	}
	result.push_back(min);
	result.push_back(wz);
	result.push_back(max);
	return result; //result包含最小值，最小值所对应列表，最大值
}
vector<int> smallestRange(vector<vector<int>>& nums) {
	vector<int> heap;
	vector<int> min;
	vector<vector<int>> maxmin;
	vector<int> result(2);
	result = { -999999,999999 };
	//建立最小堆，将所有列表的最小值保存在heap中，同时将各列表的最小值删除
	for (int i = 0; i < nums.size(); i++)
	{
		heap.push_back(nums[i][0]);
		nums[i].erase(nums[i].begin());
	}
	while (true)
	{
		vector<int> result1;
		result1 = this->findmaxmin(heap);
		vector<int> temp;
		temp.push_back(result1[0]);
		temp.push_back(result1[2]);
		//将每一次迭代的最大最小值保存，调试作用，可以不需要保存，最后一个最大最小值为最终区间
		maxmin.push_back(temp);
		if (nums[result1[1]].empty())
		{
			break;
		}
		else
		{
			//将heap最小值替换成最小值对应列表的最小值（当前最小值的下一个值），然后删除列表的最小值
			heap[result1[1]] = nums[result1[1]][0];
			nums[result1[1]].erase(nums[result1[1]].begin());
		}
	}
	for (int i = 0; i < maxmin.size(); i++)
	{
		if (maxmin[i][1] - maxmin[i][0] < result[1] - result[0])
		{
			result[1]= maxmin[i][1];
			result[0] = maxmin[i][0];
		}
	}
	return result;
}
