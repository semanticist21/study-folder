  vector<vector<char>> chars;
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        vector<char> part_char(size);

        for (int j = 0; i < size; j++)
        {
            int remnant = (i + j) % size;
            part_char[remnant] = s[remnant];
        }

        chars.emplace_back(part_char);
    }