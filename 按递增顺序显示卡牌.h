/*
找规律，反向规律
*/
vector<int> deckRevealedIncreasing(vector<int>& deck) {
	vector<int> res(deck.size());
	sort(deck.begin(), deck.end());
	queue<int> myque;
	myque.push(deck[deck.size() - 1]);
	myque.push(deck[deck.size() - 2]);
	for (int i = deck.size() - 3; i >=0 ; i--)
	{
		int temp = myque.front();
		myque.pop();
		myque.push(temp);
		myque.push(deck[i]);
	}
	for (int i = 0; i < deck.size(); i++)
	{
		res[deck.size() - 1 - i] = myque.front();
		myque.pop();
	}
	return res;
}