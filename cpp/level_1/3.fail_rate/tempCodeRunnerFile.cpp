    for (int i = players.size() - 2; i > 0; --i)
        players[i] += players[i + 1];

    for (int i = 0; i < players.size() - 1; ++i)
    {
        if (players[i + 1] == 0)
        {
            players[i] = 0;
            continue;
        }

        players[i] = players[i] / players[i + 1];
    }

    vector<pair<int, int>> p_s_match(N, make_pair(0, 0));
    players.pop_back();

    for (int i = 0; i < players.size() - 1; ++i)
        p_s_match[i] = make_pair(i, players[i]);

    auto sorter = [](pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    };
    sort(p_s_match.begin(), p_s_match.end(), sorter);

    vector<int> answer(N, 0);
    for (int i = 0; i < p_s_match.size(); ++i)
        answer[i] = p_s_match[i].first + 1;

    return answer;