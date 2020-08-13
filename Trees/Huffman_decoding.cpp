string decodeHuffmanData(struct MinHeapNode* root, string s)
{
	string ans = "";

	if (!root) return ans;

	int i = 0;

	int n = s.length();

	MinHeapNode* cur = NULL;

	while (i < n)
	{
		cur = root;

		while (cur->data == '$')
		{

			if (s[i] == '0') cur = cur->left;
			else cur = cur->right;
			i++;
		}
		ans += cur->data;
	}
	return ans;
}