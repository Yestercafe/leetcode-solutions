class Solution {
	public:
		int maxProduct(vector<string>& words) {
			vector<int> ps;
			for (string& word : words) {
				int p = 0;
				for (int i = 0; i < word.length(); i++) {
					p |= 1 << (word[i] - 'a');
				}
				ps.push_back(p);
			}

			int maxx = 0;
			for (int i = 0; i < words.size(); i++) {
				for (int j = i + 1; j < words.size(); j++) {
					if ((ps[i] & ps[j]) == 0) {
						int prod = words[i].length() * words[j].length();
						if (prod > maxx)
							maxx = prod;
					}
				}
			}

			return maxx;
		}
};
